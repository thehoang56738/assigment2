// Cqlnd_mktk.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cqlnd_mktk.h"
#include "afxdialogex.h"
#include "SecondDlg.h"

#include "cthongbaothanhcong.h"

// Cqlnd_mktk dialog

IMPLEMENT_DYNAMIC(Cqlnd_mktk, CDialog)

Cqlnd_mktk::Cqlnd_mktk(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QLND_MKTK, pParent)
{

}

Cqlnd_mktk::~Cqlnd_mktk()
{
}

void Cqlnd_mktk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_QLND_MKTK_TDN, edit_qlnd_mktk_tdn);
}


BEGIN_MESSAGE_MAP(Cqlnd_mktk, CDialog)
	ON_BN_CLICKED(IDC_QLND_MKTK_KTK, &Cqlnd_mktk::OnBnClickedQlndMktkKtk)
	ON_BN_CLICKED(IDC_QLND_MKTK_MTK, &Cqlnd_mktk::OnBnClickedQlndMktkMtk)
END_MESSAGE_MAP()


// Cqlnd_mktk message handlers


void Cqlnd_mktk::OnBnClickedQlndMktkKtk() // khoa tai khoan
{
	UpdateData(TRUE);
	CString cs1;
	edit_qlnd_mktk_tdn.GetWindowText(cs1);
	CT2CA csss(cs1);
	std::string tendangnhap(csss);
	using namespace std;
	string filename1 = "E:\\data\\tttk.txt";
	
	int check = 1;

	fstream ff1, ff2;
	ff1.open(filename1, ios::in);
	string line1, s;
	string data="";
	string maso, tt, yn, tendn;
	while (!ff1.eof())
	{
		getline(ff1, line1);
		s = line1;
		maso = tok(s);
		tt = tok(s);
		yn = tok(s);
		tendn = tok(s);
		if (tendn == tendangnhap)
		{
			if (yn == "1") data = data + maso + ";" + tt + ";0;" + tendangnhap + ";" + s + "\n";
			else
			{
				check = 0;
				break;
			}
		}
		else data = data + line1 + "\n";
	}
	ff1.close();
	if (check == 1) // check=0 tuc la khong can thay doi du lieu
	{
		ff2.open(filename1, ios::out);
		ff2 << data;
		ff2.close();
	}
	cthongbaothanhcong tk1;
	tk1.DoModal();
}
void Cqlnd_mktk::OnBnClickedQlndMktkMtk() // mo tai khoan
{
	UpdateData(TRUE);
	CString cs1;
	edit_qlnd_mktk_tdn.GetWindowText(cs1);
	CT2CA csss(cs1);
	std::string tendangnhap(csss);
	using namespace std;

	string filename1 = "E:\\data\\tttk.txt";

	int check = 1; // kiem tra

	fstream ff1, ff2;
	ff1.open(filename1, ios::in);
	string line1, s;
	string data="";
	string maso, tt, yn, tendn;
	while (!ff1.eof())
	{
		getline(ff1, line1);
		s = line1;
		maso = tok(s);
		tt = tok(s);
		yn = tok(s);
		tendn = tok(s);
		if (tendn == tendangnhap)
		{
			if (yn == "0") data = data + maso + ";" + tt + ";1;" + tendangnhap + ";" + s + "\n";
			else
			{
				check = 0;
				break;
			}
		}
		else data = data + line1 + "\n";
	}
	ff1.close();
	if (check == 1) // check=0 tuc la khong can thay doi du lieu
	{
		ff2.open(filename1, ios::out);
		ff2 << data;
		ff2.close();
	}
	cthongbaothanhcong tk2;
	tk2.DoModal();
}
