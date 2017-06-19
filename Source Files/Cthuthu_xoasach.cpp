// Cthuthu_xoasach.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cthuthu_xoasach.h"
#include "afxdialogex.h"

#include <cstdio>
// Cthuthu_xoasach dialog

IMPLEMENT_DYNAMIC(Cthuthu_xoasach, CDialog)

Cthuthu_xoasach::Cthuthu_xoasach(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TTXOASACH, pParent)
{

}

Cthuthu_xoasach::~Cthuthu_xoasach()
{
}
Cthuthu_xoasach::Cthuthu_xoasach(CWnd* pParent, CString str)
	: CDialog(IDD_TTXOASACH, pParent)
{
	tensys = str;
}
void Cthuthu_xoasach::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_tensach);
	DDX_Control(pDX, IDC_LIST_XOA, edit_list_xoa);
	DDX_Control(pDX, IDC_LIST1, edit_listsach);
}

BOOL Cthuthu_xoasach::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1;
	f1.open("E:\\data\\tensach.txt");
	while (!f1.eof())
	{
		string a;
		getline(f1, a);
		if (a != "")
		{
			CString b(a.c_str());
			edit_listsach.AddString(b);
		}
		else continue;
	}
	//z.Format(_T("%f"), data);

	// TODO:  Add extra initialization here
	//AfxMessageBox(_filename.GetBuffer());

	//	//edit_sys_tendangnhap.SetWindowText(tensys);
	//
	return TRUE;
}

BEGIN_MESSAGE_MAP(Cthuthu_xoasach, CDialog)
	ON_BN_CLICKED(IDOK, &Cthuthu_xoasach::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST1, &Cthuthu_xoasach::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// Cthuthu_xoasach message handlers


void Cthuthu_xoasach::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialog::OnOK();
	using namespace std;
	UpdateData(TRUE);
	CString str1;
	edit_tensach.GetWindowText(str1);
	CT2CA a(str1);
	string b(a);

	string c = exchange(b);
	//xóa list
	edit_list_xoa.ResetContent();
	ASSERT(edit_list_xoa.GetCount() == 0);
	string t = inhoa(b);
	CString z(t.c_str());
	edit_tensach.SetWindowText(z);
	fstream f1, f2;
	f1.open("E:\\data\\tensach.txt");
	f2.open("E:\\data\\thaythe.txt", ios::out);
	int check = 0;
	while (!f1.eof())
	{
		string ab;
		getline(f1, ab);
		string cd = exchange(ab);
		if (ab == "")continue;
		if (cd.compare(c) != 0)	f2 << ab << endl;
		else
		{
			check++;
			string ten = "E:\\data\\thuvien\\" + ab + ".txt";
			const char* name = ten.c_str();
			remove(name);
		}
	}
	if (check == 0)
		edit_list_xoa.AddString(_T("Sách không tồn tại trong thư viện!"));
	else edit_list_xoa.AddString(_T("Sách đã xóa khỏi thư viện!"));
	f1.close();
	f2.close();
	remove("E:\\data\\tensach.txt");
	rename("E:\\data\\thaythe.txt", "E:\\data\\tensach.txt");
}


void Cthuthu_xoasach::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}
