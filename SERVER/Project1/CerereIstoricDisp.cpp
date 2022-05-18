#include "CerereIstoricDisp.h"

CerereIstoricDisp::CerereIstoricDisp(string u_d)
{
	user_dispecer = u_d;
}

string CerereIstoricDisp::verificare()
{
	return B_D::create_Instance()->istoric_disp(user_dispecer);
}
