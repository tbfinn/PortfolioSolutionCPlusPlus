#pragma once

#include <list>
#include <string>
#include "ViewList.h"

class CRobotToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*)GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CRobotView : public CDockablePane
{
public:

	// constructors

	CRobotView();
	~CRobotView();

	// Overrides
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	// methods
	std::list<std::wstring> l;

	void FillRobotView(void*);
	void AdjustLayout();
	void OnChangeVisualStyle();
protected:
	void InitializeRobotView();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnRobotAddMemberFunction();
	afx_msg void OnRobotAddMemberVariable();
	afx_msg void OnRobotDefinition();
	afx_msg void OnRobotProperties();
	afx_msg void OnNewFolder();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnChangeActiveTab(WPARAM, LPARAM);
	afx_msg void OnSort(UINT id);
	afx_msg void OnUpdateSort(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()

private:

	// attributes
	CRobotToolBar m_wndToolBar;
	CViewList m_wndRobotView;
	CImageList m_RobotViewImages;
	UINT m_nCurrSort;
};

