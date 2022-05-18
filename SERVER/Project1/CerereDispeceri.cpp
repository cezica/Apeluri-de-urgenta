#include "CerereDispeceri.h"

CerereDispeceri::CerereDispeceri()
{
}

string CerereDispeceri::verificare()
{
    return B_D::create_Instance()->dispeceri();
}
