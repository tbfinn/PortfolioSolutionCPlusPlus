#pragma once

#include <list>
#include <string>
#include "ViewList.h"

class CPlanToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CPlanView : public CDockablePane
{
public:
	//	constuctors
	CPlanView();
	~CPlanView();

	// Overrides
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	// methods
	std::list<std::wstring> l;
	void FillPlanView(void*);
	void AdjustLayout();
	void OnChangeVisualStyle();
protected:
	void InitializePlanView();
	//std::list<std::wstring>
protected:
	//	event handlers
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnPlanAddMemberFunction();
	afx_msg void OnPlanAddMemberVariable();
	afx_msg void OnPlanDefinition();
	afx_msg void OnPlanProperties();
	afx_msg void OnNewFolder();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnChangeActiveTab(WPARAM, LPARAM);
	afx_msg void OnSort(UINT id);
	afx_msg void OnUpdateSort(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
private:
	//	attributes
	CPlanToolBar m_wndToolBar;
	CViewList m_wndPlanView;
	CImageList m_PlanViewImages;
	UINT m_nCurrSort;
};

