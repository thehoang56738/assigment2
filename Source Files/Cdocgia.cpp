// Cdocgia.cpp : implementation file
//

#include "stdafx.h"
#include "Primary2.h"
#include "Cdocgia.h"
#include "afxdialogex.h"
#include "Cycms.h"
#include "Cdocgia_trasach1.h"
#include "Cdocgiathongbao.h"
#include "SecondDlg.h"
#include "Cdocgia_dmk.h" 
// Cdocgia dialog

IMPLEMENT_DYNAMIC(Cdocgia, CDialog)

Cdocgia::Cdocgia(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DOCGIA, pParent)
{

}
Cdocgia::Cdocgia(CWnd* pParent, CString str)
	: CDialog(IDD_DOCGIA, pParent)
{
	tensys = str;
}


Cdocgia::~Cdocgia()
{
}

void Cdocgia::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, edit_docgia_tensys);
	DDX_Control(pDX, IDC_THONGBAODOCGIA, edit_thongbaodocgia);
}

BOOL Cdocgia::OnInitDialog()
{
	CDialog::OnInitDialog();
	using namespace std;
	fstream f1, f2;
	CT2CA d(tensys);
	string abc(d);
	string tenfile = "E:\\data\\khachhangmuonsach\\" + abc + ".txt";
	f1.open(tenfile, ios::in);
	string data = "", line;
	while (!f1.eof())
	{
		getline(f1, line);
		if (line != "")
		{
			string ms = tok(line);
			string a = tok(line);// Lấy tên môn học 
			string c = tok(line);//Lấy số lượng
			string the = line;
			string d = tok_ngay(the);//Lấy tháng
			string e = tok_ngay(the);//Lấy ngày the là năm
			int thang = stoi(d);
			int nam = stoi(the);
			if (thang +  5 <=12 )
			{
				string b ="Ma so: " + ms + ", Ten sach: " + a + " co so luong: " + c + " se het han vao: " + to_string(thang + 5) + "/" + e +"/"+ the + "\r\n";
				data = data + b;
			}
			else
			{
				string b = "Ma so: " + ms + ", Ten sach: " + a + " co so luong: " + c + " se het han vao: " + to_string(thang - 12 + 5) + "/" + e + "/" + the + "\r\n";
				data = data + b;
			}
		}

	}
	f1.close();
	CString z(data.c_str());
	edit_thongbaodocgia.SetWindowText(z);
	edit_docgia_tensys.SetWindowText(tensys);
	f1.close();
	return TRUE;
}
BEGIN_MESSAGE_MAP(Cdocgia, CDialog)
	ON_EN_CHANGE(IDC_THONGBAODOCGIA, &Cdocgia::OnEnChangeThongbaoqlnd)
	ON_BN_CLICKED(IDC_DOCGIA_MUONSACH, &Cdocgia::OnBnClickedDocgiaMuonsach)
	ON_BN_CLICKED(IDC_DOCGIA_TRASACH, &Cdocgia::OnBnClickedDocgiaTrasach)
	ON_BN_CLICKED(IDC_DOCGIA_THONGTIN, &Cdocgia::OnBnClickedDocgiaThongtin)
	ON_BN_CLICKED(IDC_DOCGIA_TRASACH2, &Cdocgia::OnBnClickedDocgiaTrasach2)
END_MESSAGE_MAP()


// Cdocgia message handlers


void Cdocgia::OnEnChangeThongbaoqlnd()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Cdocgia::OnBnClickedDocgiaMuonsach()
{
	// TODO: Add your control notification handler code here
	Cycms th(NULL, tensys); //
	th.DoModal();
}


void Cdocgia::OnBnClickedDocgiaTrasach()
{
	// TODO: Add your control notification handler code here
	Cdocgia_trasach1 th(NULL, tensys); //
	th.DoModal();
}


void Cdocgia::OnBnClickedDocgiaThongtin()
{
	// TODO: Add your control notification handler code here
	Cdocgiathongbao th(NULL, tensys); //
	th.DoModal();
}


void Cdocgia::OnBnClickedDocgiaTrasach2()
{
	// TODO: Add your control notification handler code here
	Cdocgia_dmk th(NULL, tensys); //
	th.DoModal();
}
