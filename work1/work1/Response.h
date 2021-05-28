#pragma once
#include "Codec.h"
#include <iostream>
#include "Message.pb.h"
using namespace std;

struct ResponseInfo {
	int status;
	int seckeyID;
	string clientID;
	string serverID;
	string data;
};

class Response :
	public Codec
{
public:
	Response();
	Response(string encstr);
	Response(ResponseInfo *info);
	void ititMessage(string encstr);
	void initMessage(ResponseInfo *info);
	string encodeMsg();
	void* decodeMsg();
	~Response();

private:
	string m_encStr;
	// Ҫ���л���������������У�ͨ�������������л�����
	RespondMsg m_msg;
};



