#pragma once


// Cthongbao1 dialog

class Cthongbao1 : public CDialog
{
	DECLARE_DYNAMIC(Cthongbao1)

public:
	Cthongbao1(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthongbao1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_thongbao };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
protected:
	CEdit edit_thongbao1;
};
