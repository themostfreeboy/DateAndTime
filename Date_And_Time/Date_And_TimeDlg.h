
// Date_And_TimeDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

// CDate_And_TimeDlg 对话框
class CDate_And_TimeDlg : public CDialogEx
{
// 构造
public:
	CDate_And_TimeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DATE_AND_TIME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBexit();
	CProgressCtrl m_ctrlProgress;
};

UINT proc(LPVOID pParam);