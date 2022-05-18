#pragma once
#include <iostream>
#include "Fisiere.h"

using namespace std;

__interface IProtocol
{
	virtual int get_eroare() = 0;
	virtual bool rezultat() = 0;
	virtual string get_raspuns() = 0;
};

