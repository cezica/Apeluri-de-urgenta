#pragma once
#include "iExceptie.h"

class Exceptie : public iExceptie
{
private:
	int code;
	string message;

	void chooseError();

public:
	void sendError(int errorNumber);
	string getErrorMessage();
	int getErrorCode();

	Exceptie(int errorCode)
	{
		this->code = errorCode;
		chooseError();
	}
	virtual ~Exceptie() {}
};

