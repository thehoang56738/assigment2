#pragma once


// cthongbaothanhcong dialog

class cthongbaothanhcong : public CDialog
{
	DECLARE_DYNAMIC(cthongbaothanhcong)

public:
	cthongbaothanhcong(CWnd* pParent = NULL);   // standard constructor
	virtual ~cthongbaothanhcong();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THONGBAOOK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
