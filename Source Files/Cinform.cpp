#include "Cinform.h"

BEGIN_MESSAGE_MAP(Cinform, CDialog)
	ON_BN_CLICKED(IDOK, &Cinform::OnBnClickedOk)
END_MESSAGE_MAP()


void Cinform::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
