#pragma once

#ifndef	TCPCLIENT_H
#define TCPCLIENT_H

#include <qobject.h>

class QTcpSocket;

class tcpclient : public QObject
{
	Q_OBJECT
public:
	static tcpclient& getInstance();
	static void destroyInstance();

	void porneste(QString ip, unsigned short port);
	void opreste();

	QString raspuns(QString r);

private slots:
	QString readyRead();

private:
	static tcpclient* instanta;
	static QString citirestring;
	static bool readFlag;

	explicit tcpclient(QObject* parent = nullptr);
};

#endif 