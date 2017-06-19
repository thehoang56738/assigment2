#pragma once
#include "afxwin.h"
#include <iostream>
#include <string>
#include <fstream>


// Cdangkimoi dialog

class Cdangkimoi : public CDialog
{
	DECLARE_DYNAMIC(Cdangkimoi)

public:
	Cdangkimoi(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cdangkimoi();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DANGKIMOI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CEdit edit_dkm_hoten;
	CEdit edit_dkm_ngaysinh;
	CEdit edit_dkm_email;
	CEdit edit_dkm_ID;
public:

protected:
	CEdit edit_dkm_tendangnhap;
	CEdit edit_dkm_matkhau;
	CButton edit_dkm_hoantat;
public:
	afx_msg void OnBnClickedButton2();
protected:
	CEdit edit_dkm_nhaplaimk;
};
