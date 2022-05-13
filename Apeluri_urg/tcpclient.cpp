#include "tcpclient.h"
#include "qtcpsocket.h"
#include "qmessagebox.h"

tcpclient* tcpclient::instanta = nullptr;
QString tcpclient::citirestring;

bool tcpclient::readFlag = false;

tcpclient::tcpclient(QObject* parinte)
	:QObject{ parinte }
{

}

tcpclient& tcpclient::getInstance()
{
	if (tcpclient::instanta == nullptr)
	{
		instanta = new tcpclient();
	}
	//return instanta;
}

void tcpclient::destroyInstance()
{
	delete instanta;
}

QString tcpclient::raspuns(QString mesaj)
{
    //if (socket->isWritable())
    //{

    //}
}
