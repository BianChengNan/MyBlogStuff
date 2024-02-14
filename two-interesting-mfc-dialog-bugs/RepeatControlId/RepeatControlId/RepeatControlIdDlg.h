
// RepeatControlIdDlg.h : header file
//

#pragma once


// CRepeatControlIdDlg dialog
class CRepeatControlIdDlg : public CDialogEx
{
// Construction
public:
	CRepeatControlIdDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_REPEATCONTROLID_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnShowHide();
	afx_msg void OnBnClickedBtnSetText();
};
