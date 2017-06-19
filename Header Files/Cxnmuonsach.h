#pragma once
#include "afxwin.h"
#include "Primary2Dlg.h"
#include "Cdocgia.h"
#include "afxdtctl.h"
// Cxnmuonsach dialog

class Cxnmuonsach : public CDialog
{
	DECLARE_DYNAMIC(Cxnmuonsach)

public:
	Cxnmuonsach(CWnd* pParent = NULL);   // standard constructor
	Cxnmuonsach(CWnd* pParent, CString strValue);
	virtual ~Cxnmuonsach();
	virtual BOOL OnInitDialog();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GIOHANG };
#endif

protected:
	CString tensys;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeListgiohang();
protected:
	
	CListBox edit_listgiohang;
	CEdit edit_xnloaibo;
public:
	afx_msg void OnBnClickedXnloaibo();
	afx_msg void OnBnClickedDangkymuon();
protected:
	CDateTimeCtrl edit_datetime;
	CDateTimeCtrl edit_ngaythang;
public:
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	CEdit edit_ngay;
};
