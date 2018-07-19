
// Test_NetDEVSDKDlg.h : ͷ�ļ�
//

#pragma once


// CTest_NetDEVSDKDlg �Ի���
class CTest_NetDEVSDKDlg : public CDialogEx
{
// ����
public:
	CTest_NetDEVSDKDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST_NETDEVSDK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
