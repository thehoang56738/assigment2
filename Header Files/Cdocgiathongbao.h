#pragma once
#include "afxwin.h"


// Cdocgiathongbao dialog

class Cdocgiathongbao : public CDialog
{
	DECLARE_DYNAMIC(Cdocgiathongbao)

public:
	Cdocgiathongbao(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cdocgiathongbao();
	virtual BOOL Cdocgiathongbao::OnInitDialog();
	Cdocgiathongbao::Cdocgiathongbao(CWnd* pParent, CString str);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOCGIATHONGBAO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
	CListBox edit_listthongbao;
public:
	afx_msg void OnLbnSelchangeListthongbao();
protected:
	CListBox edit_listtrasach;
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLbnSelchangeListthongbao2();
};
