#include "stdafx.h"
#include <list>
#include <string>
#include <vector>
#include "MainFrm.h"
#include "RobotView.h"
#include "Resource.h"
#include "PortfolioSolutionCPlusPlus.h"

#include "..\CommonDataLibrary\Plan.h"
#include "..\CommonDataLibrary\Robot.h"
#include "..\CommonDataLibrary\Detector.h"
#include "Model.h"

class CRobotViewMenuButton : public CMFCToolBarMenuButton
{
	friend class CRobotView;

	DECLARE_SERIAL(CRobotViewMenuButton)

public:
	CRobotViewMenuButton(HMENU hMenu = nullptr) noexcept : CMFCToolBarMenuButton((UINT)-1, hMenu, -1)
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

IMPLEMENT_SERIAL(CRobotViewMenuButton, CMFCToolBarMenuButton, 1)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRobotView::CRobotView()
{
	m_nCurrSort = ID_SORTING_GROUPBYTYPE;
}

CRobotView::~CRobotView()
{
}

BEGIN_MESSAGE_MAP(CRobotView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ROBOT_ADD_MEMBER_FUNCTION, OnRobotAddMemberFunction)
	ON_COMMAND(ID_ROBOT_ADD_MEMBER_VARIABLE, OnRobotAddMemberVariable)
	ON_COMMAND(ID_ROBOT_DEFINITION, OnRobotDefinition)
	ON_COMMAND(ID_ROBOT_PROPERTIES, OnRobotProperties)
	ON_COMMAND(ID_NEW_FOLDER, OnNewFolder)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_COMMAND_RANGE(ID_SORTING_GROUPBYTYPE, ID_SORTING_SORTBYACCESS, OnSort)
	ON_UPDATE_COMMAND_UI_RANGE(ID_SORTING_GROUPBYTYPE, ID_SORTING_SORTBYACCESS, OnUpdateSort)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassView message handlers

int CRobotView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Create views:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | LVS_REPORT;

	if (!m_wndRobotView.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS, rectDummy, this, 1234))
	{
		TRACE0("Failed to create Robot View\n");
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

	m_wndToolBar.ReplaceButton(ID_SORT_MENU, CRobotViewMenuButton(menuSort.GetSubMenu(0)->GetSafeHmenu()));

	CRobotViewMenuButton* pButton = DYNAMIC_DOWNCAST(CRobotViewMenuButton, m_wndToolBar.GetButton(0));

	if (pButton != nullptr)
	{
		pButton->m_bText = FALSE;
		pButton->m_bImage = TRUE;
		pButton->SetImage(GetCmdMgr()->GetCmdImage(m_nCurrSort));
		pButton->SetMessageWnd(this);
	}

	// Fill in some static list view data (dummy code, nothing magic here)
	InitializeRobotView();

	return 0;
}

void CRobotView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CRobotView::InitializeRobotView()
{
	m_wndRobotView.InsertColumn(
		0,              // Rank/order of item 
		L"Name",          // Caption for this header 
		LVCFMT_LEFT,    // Relative position of items under header 
		100);           // Width of items under header

	m_wndRobotView.InsertColumn(2, L"Date", LVCFMT_LEFT, 100);
}

void CRobotView::FillRobotView(void* pmodel)
{

	Model* pModel = ((Model*)pmodel);
	m_wndRobotView.DeleteAllItems();

	int pcnt = static_cast<Model*>(pModel)->get_RobotCount();
	for (int i = 0; i < pcnt; i++)
	{
		DataLibrary::CRobot robot = static_cast<Model*>(pModel)->get_Robot(i);

		// TODO - insert plan into UI
		std::wstring name = robot.get_name();

		//	get the timestamp of the plan for column2
		time_t time = robot.get_timestamp();

		//	convert the time structure into a local time stamps
		std::tm * ptm = std::localtime(&time);

		//	allocate a tempory buffer for the time string
		wchar_t buffer[32];

		// Format: Mo, 15.06.2009 20:20:00
		std::wcsftime(buffer, 32, L"%a, %d.%m.%Y %H:%M:%S", ptm);

		//	insert a new item and set the name at the the first column
		int nItem = m_wndRobotView.InsertItem(0, name.c_str());

		//	add the timestamp to the new item in the list
		m_wndRobotView.SetItemText(nItem, 1, buffer);
	}
}

void CRobotView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CTreeCtrl* pWndTree = (CTreeCtrl*)&m_wndRobotView;
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

void CRobotView::AdjustLayout()
{
	if (GetSafeHwnd() == nullptr)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(nullptr, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndRobotView.SetWindowPos(nullptr, rectClient.left + 1, rectClient.top + cyTlb + 1, rectClient.Width() - 2, rectClient.Height() - cyTlb - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}

BOOL CRobotView::PreTranslateMessage(MSG* pMsg)
{
	return CDockablePane::PreTranslateMessage(pMsg);
}

void CRobotView::OnSort(UINT id)
{
	if (m_nCurrSort == id)
	{
		return;
	}

	m_nCurrSort = id;

	CRobotViewMenuButton* pButton = DYNAMIC_DOWNCAST(CRobotViewMenuButton, m_wndToolBar.GetButton(0));

	if (pButton != nullptr)
	{
		pButton->SetImage(GetCmdMgr()->GetCmdImage(id));
		m_wndToolBar.Invalidate();
		m_wndToolBar.UpdateWindow();
	}
}

void CRobotView::OnUpdateSort(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nCurrSort);
}

void CRobotView::OnRobotAddMemberFunction()
{
	AfxMessageBox(_T("Add member function..."));
}

void CRobotView::OnRobotAddMemberVariable()
{
	// TODO: Add your command handler code here
}

void CRobotView::OnRobotDefinition()
{
	// TODO: Add your command handler code here
}

void CRobotView::OnRobotProperties()
{
	// TODO: Add your command handler code here
}

void CRobotView::OnNewFolder()
{
	AfxMessageBox(_T("New Folder..."));
}

void CRobotView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rectTree;
	m_wndRobotView.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}

void CRobotView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	m_wndRobotView.SetFocus();
}

void CRobotView::OnChangeVisualStyle()
{
	m_RobotViewImages.DeleteImageList();

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

	m_RobotViewImages.Create(16, bmpObj.bmHeight, nFlags, 0, 0);
	m_RobotViewImages.Add(&bmp, RGB(255, 0, 0));

	m_wndRobotView.SetImageList(&m_RobotViewImages, TVSIL_NORMAL);

	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_SORT_24 : IDR_SORT, 0, 0, TRUE /* Locked */);
}

