// Cdangkimoi.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cdangkimoi.h"
#include "afxdialogex.h"
#include "Cthongbaohoantat.h"
#pragma once
#include <iostream>
#include <fstream>
#include <string>
//#include <string.h>
#include <sstream>
#include <tchar.h>


// Cdangkimoi dialog

IMPLEMENT_DYNAMIC(Cdangkimoi, CDialog)

Cdangkimoi::Cdangkimoi(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DANGKIMOI, pParent)
{

}

Cdangkimoi::~Cdangkimoi()
{
}

void Cdangkimoi::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_dkm_hoten);
	DDX_Control(pDX, IDC_EDIT2, edit_dkm_ngaysinh);
	DDX_Control(pDX, IDC_EDIT3, edit_dkm_email);
	DDX_Control(pDX, IDC_EDIT5, edit_dkm_ID);
	DDX_Control(pDX, IDC_EDIT4, edit_dkm_tendangnhap);
	DDX_Control(pDX, IDC_EDIT6, edit_dkm_matkhau);
	DDX_Control(pDX, IDC_BUTTON2, edit_dkm_hoantat);
	DDX_Control(pDX, IDC_EDIT7, edit_dkm_nhaplaimk);
}


BEGIN_MESSAGE_MAP(Cdangkimoi, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &Cdangkimoi::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cdangkimoi message handlers





void Cdangkimoi::OnBnClickedButton2()
{
	
	UpdateData(TRUE);

	CString str_1;
	edit_dkm_ID.GetWindowText(str_1);
	CT2CA d(str_1);
	std::string ID(d);

	CString str_2;
	edit_dkm_hoten.GetWindowText(str_2);
	CT2CA e(str_2);
	std::string hoten(e);
	
	CString str_3;
	edit_dkm_ngaysinh.GetWindowText(str_3);
	CT2CA f(str_3);
	std::string ngaysinh(f);

	CString str_4;
	edit_dkm_email.GetWindowText(str_4);
	CT2CA g(str_4);
	std::string email(g);

	CString str_5;
	edit_dkm_tendangnhap.GetWindowText(str_5);
	CT2CA h(str_5);
	std::string tendangnhap(h);

	CString str_6;
	edit_dkm_matkhau.GetWindowText(str_6);
	CT2CA i(str_6);
	std::string matkhau(i);

	CString str_7;
	edit_dkm_nhaplaimk.GetWindowText(str_7);
	CT2CA g1(str_7);
	std::string nhaplaimk(g1);

	
	using namespace std;
	/*CString string1;
	CStdioFile input(L"c:\\ttkhachhang.txt", CFile::modeRead);
	input.ReadString(string1);*/
	//if (matkhau.compare(nhaplaimk)!=0)
	//{
	//	// thêm dialog thông báo lỗi
	//	/*Cthongbaohoantat dg1;
	//	dg1.DoModal();*/
	//}
	//else
	{
		fstream fs01, fs02, fs03;
		int maso;
		/*CT2CA f15(string1);
		std::string str1__(f15);*/
		string str11;
		fs01.open("E:\\data\\ttkhachhang.txt", ios::in);
		getline(fs01, str11);
		if (str11 == "") maso = 1;
		else
		{
			maso = 1;
			while (!fs01.eof())
			{
				getline(fs01, str11);
				maso++;
			}
		}
		fs01.close();

		fs02.open("E:\\data\\ttkhachhang.txt", ios::app);
		fs02 << maso << ";" << ID << ";" << hoten << ";" << ngaysinh << ";" << email << endl;
		fs02.close();

		fs03.open("E:\\data\\tttk.txt", ios::app);
		fs03 << maso <<";1;1;" << tendangnhap << ";" << matkhau << endl;
		fs03.close();

		// tao 1 file trong E:\data\khachhang neu ko tao file nay se loi~
		string name = "E:\\data\\khachhang\\" + tendangnhap + ".txt";
		fstream ff11;
		ff11.open(name, ios::app);
		ff11.close();


		// tao 1 file trong E:\data\khachhang neu ko tao file nay se loi~ 
		string name1 = "E:\\data\\khachhangmuonsach\\" + tendangnhap + ".txt";
		fstream ff112;
		ff112.open(name1, ios::app);
		ff112.close();

		Cthongbaohoantat dg1;
		dg1.DoModal();
	}
	
	
}
