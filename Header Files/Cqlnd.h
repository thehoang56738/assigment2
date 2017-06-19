#pragma once
#include "afxwin.h"
#include "SecondDlg.h"
//std::string tensys;


// Cqlnd dialog
class Cqlnd_tvt;
class Cqlnd : public CDialog
{
	DECLARE_DYNAMIC(Cqlnd)

public:
	Cqlnd(CWnd* pParent = NULL);   // standard constructor
	Cqlnd(CWnd* pParent, CString strValue); // ham khoi tao truyen tham so
	virtual ~Cqlnd();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QLND };
#endif

protected:
	CString tensys; // bien luu ten dang nhap
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
//protected:
	//virtual BOOL OnInitDialog();
	//virtual BOOL showaccount();
public:
	//afx_msg CString str111;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedQlndDmk();
	virtual BOOL OnInitDialog();
protected:
	CEdit edit_sys_tendangnhap;
public:
	afx_msg void OnEnChangeEdit1();
	//afx_msg void OnEnChangeThongbaoqlnd();
//protected:
private :
	CEdit edit_THONGBAOQLND;
public:
	afx_msg void OnBnClickedQlndTk();
	afx_msg void OnBnClickedQlndMktk();
	afx_msg void OnBnClickedQlndXoa();
	afx_msg void OnBnClickedQlndTvtQlnd();
	afx_msg void OnBnClickedQlndXoa2();
	//friend class Cqlnd_tvt;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeThongbaoqlnd();
};
