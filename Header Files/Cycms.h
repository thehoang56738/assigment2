#pragma once
#include "afxwin.h"


// Cycms dialog

class Cycms : public CDialog
{
	DECLARE_DYNAMIC(Cycms)

public:
	Cycms(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cycms();
	Cycms(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GUIYEUCAU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CEdit edit_ycmsnoidung;
public:
	afx_msg void OnBnClickedYcmstimkiem();
protected:
	CListBox edit_ycmslist;
public:
	CEdit edit_ycmstensach;
	afx_msg void OnLbnSelchangeYcmslist();
	afx_msg void OnBnClickedYcmsgui();
protected:
	CButton edit_giohang;
public:
	afx_msg void OnBnClickedYcmsgiohang();
};
