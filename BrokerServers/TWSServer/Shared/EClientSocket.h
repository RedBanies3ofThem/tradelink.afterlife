/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#ifndef eclientsocket_def
#define eclientsocket_def

#ifndef DLLEXP
#define DLLEXP
#endif

#include "EClientSocketBase.h"

#include <memory>

class EWrapper;

class DLLEXP EClientSocket : public EClientSocketBase
{
	class MySocket;
public:

	explicit EClientSocket( EWrapper *ptr);
	~EClientSocket();

	// override virtual funcs from EClient
	bool eConnect( const char *host, UINT port, int clientId=0);
	void eDisconnect();

private:

	int send(const char* buf, size_t sz);
	int receive(char* buf, size_t sz);

public: // dimon?
	// callback from socket
	void onConnect(int i);
	void onReceive(int i);
	void onSend(int i);
	void onClose(int i);
private: // dimon?

	// helper
	bool handleSocketError(int i);

	bool isSocketOK() const;

private:

	std::auto_ptr<MySocket> m_pSocket;
};

#endif
