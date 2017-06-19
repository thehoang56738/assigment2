// Cqlnd_xoa.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cqlnd_xoa.h"
#include "afxdialogex.h"

#include "SecondDlg.h"
#include "cthongbaothanhcong.h"

// Cqlnd_xoa dialog

IMPLEMENT_DYNAMIC(Cqlnd_xoa, CDialog)

Cqlnd_xoa::Cqlnd_xoa(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QLND_XOA, pParent)
{

}

Cqlnd_xoa::~Cqlnd_xoa()
{
}

void Cqlnd_xoa::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_QLND_XOA_TDN, edit_qlnd_xoa_tdn);
}


BEGIN_MESSAGE_MAP(Cqlnd_xoa, CDialog)
	ON_BN_CLICKED(IDC_QLND_XOA_XOA, &Cqlnd_xoa::OnBnClickedQlndXoaXoa)
END_MESSAGE_MAP()


// Cqlnd_xoa message handlers


void Cqlnd_xoa::OnBnClickedQlndXoaXoa() // moi xoa trong tttk.txt , chua xoa trong ttanha.txt
{
	using namespace std;
	UpdateData(TRUE);
	CString cs1;
	edit_qlnd_xoa_tdn.GetWindowText(cs1);
	CT2CA ss12(cs1);
	string tendangnhap(ss12);
	fstream ff1;
	string line1, data = "", s;

	string filename1 = "E:\\data\\tttk.txt";

	string filename2 = "E:\\data\\ttanhxa.txt";

	ff1.open(filename1, ios::in);
	string maso, tt, yn, tendn;
	int check = 0;// de kiem tra co ton tai tk de xoa hay khong
	while (!ff1.eof())
	{
		getline(ff1, line1);
		s = line1;
		maso = tok(s);
		tt = tok(s);
		yn = tok(s);
		tendn = tok(s);
		if (tendn == tendangnhap) check = 1; // co ton tai
		else data = data + line1 + "\n";
	}
	ff1.close();
	if (check == 1) // co ton tai thi xoa
	{
		fstream ff2;
		ff2.open(filename1, ios::out);
		ff2 << data << endl;
		ff2.close();
	}

	// xoa trong file ten dang nhap;
	fstream ff3;
	int check2 = 0;
	string data2 = "", line2, s2;
	string tendn2;
	ff3.open(filename2, ios::in);
	while (!ff3.eof())
	{
		getline(ff3, line2);
		s2 = line2;
		tendn2 = tok(s2);
		if (tendn2 == tendangnhap)
		{
			check2 = 1;
		}
		else data2 = data2 + line2 + "\n";

	}
	ff3.close();
	if (check2 == 1) // neu co ton tai thi xoa , ko ton tai thi thoi
	{
		fstream ff4;
		ff4.open(filename2, ios::out);
		ff4 << data2;
		ff4.close();
	}

	cthongbaothanhcong tk1;
	tk1.DoModal();
}
