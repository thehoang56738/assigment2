#pragma once


// Cthongbao dialog

class Cthongbao : public CDialog
{
	DECLARE_DYNAMIC(Cthongbao)

public:
	Cthongbao(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthongbao();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_thongbao };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
