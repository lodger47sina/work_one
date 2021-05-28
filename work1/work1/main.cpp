#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Message.pb.h"
/*
#include "Request.h"
#include "Response.h"
*/
#include "CodecFactory.h"
#include "RequestFactory.h"
#include "RespondFactory.h"
using namespace std;



int main()
{
	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.serverID = "Luffy";
	reqInfo.data = "����Ҫ��Ϊ������������";
	reqInfo.sign = "haha�ǺǺٺ�";

	//Request req(&reqInfo);
	// ʹ�ù�������Request
	CodecFactory* factory = new RequestFactory(&reqInfo);
	Codec* codec = factory->createCodec();
	// ����
	string str = codec->encodeMsg();
	cout << "����: " << str << endl;
	delete factory;
	delete codec;
	// ����
	factory = new RequestFactory(str);
	codec = factory->createCodec();
	RequestMsg* reqMsg = (RequestMsg*)codec->decodeMsg();
	cout << "cmdtype: " << reqMsg->cmdtype()
		<< ", clientID: " << reqMsg->clientid()
		<< ", serverID: " << reqMsg->serverid()
		<< ", data: " << reqMsg->data()
		<< ", sign: " << reqMsg->sign()
		<< endl;
	delete factory;
	delete codec;

	cout << "===========================" << endl;
	ResponseInfo repInfo;
	repInfo.clientID = "����С��";
	repInfo.serverID = "����С��������";
	repInfo.data = "�Ҵ���С����Կ��";
	repInfo.status = 1;
	repInfo.seckeyID = 9527;

	factory = new RespondFactory(&repInfo);
	codec= factory->createCodec();
	str = codec->encodeMsg();
	cout << "����:" << str << endl;
	delete factory;
	delete codec;
	// ����
	factory = new RespondFactory(str);
	codec =factory->createCodec();
	RespondMsg* repMsg = (RespondMsg*)codec->decodeMsg();
	cout << "cientid: " << repMsg->clientid()
		<< ", serverid: " << repMsg->serverid()
		<< ", seckeyid: " << repMsg->seckeyid()
		<< ", rv: " << repMsg->rv()
		<< endl;
	delete factory;
	delete codec;
	return 0;
}