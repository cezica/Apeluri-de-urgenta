#include "CerereListaAsteptare.h"

CerereListaAsteptare::CerereListaAsteptare(string u)
{
	user_dispecer = u;
}

string CerereListaAsteptare::verificare()
{
	return B_D::create_Instance()->lista_asteptare(user_dispecer);
}
