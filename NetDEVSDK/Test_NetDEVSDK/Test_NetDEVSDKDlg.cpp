
// Test_NetDEVSDKDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Test_NetDEVSDK.h"
#include "Test_NetDEVSDKDlg.h"
#include "afxdialogex.h"
#include "../NetDEVSDK/NetDEVSDK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef DEBUG
#pragma comment(lib, "../debug/NetDEVSDK.lib")
#else
#pragma comment(lib, "../release/NetDEVSDK.lib")
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTest_NetDEVSDKDlg �Ի���



CTest_NetDEVSDKDlg::CTest_NetDEVSDKDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTest_NetDEVSDKDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_NetDEVSDKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTest_NetDEVSDKDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_Init, &CTest_NetDEVSDKDlg::OnBnClickedButtonInit)
    ON_BN_CLICKED(IDC_BUTTON_Login, &CTest_NetDEVSDKDlg::OnBnClickedButtonLogin)
    ON_BN_CLICKED(IDC_BUTTON_RealPlay, &CTest_NetDEVSDKDlg::OnBnClickedButtonRealplay)
    ON_BN_CLICKED(IDC_BUTTON_StopRealPlay, &CTest_NetDEVSDKDlg::OnBnClickedButtonStoprealplay)
    ON_BN_CLICKED(IDC_BUTTON_Logout, &CTest_NetDEVSDKDlg::OnBnClickedButtonLogout)
    ON_BN_CLICKED(IDC_BUTTON_Cleanup, &CTest_NetDEVSDKDlg::OnBnClickedButtonCleanup)
    ON_BN_CLICKED(IDC_BUTTON_GetVersion, &CTest_NetDEVSDKDlg::OnBnClickedButtonGetversion)
END_MESSAGE_MAP()


// CTest_NetDEVSDKDlg ��Ϣ�������

BOOL CTest_NetDEVSDKDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
    m_pCameraHandle = NULL;
    m_pPlayHandle = NULL;

    ((CComboBox*)GetDlgItem(IDC_COMBO_ChannelID))->AddString("0");
    ((CComboBox*)GetDlgItem(IDC_COMBO_ChannelID))->AddString("1");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTest_NetDEVSDKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTest_NetDEVSDKDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTest_NetDEVSDKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTest_NetDEVSDKDlg::OnBnClickedButtonInit()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    BOOL bRet = NETDEV_Init();
    char szLog[MAX_PATH] = {0};
    sprintf_s(szLog, sizeof(szLog), "NETDEV_Init , return code = %d", bRet);
    MessageBox(szLog);
}


void CTest_NetDEVSDKDlg::OnBnClickedButtonLogin()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    char chLog[256] = { 0 };

    CString cstrIPAddress;
    GetDlgItem(IDC_IPADDRESS1)->GetWindowText(cstrIPAddress);
    char szIP[64] = {0};
    sprintf_s(szIP, sizeof(szIP), "%s", cstrIPAddress.GetBuffer());
    cstrIPAddress.ReleaseBuffer();

    CString cstrChanelNo;
    GetDlgItem(IDC_COMBO_ChannelID)->GetWindowText(cstrChanelNo);
    int iChannelID = atoi(cstrChanelNo.GetBuffer());
    cstrChanelNo.ReleaseBuffer();
    iChannelID = (iChannelID >= 0) ? iChannelID : 1;

    if (NULL ==  m_pCameraHandle)
    {
        NETDEV_DEVICE_INFO_S deviceInfo;
        deviceInfo.dwChannelNum = iChannelID;
        m_pCameraHandle = NETDEV_Login(szIP, 0, "admin", "admin", &deviceInfo);

        sprintf_s(chLog, sizeof(chLog), "NETDEV_Login, Camera ip address = %s, return handle = %p.", szIP, m_pCameraHandle);
    }
    else
    {
        sprintf_s(chLog, sizeof(chLog), "NETDEV_Login, Camera ip address = %s, the  handle = %p is already in used, please clean it first.", szIP, m_pCameraHandle);
    }        
    //ShowMessage(chLog);
    MessageBox(chLog);
}


void CTest_NetDEVSDKDlg::OnBnClickedButtonRealplay()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    CString cstrChanelNo;
    GetDlgItem(IDC_COMBO_ChannelID)->GetWindowText(cstrChanelNo);
    int iChannelID = atoi(cstrChanelNo.GetBuffer());
    cstrChanelNo.ReleaseBuffer();
    iChannelID = (iChannelID >= 0) ? iChannelID : 1;

    char chLog[MAX_PATH] = {0};
    if (NULL == m_pPlayHandle)
    {
        NETDEV_PREVIEWINFO_S preViewInfo;
        preViewInfo.dwChannelID = 0;
        preViewInfo.dwStreamType = iChannelID;
        preViewInfo.hPlayWnd = GetDlgItem(IDC_STATIC_Video)->GetSafeHwnd();
        m_pPlayHandle = NETDEV_RealPlay(m_pCameraHandle, &preViewInfo, NULL, NULL);

        sprintf_s(chLog, sizeof(chLog), "NETDEV_RealPlay, window handle = %p, play handle = %p.", preViewInfo.hPlayWnd, m_pPlayHandle);
    }
    else
    {
        sprintf_s(chLog, sizeof(chLog), "NETDEV_RealPlay, the  play handle  = %p is already in used, please clean it first.", m_pPlayHandle);
    }
    MessageBox(chLog);
}


void CTest_NetDEVSDKDlg::OnBnClickedButtonStoprealplay()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    char chLog[MAX_PATH] = { 0 };
    if (NULL == m_pPlayHandle)
    {
        sprintf_s(chLog, sizeof(chLog), "NETDEV_StopRealPlay, the play handle = %p", m_pPlayHandle);
    }
    else
    {
        BOOL bRet = NETDEV_StopRealPlay(m_pPlayHandle);
        sprintf_s(chLog, sizeof(chLog), "NETDEV_StopRealPlay, the  play handle  = %p , return code = %d", m_pPlayHandle, bRet);
        if (bRet)
        {
            m_pPlayHandle = NULL;
        }
    }
    MessageBox(chLog);
}


void CTest_NetDEVSDKDlg::OnBnClickedButtonLogout()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    char chLog[MAX_PATH] = { 0 };
    if (NULL == m_pCameraHandle)
    {
        sprintf_s(chLog, sizeof(chLog), "NETDEV_Logout, the  handle = %p", m_pCameraHandle);
    }
    else
    {
        BOOL bRet = NETDEV_Logout(m_pCameraHandle);
        sprintf_s(chLog, sizeof(chLog), "NETDEV_Logout, the Camera handle  = %p , return code = %d", m_pCameraHandle, bRet);
        if (bRet)
        {
            m_pCameraHandle = NULL;
        }
    }
    MessageBox(chLog);
}


void CTest_NetDEVSDKDlg::OnBnClickedButtonCleanup()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    BOOL bRet = NETDEV_Cleanup();
    if (bRet)
    {
        m_pCameraHandle = NULL;
        m_pPlayHandle = NULL;
    }
    char chLog[MAX_PATH] = { 0 };
    sprintf_s(chLog, sizeof(chLog), "NETDEV_Cleanup,  return code = %d",  bRet);
    MessageBox(chLog);
}


void CTest_NetDEVSDKDlg::OnBnClickedButtonGetversion()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    INT32 iVersion = NETDEV_GetSDKVersion();
    int iMainVersion = iVersion >> 16;
    int iminorVersion = iVersion & 0x0000FFFF;

    char szLog[MAX_PATH] = {0};
    sprintf_s(szLog, sizeof(szLog), "major version = %d, iMinorVersion = %d", iMainVersion, iminorVersion);
    MessageBox(szLog);
}
