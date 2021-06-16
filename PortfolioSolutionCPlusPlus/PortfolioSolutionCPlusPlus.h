
// PortfolioSolutionCPlusPlus.h : main header file for the PortfolioSolutionCPlusPlus application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPortfolioSolutionCPlusPlusApp:
// See PortfolioSolutionCPlusPlus.cpp for the implementation of this class
//

class CPortfolioSolutionCPlusPlusApp : public CWinAppEx
{
public:
	CPortfolioSolutionCPlusPlusApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	void UpdateViews();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	//	functions
	BOOL InitEvents();

	// attributes
	void* m_pModel = nullptr;
	void* m_pController = nullptr;
	void* m_pViewModel = nullptr;
};
extern CPortfolioSolutionCPlusPlusApp theApp;
