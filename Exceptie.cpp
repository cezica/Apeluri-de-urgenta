#include "Exceptie.h"

void Exceptie::chooseError()
{
	switch (this->code)
	{
	case 1:
		this->message = "Eroare 1: DATE INCORECTE";
		break;
	case 2:
		this->message = "Eroare 2: FISIER GOL";
		break;
	case 3:
		this->message = "Eroare 3: USERNAME EXISTENT";
		break;
	case 4:
		this->message = "Eroare 4: NUMARUL DE TELEFON EXISTENT";
		break;
	case 5:
		this->message = "Eroare 5: NU S-A DESCHIS FISIERUL";
		break;
	default:
		this->message = "Eroare necunoascuta!";
		break;
	}
}

void Exceptie::sendError(int errorNumber)
{
	this->code = errorNumber;
}

string Exceptie::getErrorMessage()
{
	return message;
}

int Exceptie::getErrorCode()
{
	return code;
}
