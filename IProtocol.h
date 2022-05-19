#pragma once
#include <iostream>
#include "Fisiere.h"

using namespace std;

__interface IProtocol
{
	virtual int obtine_eroare() = 0;
	virtual void rezultat() = 0;
	virtual string obtine_raspuns() = 0;
};

