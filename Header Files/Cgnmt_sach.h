#pragma once
#include "afxwin.h"


// Cgnmt_sach dialog

class Cgnmt_sach : public CDialog
{
	DECLARE_DYNAMIC(Cgnmt_sach)

public:
	Cgnmt_sach(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cgnmt_sach();
	virtual BOOL OnInitDialog();
	Cgnmt_sach::Cgnmt_sach(CWnd* pParent, CString str);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUONTRASACH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CListBox edit_ds_muonsach;
	CListBox edit_ds_trasach;
	CButton edit_xn_muonsach;
public:
	afx_msg void OnBnClickedXnmuonsach();
protected:
	CEdit edit_dc_muonsach;
public:
	afx_msg void OnLbnSelchangeListmuonsach();
	afx_msg void OnBnClickedXnmuonsach2();
	afx_msg void OnBnClickedXntrasach();
protected:
	CEdit edit_datrasach;
public:
	afx_msg void OnBnClickedDatrasachbutton();
	afx_msg void OnLbnSelchangeListtrasach();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
};
