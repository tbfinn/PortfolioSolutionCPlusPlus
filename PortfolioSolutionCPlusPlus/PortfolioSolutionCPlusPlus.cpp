
// PortfolioSolutionCPlusPlus.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "PortfolioSolutionCPlusPlus.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "PortfolioSolutionCPlusPlusDoc.h"
#include "PortfolioSolutionCPlusPlusView.h"
#include "Controller.h"
#include "Model.h"
#include "ViewModel.h"

#include "IPlanManager.h"
#include "IDetectorManager.h"
#include "IRobotManager.h"
#include "IRunManager.h"

#include "IDBManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPortfolioSolutionCPlusPlusApp

BEGIN_MESSAGE_MAP(CPortfolioSolutionCPlusPlusApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CPortfolioSolutionCPlusPlusApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_TEST_LOADPLANS, &CPortfolioSolutionCPlusPlusApp::OnTestLoadplans)
	ON_COMMAND(ID_TEST_LOADROBOTS, &CPortfolioSolutionCPlusPlusApp::OnTestLoadrobots)
	ON_COMMAND(ID_TEST_LOADDETECTORS, &CPortfolioSolutionCPlusPlusApp::OnTestLoaddetectors)
END_MESSAGE_MAP()


// CPortfolioSolutionCPlusPlusApp construction

CPortfolioSolutionCPlusPlusApp::CPortfolioSolutionCPlusPlusApp() noexcept
{
	m_bHiColorIcons = TRUE;

	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("PortfolioSolutionCPlusPlus.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CPortfolioSolutionCPlusPlusApp object

CPortfolioSolutionCPlusPlusApp theApp;

sz::event_handler<unsigned int> IsModelDirtyEventHandler([](unsigned int counter)
{
	theApp.UpdateViews();
});


void CPortfolioSolutionCPlusPlusApp::UpdateViews()
{
	((CMainFrame*)m_pMainWnd)->UpdateNavigationViews(m_pModel);
}

// CPortfolioSolutionCPlusPlusApp initialization

BOOL CPortfolioSolutionCPlusPlusApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_PortfolioSolutionCPlusPlusTYPE,
		RUNTIME_CLASS(CPortfolioSolutionCPlusPlusDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPortfolioSolutionCPlusPlusView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The main window has been initialized, so show and update it
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

 

	m_pPlanManager = GetPlanManagerInstance();
	m_pDBManager = GetDbManagerInstance();
	m_pRobotManager = GetRobotManagerInstance();
	m_pDetectorManager = GetDetectorManagerInstance();
	m_pRunManager = GetRunManagerInstance();

	m_pModel = new Model(m_pDBManager);
	m_pViewModel = new ViewModel();

	m_pController = new Controller(m_pModel, m_pPlanManager, m_pRobotManager, m_pDetectorManager, m_pRunManager, m_pDBManager);


	InitEvents();


	return TRUE;
}

int CPortfolioSolutionCPlusPlusApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CPortfolioSolutionCPlusPlusApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CPortfolioSolutionCPlusPlusApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CPortfolioSolutionCPlusPlusApp customization load/save methods

void CPortfolioSolutionCPlusPlusApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CPortfolioSolutionCPlusPlusApp::LoadCustomState()
{
}

void CPortfolioSolutionCPlusPlusApp::SaveCustomState()
{
}

// CPortfolioSolutionCPlusPlusApp message handlers
BOOL CPortfolioSolutionCPlusPlusApp::InitEvents()
{
	((Model*)m_pModel)->DataChange += IsModelDirtyEventHandler;
	return TRUE;
}


void CPortfolioSolutionCPlusPlusApp::OnTestLoadplans()
{
	// TODO: Add your command handler code here
	((Controller*)m_pController)->LoadPlanView();
}

void CPortfolioSolutionCPlusPlusApp::OnTestLoadrobots()
{
	// TODO: Add your command handler code here
	((Controller*)m_pController)->LoadRobotView();
}

void CPortfolioSolutionCPlusPlusApp::OnTestLoaddetectors()
{
	// TODO: Add your command handler code here
	((Controller*)m_pController)->LoadDetectorView();
}
