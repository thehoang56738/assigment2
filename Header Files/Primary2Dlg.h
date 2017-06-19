
// Primary2Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// CPrimary2Dlg dialog
class CPrimary2Dlg : public CDialogEx
{
// Construction
public:
	CPrimary2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRIMARY2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSecondBtn();
	afx_msg void OnBnClickedButton1();
	/*afx_msg void OnBnClickedThirdBtn();*/
	afx_msg void OnBnClickTimkiem();
protected:
	CButton edit_timkiem;
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickeddangkimoi();
	afx_msg void OnBnClickeddangkimoi2();
protected:
	CEdit edit_tendangnhap;
	CEdit edit_matkhau;
	int edit_doc_gia;
	int edit_thu_thu;
	int edit_quan_li_nguoi_dung;
public:
	afx_msg void OnBnClickedButton2();
};
