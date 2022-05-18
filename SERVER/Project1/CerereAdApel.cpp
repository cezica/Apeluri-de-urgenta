#include "CerereAdApel.h"

CerereAdApel::CerereAdApel(string u, string d, string i_a, string s_a, string f)
{
	user = u; dispecer = d; i_apel = i_a; s_apel = s_a; n_fis = f;
}

string CerereAdApel::verificare()
{
	if(B_D::create_Instance()->ad_apel(user, dispecer, i_apel, s_apel, n_fis)==true)
		return "v";
	return "x";
}
