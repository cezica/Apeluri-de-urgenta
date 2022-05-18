#include "CerereAdDetalii.h"

CerereAdDetalii::CerereAdDetalii(string u, string n, string det)
{
	u_d = u; s_apel = n; detalii = det;
}

string CerereAdDetalii::verificare()
{
	if(B_D::create_Instance()->ad_detalii(u_d,s_apel,detalii)==true) return "v";
	return "x";
}
