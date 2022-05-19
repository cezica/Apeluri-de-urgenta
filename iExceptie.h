#pragma once 
#include <exception>
#include <string>
#include <iostream>
using namespace std;

__interface iExceptie
{
	virtual void sendError(int errorNumber) = 0;
	virtual string getErrorMessage() = 0;
	virtual int getErrorCode() = 0;
};