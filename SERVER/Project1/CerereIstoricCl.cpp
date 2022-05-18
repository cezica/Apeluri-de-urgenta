#include "CerereIstoricCl.h"

CerereIstoricCl::CerereIstoricCl(string u)
{
	user = u;
}

string CerereIstoricCl::verificare()
{
	return B_D::create_Instance()->istoric_cl(user);
}
