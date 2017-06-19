
// Primary2Dlg.cpp : implementation file
//
#pragma once
#include "stdafx.h"
#include "Primary2.h"
#include "Primary2Dlg.h"
#include "afxdialogex.h"
#include "SecondDlg.h"
#include "ThirdDlg.h"
#include "Cdangkimoi.h"
#include "Cdocgia.h"
#include "Cthuthu.h"
#include "Cqlnd.h"
#include "Cthongbaokhoatk.h"
#include "Cthuthu_timkiem.h"
#include "Csaimatkhau.h"

#include "Cthemvaitro.h"
//#include "Cbienphu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//std::string tensys;

// CPrimary2Dlg dialog



CPrimary2Dlg::CPrimary2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRIMARY2_DIALOG, pParent)
	, edit_doc_gia(0)
	, edit_thu_thu(0)
	, edit_quan_li_nguoi_dung(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrimary2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_THIRD_BTN, edit_timkiem);
	DDX_Control(pDX, IDC_EDIT1, edit_tendangnhap);
	DDX_Control(pDX, IDC_EDIT2, edit_matkhau);
	DDX_Check(pDX, IDC_DOCGIA, edit_doc_gia);
	DDX_Check(pDX, IDC_THUTHU, edit_thu_thu);
	DDX_Check(pDX, IDC_QLND, edit_quan_li_nguoi_dung);


	//DDX_Check(pDX, IDC_THUTHU, edit_doc_gia);

}

BEGIN_MESSAGE_MAP(CPrimary2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SECOND_BTN, &CPrimary2Dlg::OnBnClickedSecondBtn)
	/*ON_BN_CLICKED(IDC_BUTTON1, &CPrimary2Dlg::OnBnClickedButton1)*/
	ON_BN_CLICKED(IDD_THIRD_BTN, &CPrimary2Dlg::OnBnClickTimkiem)
	ON_BN_CLICKED(IDCANCEL, &CPrimary2Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_dangkimoi, &CPrimary2Dlg::OnBnClickeddangkimoi)
	ON_BN_CLICKED(IDC_dangkimoi2, &CPrimary2Dlg::OnBnClickeddangkimoi2)
	ON_BN_CLICKED(IDC_BUTTON2, &CPrimary2Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CPrimary2Dlg message handlers
// khởi tạo mặc định
BOOL CPrimary2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	edit_doc_gia = 1;
	edit_thu_thu = 0;
	edit_quan_li_nguoi_dung = 0;

	UpdateData(FALSE);
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPrimary2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPrimary2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPrimary2Dlg::OnBnClickedSecondBtn()
{
	// TODO: Add your control notification handler code here
	CSecondDlg Dlg;

	Dlg.DoModal();
}


void CPrimary2Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}


//void CPrimary2Dlg::OnBnClickedThirdBtn()
//{
//	// TODO: Add your control notification handler code here
//	CThirdDlg Dlg;
//
//	Dlg.DoModal();
//}
void CPrimary2Dlg::OnBnClickTimkiem()
{
	Cthuthu_timkiem Dlg;
	Dlg.DoModal();
}

void CPrimary2Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CPrimary2Dlg::OnBnClickeddangkimoi()
{
	// TODO: Add your control notification handler code here
	Cdangkimoi Dlg1;
	Dlg1.DoModal();
}


void CPrimary2Dlg::OnBnClickeddangkimoi2() // ham nay la ham them tinh nang
{
	Cthemvaitro Dlg2;
	Dlg2.DoModal();
	// TODO: Add your control notification handler code here
}

void CPrimary2Dlg::OnBnClickedButton2()
{
	using namespace std;
	UpdateData(TRUE);
	CString str_1;
	edit_tendangnhap.GetWindowText(str_1);
	CT2CA fsf(str_1);
	string tendangnhap(fsf);
	CString str_2;
	edit_matkhau.GetWindowText(str_2);
	CT2CA fg1(str_2);
	string matkhau(fg1);

	fstream ff1;
	ff1.open("E:\\data\\tttk.txt", ios::in);
	string line;
	string a, b, c, tendn, mk;
	int check = 0;
	while (!ff1.eof())
	{
		getline(ff1, line);
		if (line == "") continue;
		else
		{
			a = tok(line); // maso
			b = tok(line); // tt
			c = tok(line); // 0 hoac 1
			tendn = tok(line);
			//mk = tok(line);
			mk = line;
			if (tendn == tendangnhap&&mk == matkhau&&c == "1")// kiem tra
			{
				check = 1;
				if (edit_doc_gia == 1)
				{
					Cdocgia dg1(NULL, str_1);
					dg1.DoModal();
					//break;
				}
				else
				{
					// kiem tra truong hop dang nhap voi vai tro thu thu hoac qlnd
					fstream fff1;
					fff1.open("E:\\data\\ttanhxa.txt", ios::in);
					string trs;
					string ten, role;
					while (!fff1.eof()) // cho nay co van de
					{
						getline(fff1, trs);
						ten = tok(trs);
						role = trs;
						if (ten == tendangnhap)
						{

							if (edit_thu_thu == 1 && role == "thuthu")
							{
								Cthuthu dg2(NULL, str_1);
								dg2.DoModal();
							}
							else if (edit_quan_li_nguoi_dung == 1 && role == "qlnd")
							{
								//CString ss(_T("abc"));
								Cqlnd dg3(NULL, str_1); // str_1 la ten dang nhap

								dg3.DoModal();
							}
							// else thong bao ko co vai tro
						}
					}
					fff1.close();
				}
				//Cthongbaothemvaitro dlg11;// thong bao ok;
				//dlg11.DoModal();
				break;



			}
			else if (tendn == tendangnhap&&mk == matkhau&&c == "0")
			{
				check = 1;
				//Cqlnd dg3(NULL, str_1); // str_1 la ten dang nhap
				//dg3.DoModal();
				Cthongbaokhoatk dg15;
				dg15.DoModal();
				break;

			}
			else continue;



		}
	}
	ff1.close();
	if (check == 0)
	{
		Csaimatkhau sg1;
		sg1.DoModal();
	}
}
//fstream ff1;
//ff1.open("E:\\data\\tttk.txt", ios::in);
//string line;
//string a, b, c, tendn, mk;
//int check = 0;
//while (!ff1.eof())
//{
//	getline(ff1, line);
//	if (line == "") continue;
//	else
//	{
//		a = tok(line); // maso
//		b = tok(line); // tt
//		c = tok(line); // 0 hoac 1
//		tendn = tok(line);
//		mk = tok(line);
//		if (tendn == tendangnhap&&mk == matkhau&&c == "1")// kiem tra
//		{
//			check = 1;
//			//tensys = tendangnhap;
//			fstream fff1;
//			fff1.open("E:\\data\\ttanhxa.txt", ios::in);
//			string trs;
//			string ten, role;
//			while (!fff1.eof())  // cho nay co van de
//			{
//				getline(fff1, trs);
//				ten = tok(trs);
//				role = trs;
//				if (ten == tendangnhap)
//				{
//
//					if (edit_doc_gia == 1)
//					{
//						Cdocgia dg1(NULL, str_1);
//						dg1.DoModal();
//						break;
//					}
//					else if (edit_thu_thu == 1 && role == "thuthu")
//					{
//						Cthuthu dg2(NULL, str_1);
//						dg2.DoModal();
//					}
//					else if (edit_quan_li_nguoi_dung == 1 && role == "qlnd")
//					{
//						//CString ss(_T("abc"));
//						Cqlnd dg3(NULL, str_1); // str_1 la ten dang nhap
//
//						dg3.DoModal();
//					}
//				}
//
//			}
//			fff1.close();
//			//Cthongbaothemvaitro dlg11;// thong bao ok;
//			//dlg11.DoModal();
//			break;
//		}
//		else if (tendn == tendangnhap && mk == matkhau && c == "0")
//		{
//			check = 1;
//			Cthongbaokhoatk abc;
//			abc.DoModal();
//		}
//
//		else continue;
//
//	}
//}
//ff1.close();
//if (check == 0)
//{
//	Csaimatkhau sg1;
//	sg1.DoModal();
//}



/*UpdateData(TRUE);
if (edit_doc_gia == 1)
{
Cdocgia dg1;
dg1.DoModal();
}
else if (edit_thu_thu == 1)
{
Cthuthu dg2;
dg2.DoModal();
}
else if (edit_quan_li_nguoi_dung == 1)
{
Cqlnd dg3;
dg3.DoModal();
}
UpdateData(FALSE);*/
