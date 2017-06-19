#pragma once
#include "afxwin.h"


// Cdocgia dialog

class Cdocgia : public CDialog
{
	DECLARE_DYNAMIC(Cdocgia)

public:
	Cdocgia(CWnd* pParent = NULL);   // standard constructor
	Cdocgia(CWnd* pParent, CString strValue);
	virtual ~Cdocgia();
	virtual BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOCGIA };
#endif

protected:
	CString tensys;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CEdit edit_docgia_tensys;
public:
	afx_msg void OnEnChangeThongbaoqlnd();
protected:
	CEdit edit_thongbaodocgia;
public:
	afx_msg void OnBnClickedDocgiaMuonsach();
	//afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedDocgiaTrasach();
	afx_msg void OnBnClickedDocgiaThongtin();
	afx_msg void OnBnClickedDocgiaTrasach2();
};
