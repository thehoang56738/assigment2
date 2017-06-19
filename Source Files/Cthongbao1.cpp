#include "Cthongbao1.h"
// Cthongbao1.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cthongbao1.h"
#include "afxdialogex.h"


// Cthongbao1 dialog

IMPLEMENT_DYNAMIC(Cthongbao1, CDialog)

Cthongbao1::Cthongbao1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_thongbao, pParent)
{

}

Cthongbao1::~Cthongbao1()
{
}

void Cthongbao1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cthongbao1, CDialog)
	ON_BN_CLICKED(IDOK, &Cthongbao1::OnBnClickedOk)
END_MESSAGE_MAP()


// Cthongbao1 message handlers


void Cthongbao1::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
