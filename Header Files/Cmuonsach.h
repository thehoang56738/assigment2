#pragma once
#include "afxdtctl.h"
#include "afxwin.h"


// Cmuonsach dialog

class Cmuonsach : public CDialog
{
	DECLARE_DYNAMIC(Cmuonsach)

public:
	Cmuonsach(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cmuonsach();
	//Cmuonsach(CWnd* pParent, CString strValue);
	virtual BOOL OnInitDialog();
	Cmuonsach(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GIOHANG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CDateTimeCtrl edit_time;
	CEdit edit_chontime;
	CListBox edit_listhang;
	CEdit edit_chonxoa;
public:
	afx_msg void OnBnClickedButtondangky();
	afx_msg void OnBnClickedButtonloaibo();
	afx_msg void OnLbnSelchangeListgiohang1();
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit1();
};
