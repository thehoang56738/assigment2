#pragma once
#include "afxwin.h"


// Cdocgia_dmk dialog

class Cdocgia_dmk : public CDialog
{
	DECLARE_DYNAMIC(Cdocgia_dmk)

public:
	Cdocgia_dmk(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cdocgia_dmk();
	virtual BOOL OnInitDialog();
	Cdocgia_dmk::Cdocgia_dmk(CWnd* pParent, CString str);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOCGIA_DMK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	CString tensys;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
protected:
	CEdit edit_mk_moi;
	CEdit edit_mk_moi2;
	CEdit edit_mk_nhaplai;
	CEdit edit_docgia_dmk;
	CEdit edit_thongbao;
};
