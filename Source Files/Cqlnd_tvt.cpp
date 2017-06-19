// Cqlnd_tvt.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cqlnd_tvt.h"
#include "afxdialogex.h"
#include "SecondDlg.h"

#include "Cqlnd.h"
#include "cthongbaothanhcong.h"


// Cqlnd_tvt dialog

IMPLEMENT_DYNAMIC(Cqlnd_tvt, CDialog)

Cqlnd_tvt::Cqlnd_tvt(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QLND_TVT, pParent)
{

}

Cqlnd_tvt::~Cqlnd_tvt()
{
}

void Cqlnd_tvt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_QLND_TVT_TDN, edit_qlnd_tvt_tdn);
	DDX_Control(pDX, IDC_QLND_TVT_THUTHU, edit_qlnd_tvt_thuthu);
	DDX_Control(pDX, IDC_QLND_TVT_QLND, edit_qlnd_tvt_qlnd);
	DDX_Control(pDX, IDC_QLND_TVT_HVT, edit_qlnd_tvt_hvt);
}


BEGIN_MESSAGE_MAP(Cqlnd_tvt, CDialog)
	ON_BN_CLICKED(IDC_QLND_TVT_TVT, &Cqlnd_tvt::OnBnClickedQlndTvtTvt)
	ON_BN_CLICKED(IDC_QLND_TVT_HVT, &Cqlnd_tvt::OnBnClickedQlndTvtHvt)
END_MESSAGE_MAP()


// Cqlnd_tvt message handlers


// con mot so lo~ hong~ , se khac phuc sau
void Cqlnd_tvt::OnBnClickedQlndTvtTvt()
{

	UpdateData(TRUE);
	using namespace std;
	CString cs1;
	edit_qlnd_tvt_tdn.GetWindowText(cs1);
	CT2CA ss1(cs1);
	string tendangnhap(ss1);
	// kiem tra xem ten dang nhap co hop le khong
	
	string filename = "E:\\data\\ttanhxa.txt";

	string line1, line2;
	string data1 = tendangnhap + ";" + "thuthu";
	string data2 = tendangnhap + ";" + "qlnd";
	
	if (edit_qlnd_tvt_thuthu.GetCheck() == 1)
	{

		fstream ff1;
		int check = 0;
		ff1.open(filename, ios::in);
		while (!ff1.eof())
		{
			getline(ff1, line1);
			if (line1 == data1)
			{
				check = 1;
				break;
			}
		}
		ff1.close();
		if (check == 0)
		{
			fstream ff2;
			ff2.open(filename, ios::app);
			ff2 << data1 << endl;
			ff2.close();
		}
		fstream ff12;
		ff12.open("E:\\data\\lichsu_qlnd.txt", ios::app);
		ff12 << data1 << endl;
		ff12.close();


	}
	if (edit_qlnd_tvt_qlnd.GetCheck() == 1)
	{
		fstream ff3;
		int check1 = 0;
		ff3.open(filename, ios::in);
		while (!ff3.eof())
		{
			getline(ff3, line2);
			if (line2 == data2)
			{
				check1 = 1;
				break;
			}
		}
		ff3.close();
		if (check1 == 0)
		{
			fstream ff4;
			ff4.open(filename, ios::app);
			ff4 << data2 << endl;
			ff4.close();
		}

		fstream ff12;
		ff12.open("E:\\data\\lichsu_qlnd.txt", ios::app);
		ff12 << data2 << endl;
		ff12.close();

	}


	cthongbaothanhcong tk1;
	tk1.DoModal();
	
}
//Cqlnd::OnInitDialog()
////xoa tendangnhap + ";" + "qlnd" trong  list_themvaitro.txt
//fstream fs01;
//string para = "";
//fs01.open("E:\\data\\list_themvaitro.txt", ios::in);
//while (!fs01.eof())
//{
//	getline(cin, line2);
//	if (line2 != data2) para = para + line2 + '\n';
//}
//fs01.close();
//fstream fs02;
//fs02.open("E:\\data\\list_themvaitro.txt", ios::out);
//fs02 << para;
//fs02.close();

void Cqlnd_tvt::OnBnClickedQlndTvtHvt()
{
	UpdateData(TRUE);
	using namespace std;
	CString cs1;
	edit_qlnd_tvt_tdn.GetWindowText(cs1);
	CT2CA ss1(cs1);
	string tendangnhap(ss1);
	// kiem tra xem ten dang nhap co hop le khong
	string filename = "E:\\data\\ttanhxa.txt";
	string line1, data = "";
	string data1 = tendangnhap + ";" + "thuthu";
	string data2 = tendangnhap + ";" + "qlnd";
	fstream ff1;
	int check = 0;
	ff1.open(filename, ios::in);
	while (!ff1.eof())
	{
		getline(ff1, line1);
		if (edit_qlnd_tvt_thuthu.GetCheck() == 1 && line1 == data1)
		{
			check = 1;
			continue;
		}
		else if (edit_qlnd_tvt_qlnd.GetCheck() == 1 && line1 == data2)
		{
			check = 1;
			continue;
		}
		else data = data + line1 + "\n";
	}
	ff1.close();
	if (check == 1)
	{
		ff1.open(filename, ios::out);
		ff1 << data;
		ff1.close();
	}

	cthongbaothanhcong tk2;
	tk2.DoModal();

}
