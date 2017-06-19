// Cqlnd_dstv.cpp : implementation file
//
#pragma
#include "stdafx.h"
#include "Primary2.h"
#include "Cqlnd_dstv.h"
#include "afxdialogex.h"
#include "SecondDlg.h"


// Cqlnd_dstv dialog

IMPLEMENT_DYNAMIC(Cqlnd_dstv, CDialog)

Cqlnd_dstv::Cqlnd_dstv(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QLND_DSTV, pParent)
{

}

Cqlnd_dstv::~Cqlnd_dstv()
{
}

void Cqlnd_dstv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_QLND_DSTV_TDN, edit_qlnd_dstv_tdn);
}


BEGIN_MESSAGE_MAP(Cqlnd_dstv, CDialog)
	
END_MESSAGE_MAP()

BOOL Cqlnd_dstv::OnInitDialog()
{
	CDialog::OnInitDialog();

	using namespace std;
	fstream ff1;
	string line, data = "";
	string data2;
	ff1.open("E:\\data\\tttk.txt", ios::in);
	string ms, tt, yn, tdn;
	while (!ff1.eof())
	{
		getline(ff1, line);
		if (line == "") continue;
		else
		{
			ms = tok(line);
			tt = tok(line);
			yn = tok(line);
			tdn = tok(line);
			data2 = tdn + " active " + yn + "\r\n";
			data += data2;
		}
	}
	ff1.close();

	CString cstr(data.c_str());
	edit_qlnd_dstv_tdn.SetWindowText(cstr);
	UpdateData(FALSE);
	return TRUE;
}
// Cqlnd_dstv message handlers



