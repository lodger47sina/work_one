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

// ����
string encodeMsg(Codec* codec) {
	return codec->encodeMsg();
}
// ����
void* decodeMsg(Codec* codec) {
	return codec->decodeMsg();
}

int main()
{
	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.serverID = "Luffy";
	reqInfo.data = "����Ҫ��Ϊ������������";
	reqInfo.sign = "haha�ǺǺٺ�";

	//Request req(&reqInfo);
	// ʹ�ù�������Request
	RequestFactory* reqFactory = new RequestFactory(&reqInfo);
	Request* req = (Request*)reqFactory->createCodec();
	// ����
	string reqmsg = encodeMsg(req);
	// ����
	reqFactory = new RequestFactory(reqmsg);
	Request* req1 = (Request*)reqFactory->createCodec();
	RequestMsg* reqMsg = (RequestMsg*)decodeMsg(req1);
	cout << "cmdtype: " << reqMsg->cmdtype()
		<< ", clientID: " << reqMsg->clientid()
		<< ", serverID: " << reqMsg->serverid()
		<< ", data: " << reqMsg->data()
		<< ", sign: " << reqMsg->sign()
		<< endl;
	
	ResponseInfo repInfo;
	repInfo.clientID = "����С��";
	repInfo.serverID = "����С��������";
	repInfo.data = "�Ҵ���С����Կ��";
	repInfo.status = 1;
	repInfo.seckeyID = 9527;

	RespondFactory* repFactory = new RespondFactory(&repInfo);
	Response* rep =(Response*) repFactory->createCodec();
	string repmsg = encodeMsg(rep);
	// ����
	repFactory = new RespondFactory(repmsg);
	Response* resp1 =(Response*)repFactory->createCodec();
	RespondMsg* repMsg = (RespondMsg*)decodeMsg(resp1);
	cout << "cientid: " << repMsg->clientid()
		<< ", serverid: " << repMsg->serverid()
		<< ", seckeyid: " << repMsg->seckeyid()
		<< ", rv: " << repMsg->rv()
		<< endl;
	return 0;
}