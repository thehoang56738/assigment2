// Cthemvaitro.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cthemvaitro.h"
#include "afxdialogex.h"
#include "Cthongbaothemvaitro.h"
#include "Csaimatkhau.h";

#include "SecondDlg.h"


// Cthemvaitro dialog

IMPLEMENT_DYNAMIC(Cthemvaitro, CDialog)

Cthemvaitro::Cthemvaitro(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_THEMVAITRO, pParent)
{

}

Cthemvaitro::~Cthemvaitro()
{
}
Cthemvaitro::Cthemvaitro(CWnd* pParent, CString str)
	: CDialog(IDD_THEMVAITRO, pParent)
{
	tensys = str;
}
void Cthemvaitro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_tendangnhap_tvt);
	DDX_Control(pDX, IDC_EDIT2, edit_matkhau_tvt);
	DDX_Control(pDX, IDC_CHECK1, edit_thuthu_tvt);
	DDX_Control(pDX, IDC_CHECK2, edit_qldn_tvt);
	DDX_Control(pDX, IDC_EDIT8, edit_themvaitro_nhaplaimk);
}


BEGIN_MESSAGE_MAP(Cthemvaitro, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Cthemvaitro::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cthemvaitro message handlers


void Cthemvaitro::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	using namespace std;
	UpdateData(TRUE);
	CString str_1;
	edit_tendangnhap_tvt.GetWindowText(str_1);
	CT2CA fsf(str_1);
	string tendangnhap(fsf);
	CString str_2;
	edit_matkhau_tvt.GetWindowText(str_2);
	CT2CA fg1(str_2);
	string matkhau(fg1);

	CString str_3;
	edit_themvaitro_nhaplaimk.GetWindowText(str_3);
	CT2CA kk(str_3);
	string nhaplaihmatkhau(kk);
	
	int kiemtra = 0;
	int check = 0;
	if (nhaplaihmatkhau == matkhau) // chua chac mat khau da dung
	{
		kiemtra = 1;//

		fstream ff1;
		ff1.open("E:\\data\\tttk.txt", ios::in);
		string line;
		
		string a, b, c, tendn, mk;

		while (!ff1.eof())
		{
			getline(ff1, line);
			if (line == "") continue;
			else
			{
				a = tok(line);
				b = tok(line);
				c = tok(line);
				tendn = tok(line);
				mk = tok(line);
				if (tendn == tendangnhap&&mk == matkhau)// kiem tra
				{
					check = 1;//

					fstream fs1234;
					string ten = "E:\\data\\list_themtaikhoan.txt";
					fs1234.open(ten, ios::app);
					if (edit_thuthu_tvt.GetCheck() == 1)
					{
						fs1234 << tendangnhap << ";thuthu" << endl;
					}
					if (edit_qldn_tvt.GetCheck() == 1)
					{
						fs1234 << tendangnhap << ";qlnd" << endl;
					}
					fs1234.close();

					Cthongbaothemvaitro dlg11;// thong bao ok;
					dlg11.DoModal();
					break;
				}
				else continue;
			}
		}
		ff1.close();
		UpdateData(FALSE);
	}
	if (check == 0||kiemtra==0)
	{
		Csaimatkhau dgf1;
		dgf1.DoModal();
	}
}
//fstream fs123;
//fs123.open("E:\\data\\ttanhxa.txt", ios::in);
//string str__;
//string as, bs;
//while (!fs123.eof())
//{
//	getline(fs123, str__);
//	as = tok(str__);
//	//bs = tok(str__);
//	if (str__ == "qlnd") break;
//}


//fs123.close();