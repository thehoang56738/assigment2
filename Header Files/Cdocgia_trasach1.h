#pragma once
#include "afxwin.h"


// Cdocgia_trasach1 dialog

class Cdocgia_trasach1 : public CDialog
{
	DECLARE_DYNAMIC(Cdocgia_trasach1)

public:
	Cdocgia_trasach1(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cdocgia_trasach1();
	virtual BOOL Cdocgia_trasach1::OnInitDialog();
	Cdocgia_trasach1(CWnd* pParent, CString strValue);
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOCGIATRASACH };
#endif

protected:
	CString tensys;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	CEdit edit_chontime;
	CListBox edit_list;
	CEdit edit_chon;
public:
	afx_msg void OnLbnSelchangeList11();
	afx_msg void OnBnClickedDocgiatrasach1();
	afx_msg void OnBnClickedButtontraall();
};
