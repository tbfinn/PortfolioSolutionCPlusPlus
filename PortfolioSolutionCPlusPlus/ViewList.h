#pragma once

/////////////////////////////////////////////////////////////////////////////
// CViewTree window

class CViewList : public CListCtrl
{
	// Construction
public:
	CViewList() noexcept;

	// Overrides
protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	// Implementation
public:
	virtual ~CViewList();

protected:
	DECLARE_MESSAGE_MAP()
};

