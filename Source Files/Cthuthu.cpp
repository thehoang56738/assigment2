// Cthuthu.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cthuthu.h"
#include "afxdialogex.h"
#include "Cthemvao1.h"
#include "Cthuthu_timkiem.h"
#include "Cthuthu_xoasach.h"
#include "Cgnmt_sach.h"


// Cthuthu dialog

IMPLEMENT_DYNAMIC(Cthuthu, CDialog)

Cthuthu::Cthuthu(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_THUTHU, pParent)
{

}
Cthuthu::Cthuthu(CWnd* pParent, CString str)
	: CDialog(IDD_THUTHU, pParent)
{
	tensys = str;
}

Cthuthu::~Cthuthu()
{
}

void Cthuthu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_thuthu_tensys, edit_thuthu_tensys);
	DDX_Control(pDX, IDC_THONGBAOTHUTHU, edit_thongbaothuthu);
}


BEGIN_MESSAGE_MAP(Cthuthu, CDialog)
	ON_BN_CLICKED(IDC_THUTHUTHEMVAO, &Cthuthu::OnBnClickedThuthuthemvao)
	ON_BN_CLICKED(IDC_THUTHUTIMKIEM, &Cthuthu::OnBnClickedThuthutimkiem)
	ON_BN_CLICKED(IDC_THUTHUXOASACH, &Cthuthu::OnBnClickedThuthuxoasach)
	ON_BN_CLICKED(IDC_GHINHANMUONTRA, &Cthuthu::OnBnClickedGhinhanmuontra)
	ON_EN_CHANGE(IDC_THONGBAOTHUTHU, &Cthuthu::OnEnChangeThongbaothuthu)
END_MESSAGE_MAP()

BOOL Cthuthu::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1, f2;
	CT2CA d(tensys);
	string abc(d);
	string tenfile = "E:\\data\\listmuonsach.txt";
	f1.open(tenfile, ios::in);
	string data = "", line;
	while (!f1.eof())
	{
		getline(f1, line);
		if (line != "")
		{
			
			string a = tok(line);// Lấy tên tài khoản Lấy tên môn học 
			string b = tok(line);//Lấy tên sách
			string c = tok(line);//Lấy số lượng
			data += "Khach hang: " + a + " Dang ky muon: " + c + " Cuon " + b + " Vao ngay: " + line + "\r\n";
		}
	}
	f1.close();
	CString z(data.c_str());
	edit_thongbaothuthu.SetWindowText(z);
	edit_thuthu_tensys.SetWindowText(tensys);
	return TRUE;
}

// Cthuthu message handlers


void Cthuthu::OnBnClickedThuthuthemvao()
{
	// TODO: Add your control notification handler code here
	Cthemvao1 dg1;
	dg1.DoModal();
}


void Cthuthu::OnBnClickedThuthutimkiem()
{
	// TODO: Add your control notification handler code here
	Cthuthu_timkiem trans;
	trans.DoModal();
}


void Cthuthu::OnBnClickedThuthuxoasach()
{
	// TODO: Add your control notification handler code here
	Cthuthu_xoasach xoa;
	xoa.DoModal();
}


void Cthuthu::OnBnClickedGhinhanmuontra()
{
	// TODO: Add your control notification handler code here
	Cgnmt_sach th(NULL, tensys); //
	th.DoModal();
}


void Cthuthu::OnEnChangeThongbaothuthu()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
