#include "Exceptie.h"

Exceptie::Exceptie(int errorCode)
{
	this->code = errorCode;
	chooseError();
}
