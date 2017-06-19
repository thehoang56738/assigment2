#pragma once
#include "afxwin.h"
#include "afxdtctl.h"


// Cdocgia_trasach dialog

class Cdocgia_trasach : public CDialog
{
	DECLARE_DYNAMIC(Cdocgia_trasach)

public:
	Cdocgia_trasach(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cdocgia_trasach();
	virtual BOOL Cdocgia_trasach::OnInitDialog();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOCGIATRASACH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CListBox edit_list;
	CEdit edit_chon;
public:
	afx_msg void OnBnClickedDocgiatrasach();
protected:
	CEdit edit_chontime;
public:
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	CDateTimeCtrl edit_time;
public:
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLbnSelchangeList1();
protected:
	CDateTimeCtrl edit_time1;
};
