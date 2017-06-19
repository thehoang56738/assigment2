// Cqlnd_tk.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cqlnd_tk.h"
#include "afxdialogex.h"
#include "SecondDlg.h"


// Cqlnd_tk dialog

IMPLEMENT_DYNAMIC(Cqlnd_tk, CDialog)

Cqlnd_tk::Cqlnd_tk(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QLND_TK, pParent)
{

}

Cqlnd_tk::~Cqlnd_tk()
{
}

void Cqlnd_tk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_QLND_TK_TDN, edit_qlnd_tk_tdn);
	DDX_Control(pDX, IDC_QLND_TK_HVT, edit_qlnd_tk_hvt);
	DDX_Control(pDX, IDC_QLND_TK_MSSV, edit_qlnd_tk_mssv);
	DDX_Control(pDX, IDC_QLND_TK_NS, edit_qlnd_tk_ns);
	DDX_Control(pDX, IDC_QLND_TK_EM, edit_qlnd_tk_em);
	DDX_Control(pDX, IDC_QLND_TK_MSTK, edit_qlnd_tk_mstk);
	DDX_Control(pDX, IDC_QLND_TK_DSTK, edit_qlnd_tk_dstk);
}


BEGIN_MESSAGE_MAP(Cqlnd_tk, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Cqlnd_tk::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cqlnd_tk message handlers


void Cqlnd_tk::OnBnClickedButton1() // them ds role
{
	using namespace std;
	UpdateData(TRUE);
	CString cs_1;
	edit_qlnd_tk_tdn.GetWindowText(cs_1);
	CT2CA ss(cs_1);
	string tendangnhap(ss);
	fstream ff1, ff2, ff3;

	string tenfile = "E:\\data\\tttk.txt";
	ff1.open(tenfile, ios::in);
	string line;
	string mstk, a, b, tendn, data = "";
	string mstk001, tendn001;
	while (!ff1.eof())
	{
		getline(ff1, line);
		mstk = tok(line); // mstk
		a = tok(line); // tt
		b = tok(line); // 0 hoac 1
		tendn = tok(line); // ten dang nhap
		if (tendn == tendangnhap) break;
	}
	ff1.close();
	ff3.open(tenfile, ios::in);
	string line001;
	while (!ff3.eof())
	{
		getline(ff3, line001);
		mstk001 = tok(line001);
		if (mstk001 == mstk)
		{
			string role = "  role :  docgia  ",fileline,tk1;
			a = tok(line001);
			b = tok(line001);
			tendn001 = tok(line001);
			fstream file1;
			file1.open("E:\\data\\ttanhxa.txt", ios::in);
			while (!file1.eof())
			{
				getline(file1, fileline);
				tk1 = tok(fileline);
				if (tk1 == tendn001) role = role + fileline + "  ";
			}
			file1.close();
			data = data + tendn001 + role + "\r\n";
		}
	}
	ff3.close();

	string tenfile2 = "E:\\data\\ttkhachhang.txt";
	ff2.open(tenfile2, ios::in);
	string line2;
	string mstk1, hvt, mssv, ns, em;
	while (!ff2.eof())
	{
		getline(ff2, line2);
		mstk1 = tok(line2);
		if (mstk1 == mstk)
		{
			mssv = tok(line2);
			hvt = tok(line2);
			ns = tok(line2);
			em = line2;
			break;
		}
	}
	ff2.close();

	CString MSTK(mstk.c_str());
	CString HVT(hvt.c_str());
	CString EM(em.c_str());
	CString MSSV(mssv.c_str());
	CString NS(ns.c_str());
	CString DSTK(data.c_str());

	edit_qlnd_tk_em.SetWindowText(EM);
	edit_qlnd_tk_hvt.SetWindowText(HVT);
	edit_qlnd_tk_mssv.SetWindowText(MSSV);
	edit_qlnd_tk_mstk.SetWindowText(MSTK);
	edit_qlnd_tk_ns.SetWindowText(NS);
	edit_qlnd_tk_dstk.SetWindowText(DSTK);

	UpdateData(FALSE);
}
