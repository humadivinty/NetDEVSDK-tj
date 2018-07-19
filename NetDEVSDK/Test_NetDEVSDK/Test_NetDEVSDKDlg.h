
// Test_NetDEVSDKDlg.h : 头文件
//

#pragma once


// CTest_NetDEVSDKDlg 对话框
class CTest_NetDEVSDKDlg : public CDialogEx
{
// 构造
public:
	CTest_NetDEVSDKDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST_NETDEVSDK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonInit();
    afx_msg void OnBnClickedButtonLogin();
    afx_msg void OnBnClickedButtonRealplay();
    afx_msg void OnBnClickedButtonStoprealplay();
    afx_msg void OnBnClickedButtonLogout();
    afx_msg void OnBnClickedButtonCleanup();
    

private:
    void* m_pCameraHandle;
    void* m_pPlayHandle;
public:
    afx_msg void OnBnClickedButtonGetversion();
};
