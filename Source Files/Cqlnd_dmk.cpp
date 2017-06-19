// Cqlnd_dmk.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cqlnd_dmk.h"
#include "afxdialogex.h"
#include "SecondDlg.h"

#include "cthongbaothanhcong.h"
#include <iostream>
#include <fstream>
#include <string>

// Cqlnd_dmk dialog

IMPLEMENT_DYNAMIC(Cqlnd_dmk, CDialog)

Cqlnd_dmk::Cqlnd_dmk(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QLDN_DOIMATKHAU, pParent)
{

}

Cqlnd_dmk::~Cqlnd_dmk()
{
}
Cqlnd_dmk::Cqlnd_dmk(CWnd* pParent, CString str)
	: CDialog(IDD_QLDN_DOIMATKHAU, pParent)
{
	tensys = str;
}
void Cqlnd_dmk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_tendangnhap111);
}


BEGIN_MESSAGE_MAP(Cqlnd_dmk, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &Cqlnd_dmk::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cqlnd_dmk message handlers

//using namespace std;
//std::string tok(std::string &a)
//{
//	std::string b;
//	for (int i = 0; i < 16; i++)
//	{
//		int t = i;
//		if (a[i] == ';')
//		{
//			a = a.erase(0, i + 1);
//			break;
//		}
//		else  b.push_back(a[i]);
//	}
//	return b;
//
//}


//void Cqlnd_dmk::OnBnClickedButton2()
//{
//	// TODO: Add your control notification handler code here
//
//
//}


using namespace std;
//string tok(string &a)
//{
//	string b;
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] == ';')
//		{
//			a = a.erase(0, i + 1);
//			break;
//		}
//		else  b.push_back(a[i]);
//	}
//	return b;
//
//}
void Cqlnd_dmk::OnBnClickedButton2()
{
	UpdateData(TRUE);
	CString str_1;
	edit_tendangnhap111.GetWindowText(str_1);
	CT2CA ss(str_1);
	std::string tendn(ss);
	//fstream ff1;
	fstream filein, fileout;
	filein.open("E:\\data\\tttk.txt");
	fileout.open("E:\\data\\out.txt", ios::out);
	string s;
	string maso,matkhau,tt,yn;
	string c, d,e,f,line;
	while (filein.eof() == false)
	{
		getline(filein, s);
		line = s;
		c = tok(s);
		d = tok(s);
		e = tok(s);
		f = tok(s);
		if (f == tendn)
		{
			maso = c;
			tt = d;
			yn = e;
		}
		else {
			fileout << line << endl;
		}
	}
	fileout << maso << ";" << tt << ";" << yn << ";" << tendn << ";" << "123456" << endl;
	filein.close();
	fileout.close();
	remove("E:\\data\\tttk.txt");
	rename("E:\\data\\out.txt", "E:\\data\\tttk.txt");
	cthongbaothanhcong tk1;
	tk1.DoModal();
}