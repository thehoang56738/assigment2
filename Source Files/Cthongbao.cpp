// Cthongbao.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cthongbao.h"
#include "afxdialogex.h"


// Cthongbao dialog

IMPLEMENT_DYNAMIC(Cthongbao, CDialog)

Cthongbao::Cthongbao(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_thongbao, pParent)
{

}

Cthongbao::~Cthongbao()
{
}

void Cthongbao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cthongbao, CDialog)
	ON_BN_CLICKED(IDOK, &Cthongbao::OnBnClickedOk)
END_MESSAGE_MAP()


// Cthongbao message handlers


void Cthongbao::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
