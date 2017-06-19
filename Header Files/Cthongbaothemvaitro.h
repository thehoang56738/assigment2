#pragma once


// Cthongbaothemvaitro dialog

class Cthongbaothemvaitro : public CDialog
{
	DECLARE_DYNAMIC(Cthongbaothemvaitro)

public:
	Cthongbaothemvaitro(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cthongbaothemvaitro();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THONGBAO_THEMTAIKHOAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
