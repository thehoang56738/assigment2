#pragma once
#include "afxwin.h"


// Cthuthu_timkiem dialog

class Cthuthu_timkiem : public CDialog
{
	DECLARE_DYNAMIC(Cthuthu_timkiem)

public:
	Cthuthu_timkiem(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthuthu_timkiem();
	Cthuthu_timkiem(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THUTHUTIMKIEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CEdit edit_timkiemsach;
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedTimkiemsach();
protected:
	CListBox edit_listtimsach;
public:
	afx_msg void OnLbnSelchangeListtimsach();
protected:
	CEdit edit_noidungsach;
};
