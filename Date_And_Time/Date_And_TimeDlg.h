
// Date_And_TimeDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

// CDate_And_TimeDlg �Ի���
class CDate_And_TimeDlg : public CDialogEx
{
// ����
public:
	CDate_And_TimeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DATE_AND_TIME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBexit();
	CProgressCtrl m_ctrlProgress;
};

UINT proc(LPVOID pParam);