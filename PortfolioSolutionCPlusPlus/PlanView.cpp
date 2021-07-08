#include "stdafx.h"
#include <list>
#include <string>
#include <vector>

#include "MainFrm.h"
#include "PlanView.h"
#include "Resource.h"
#include "PortfolioSolutionCPlusPlus.h"

#include "..\CommonDataLibrary\Plan.h"
#include "..\CommonDataLibrary\Robot.h"
#include "..\CommonDataLibrary\Detector.h"
#include "Model.h"

class CPlanViewMenuButton : public CMFCToolBarMenuButton
{
	friend class CPlanView;

	DECLARE_SERIAL(CPlanViewMenuButton)

public:
	CPlanViewMenuButton(HMENU hMenu = nullptr) noexcept : CMFCToolBarMenuButton((UINT)-1, hMenu, -1)
	{
	}

	virtual void OnDraw(CDC* pDC, const CRect& rect, CMFCToolBarImages* pImages, BOOL bHorz = TRUE,
		BOOL bCustomizeMode = FALSE, BOOL bHighlight = FALSE, BOOL bDrawBorder = TRUE, BOOL bGrayDisabledButtons = TRUE)
	{
		pImages = CMFCToolBar::GetImages();

		CAfxDrawState ds;
		pImages->PrepareDrawImage(ds);

		CMFCToolBarMenuButton::OnDraw(pDC, rect, pImages, bHorz, bCustomizeMode, bHighlight, bDrawBorder, bGrayDisabledButtons);

		pImages->EndDrawImage(ds);
	}
};

IMPLEMENT_SERIAL(CPlanViewMenuButton, CMFCToolBarMenuButton, 1)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CPlanView::CPlanView()
{
	m_nCurrSort = ID_SORTING_GROUPBYTYPE;
}

CPlanView::~CPlanView()
{
}

BEGIN_MESSAGE_MAP(CPlanView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_PLAN_ADD_MEMBER_FUNCTION, OnPlanAddMemberFunction)
	ON_COMMAND(ID_PLAN_ADD_MEMBER_VARIABLE, OnPlanAddMemberVariable)
	ON_COMMAND(ID_PLAN_DEFINITION, OnPlanDefinition)
	ON_COMMAND(ID_PLAN_PROPERTIES, OnPlanProperties)
	ON_COMMAND(ID_NEW_FOLDER, OnNewFolder)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_COMMAND_RANGE(ID_SORTING_GROUPBYTYPE, ID_SORTING_SORTBYACCESS, OnSort)
	ON_UPDATE_COMMAND_UI_RANGE(ID_SORTING_GROUPBYTYPE, ID_SORTING_SORTBYACCESS, OnUpdateSort)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlanView message handlers

int CPlanView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Create views:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | LVS_REPORT;


	if (!m_wndPlanView.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, rectDummy, this, 1234))
	{
		TRACE0("Failed to create Plan View\n");
		return -1;      // fail to create
	}

	// Load images:
	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_SORT);
	m_wndToolBar.LoadToolBar(IDR_SORT, 0, 0, TRUE /* Is locked */);

	OnChangeVisualStyle();

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_wndToolBar.SetOwner(this);

	// All commands will be routed via this control , not via the parent frame:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	CMenu menuSort;
	menuSort.LoadMenu(IDR_POPUP_SORT);

	m_wndToolBar.ReplaceButton(ID_SORT_MENU, CPlanViewMenuButton(menuSort.GetSubMenu(0)->GetSafeHmenu()));

	CPlanViewMenuButton* pButton = DYNAMIC_DOWNCAST(CPlanViewMenuButton, m_wndToolBar.GetButton(0));

	if (pButton != nullptr)
	{
		pButton->m_bText = FALSE;
		pButton->m_bImage = TRUE;
		pButton->SetImage(GetCmdMgr()->GetCmdImage(m_nCurrSort));
		pButton->SetMessageWnd(this);
	}

	// Fill in some static list view data (dummy code, nothing magic here)
	InitializePlanView();

	return 0;
}

void CPlanView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CPlanView::InitializePlanView()
{
	m_wndPlanView.InsertColumn(
		0,              // Rank/order of item 
		L"Name",          // Caption for this header 
		LVCFMT_LEFT,    // Relative position of items under header 
		100);           // Width of items under header

	m_wndPlanView.InsertColumn(2, L"Date", LVCFMT_LEFT, 100);
}

void CPlanView::FillPlanView(void* pModel)
{
	Model* model = ((Model*)pModel);

	int pcnt = static_cast<Model*>(pModel)->get_PlanCount();
	m_wndPlanView.DeleteAllItems();

	for (int i = 0; i < pcnt; i++)
	{
		DataLibrary::CPlan plan = static_cast<Model*>(pModel)->get_Plan(i);

		// TODO - insert plan into UI
		std::wstring name = plan.get_name();

		//	get the timestamp of the plan for column2
		time_t time = plan.get_timestamp();

		//	convert the time structure into a local time stamps
		std::tm * ptm = std::localtime(&time);

		//	allocate a tempory buffer for the time string
		wchar_t buffer[32];

		// Format: Mo, 15.06.2009 20:20:00
		std::wcsftime(buffer, 32, L"%a, %d.%m.%Y %H:%M:%S", ptm);

		//	insert a new item and set the name at the the first column
		int nItem = m_wndPlanView.InsertItem(0, name.c_str());

		//	add the timestamp to the new item in the list
		m_wndPlanView.SetItemText(nItem, 1, buffer);
	}
}

void CPlanView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CTreeCtrl* pWndTree = (CTreeCtrl*)&m_wndPlanView;
	ASSERT_VALID(pWndTree);

	if (pWnd != pWndTree)
	{
		CDockablePane::OnContextMenu(pWnd, point);
		return;
	}

	if (point != CPoint(-1, -1))
	{
		// Select clicked item:
		CPoint ptTree = point;
		pWndTree->ScreenToClient(&ptTree);

		UINT flags = 0;
		HTREEITEM hTreeItem = pWndTree->HitTest(ptTree, &flags);
		if (hTreeItem != nullptr)
		{
			pWndTree->SelectItem(hTreeItem);
		}
	}

	pWndTree->SetFocus();
	CMenu menu;
	menu.LoadMenu(IDR_POPUP_SORT);

	CMenu* pSumMenu = menu.GetSubMenu(0);

	if (AfxGetMainWnd()->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx)))
	{
		CMFCPopupMenu* pPopupMenu = new CMFCPopupMenu;

		if (!pPopupMenu->Create(this, point.x, point.y, (HMENU)pSumMenu->m_hMenu, FALSE, TRUE))
			return;

		((CMDIFrameWndEx*)AfxGetMainWnd())->OnShowPopupMenu(pPopupMenu);
		UpdateDialogControls(this, FALSE);
	}
}

void CPlanView::AdjustLayout()
{
	if (GetSafeHwnd() == nullptr)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(nullptr, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndPlanView.SetWindowPos(nullptr, rectClient.left + 1, rectClient.top + cyTlb + 1, rectClient.Width() - 2, rectClient.Height() - cyTlb - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}

BOOL CPlanView::PreTranslateMessage(MSG* pMsg)
{
	return CDockablePane::PreTranslateMessage(pMsg);
}

void CPlanView::OnSort(UINT id)
{
	if (m_nCurrSort == id)
	{
		return;
	}

	m_nCurrSort = id;

	CPlanViewMenuButton* pButton = DYNAMIC_DOWNCAST(CPlanViewMenuButton, m_wndToolBar.GetButton(0));

	if (pButton != nullptr)
	{
		pButton->SetImage(GetCmdMgr()->GetCmdImage(id));
		m_wndToolBar.Invalidate();
		m_wndToolBar.UpdateWindow();
	}
}

void CPlanView::OnUpdateSort(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nCurrSort);
}

void CPlanView::OnPlanAddMemberFunction()
{
	AfxMessageBox(_T("Add member function..."));
}

void CPlanView::OnPlanAddMemberVariable()
{
	// TODO: Add your command handler code here
}

void CPlanView::OnPlanDefinition()
{
	// TODO: Add your command handler code here
}

void CPlanView::OnPlanProperties()
{
	// TODO: Add your command handler code here
}

void CPlanView::OnNewFolder()
{
	AfxMessageBox(_T("New Folder..."));
}

void CPlanView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rectTree;
	m_wndPlanView.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}

void CPlanView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	m_wndPlanView.SetFocus();
}

void CPlanView::OnChangeVisualStyle()
{
	m_PlanViewImages.DeleteImageList();

	UINT uiBmpId = theApp.m_bHiColorIcons ? IDB_CLASS_VIEW_24 : IDB_CLASS_VIEW;


	CBitmap bmp;
	if (!bmp.LoadBitmap(uiBmpId))
	{
		TRACE(_T("Can't load bitmap: %x\n"), uiBmpId);
		ASSERT(FALSE);
		return;
	}

	BITMAP bmpObj;
	bmp.GetBitmap(&bmpObj);

	UINT nFlags = ILC_MASK;

	nFlags |= (theApp.m_bHiColorIcons) ? ILC_COLOR24 : ILC_COLOR4;

	m_PlanViewImages.Create(16, bmpObj.bmHeight, nFlags, 0, 0);
	m_PlanViewImages.Add(&bmp, RGB(255, 0, 0));

	m_wndPlanView.SetImageList(&m_PlanViewImages, TVSIL_NORMAL);

	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_SORT_24 : IDR_SORT, 0, 0, TRUE /* Locked */);
}
