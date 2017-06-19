#pragma once


// Cinform dialog

class Cinform : public CDialog
{
	DECLARE_DYNAMIC(Cinform)

public:
	Cinform(CWnd* pParent = NULL);   // standard constructor
	virtual ~Cinform();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};
