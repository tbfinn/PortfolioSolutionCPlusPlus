#pragma once

#include "ViewList.h"

class CDetectorToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CDetectorView : public CDockablePane
{
public:
	CDetectorView();
	~CDetectorView();

	void AdjustLayout();
	void OnChangeVisualStyle();

protected:
	CDetectorToolBar m_wndToolBar;
	CViewList m_wndDetectorView;
	CImageList m_DetectorViewImages;
	UINT m_nCurrSort;

	void FillDetectorView();

	// Overrides
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnDetectorAddMemberFunction();
	afx_msg void OnDetectorAddMemberVariable();
	afx_msg void OnDetectorDefinition();
	afx_msg void OnDetectorProperties();
	afx_msg void OnNewFolder();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnChangeActiveTab(WPARAM, LPARAM);
	afx_msg void OnSort(UINT id);
	afx_msg void OnUpdateSort(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};


