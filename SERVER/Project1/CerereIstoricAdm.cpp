#include "CerereIstoricAdm.h"

CerereIstoricAdm::CerereIstoricAdm()
{
}

string CerereIstoricAdm::verificare()
{
    return B_D::create_Instance()->istoric_adm();
}
