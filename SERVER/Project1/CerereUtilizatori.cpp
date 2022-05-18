#include "CerereUtilizatori.h"

CerereUtilizatori::CerereUtilizatori()
{
}

string CerereUtilizatori::verificare()
{
    return B_D::create_Instance()->utilizatori();
}
