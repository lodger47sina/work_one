#pragma once
#include "Codec.h"
#include <iostream>
#include "Message.pb.h"

using namespace std;

struct RequestInfo {
	int cmd;
	string clientID;
	string serverID;
	string sign;
	string data;
};

class Request :
	public Codec
{
public:
	// �ն���
	Request();
	// ������Ķ������� ���� �ĳ���
	Request(string encstr);
	// ������Ķ������� ���� ����
	Request(RequestInfo *info);
	// ����ʹ��
	void initMessage(string encstr);
	// ����ʹ��
	void initMessage(RequestInfo *info);
	// ��д�ĸ��ຯ�� -> ���л�����
	string encodeMsg();
	// ��д�ĸ��ຯ�� -> �����л�����
	void* decodeMsg();
	~Request();
	

private:
	string m_encStr;
	RequestMsg m_msg;
};

