// Clichsumuonsach.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Clichsumuonsach.h"
#include "afxdialogex.h"


// Clichsumuonsach dialog

IMPLEMENT_DYNAMIC(Clichsumuonsach, CDialog)

Clichsumuonsach::Clichsumuonsach(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LICHSUMUONSACH, pParent)
{

}

Clichsumuonsach::~Clichsumuonsach()
{
}
Clichsumuonsach::Clichsumuonsach(CWnd* pParent, CString str)
	: CDialog(IDD_LICHSUMUONSACH, pParent)
{
	tensys = str;
}
void Clichsumuonsach::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, edit_listmuonsach);
}

BOOL Clichsumuonsach::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1;
	f1.open("E:\\data\\lichsu_muonsach.txt");
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		if (ab != "")
		{
			string ms = tok(ab);//lấy ms
			string a = tok(ab);//lấy tên tài khoản
			string b = tok(ab);//Lấy tên sách
			string d = tok(ab);//Lấy số lượng
			//string e = tok(ab);//Lấy ngày tháng
			string ten = a + " :: " + b + " :: " + d + " :: " + ab;
			CString c(ten.c_str());
			edit_listmuonsach.AddString(c);
		}
	}
	f1.close();
	return TRUE;
}
BEGIN_MESSAGE_MAP(Clichsumuonsach, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST1, &Clichsumuonsach::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// Clichsumuonsach message handlers


void Clichsumuonsach::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}
