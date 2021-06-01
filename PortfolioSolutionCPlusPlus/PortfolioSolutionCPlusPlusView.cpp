
// PortfolioSolutionCPlusPlusView.cpp : implementation of the CPortfolioSolutionCPlusPlusView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PortfolioSolutionCPlusPlus.h"
#endif

#include "PortfolioSolutionCPlusPlusDoc.h"
#include "PortfolioSolutionCPlusPlusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPortfolioSolutionCPlusPlusView

IMPLEMENT_DYNCREATE(CPortfolioSolutionCPlusPlusView, CView)

BEGIN_MESSAGE_MAP(CPortfolioSolutionCPlusPlusView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPortfolioSolutionCPlusPlusView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPortfolioSolutionCPlusPlusView construction/destruction

CPortfolioSolutionCPlusPlusView::CPortfolioSolutionCPlusPlusView() noexcept
{
	// TODO: add construction code here

}

CPortfolioSolutionCPlusPlusView::~CPortfolioSolutionCPlusPlusView()
{
}

BOOL CPortfolioSolutionCPlusPlusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPortfolioSolutionCPlusPlusView drawing

void CPortfolioSolutionCPlusPlusView::OnDraw(CDC* /*pDC*/)
{
	CPortfolioSolutionCPlusPlusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPortfolioSolutionCPlusPlusView printing


void CPortfolioSolutionCPlusPlusView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPortfolioSolutionCPlusPlusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPortfolioSolutionCPlusPlusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPortfolioSolutionCPlusPlusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPortfolioSolutionCPlusPlusView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPortfolioSolutionCPlusPlusView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPortfolioSolutionCPlusPlusView diagnostics

#ifdef _DEBUG
void CPortfolioSolutionCPlusPlusView::AssertValid() const
{
	CView::AssertValid();
}

void CPortfolioSolutionCPlusPlusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPortfolioSolutionCPlusPlusDoc* CPortfolioSolutionCPlusPlusView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPortfolioSolutionCPlusPlusDoc)));
	return (CPortfolioSolutionCPlusPlusDoc*)m_pDocument;
}
#endif //_DEBUG


// CPortfolioSolutionCPlusPlusView message handlers
