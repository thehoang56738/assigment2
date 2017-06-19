#pragma once
#include "afxwin.h"


// Clichsutrasach dialog

class Clichsutrasach : public CDialog
{
	DECLARE_DYNAMIC(Clichsutrasach)

public:
	Clichsutrasach(CWnd* pParent = NULL);   // standard constructor
	virtual ~Clichsutrasach();
	virtual BOOL Clichsutrasach::OnInitDialog();
	Clichsutrasach(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LICHSUTRASACH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CListBox edit_listtrasach;
public:
	afx_msg void OnLbnSelchangeList1();
};
