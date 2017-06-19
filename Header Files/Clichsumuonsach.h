#pragma once
#include "afxwin.h"


// Clichsumuonsach dialog

class Clichsumuonsach : public CDialog
{
	DECLARE_DYNAMIC(Clichsumuonsach)

public:
	Clichsumuonsach(CWnd* pParent = NULL);   // standard constructor
	virtual ~Clichsumuonsach();
	virtual BOOL Clichsumuonsach::OnInitDialog();
	Clichsumuonsach(CWnd* pParent, CString strValue);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LICHSUMUONSACH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CListBox edit_listmuonsach;
public:
	afx_msg void OnLbnSelchangeList1();
};
