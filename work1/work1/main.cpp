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

// 编码
string encodeMsg(Codec* codec) {
	return codec->encodeMsg();
}
// 解码
void* decodeMsg(Codec* codec) {
	return codec->decodeMsg();
}

int main()
{
	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.serverID = "Luffy";
	reqInfo.data = "我是要成为黑贼王的男人";
	reqInfo.sign = "haha呵呵嘿嘿";

	//Request req(&reqInfo);
	// 使用工厂创建Request
	RequestFactory* reqFactory = new RequestFactory(&reqInfo);
	Request* req = (Request*)reqFactory->createCodec();
	// 编码
	string reqmsg = encodeMsg(req);
	// 解码
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
	repInfo.clientID = "我是小明";
	repInfo.serverID = "我是小明的秘书";
	repInfo.data = "我带了小明的钥匙";
	repInfo.status = 1;
	repInfo.seckeyID = 9527;

	RespondFactory* repFactory = new RespondFactory(&repInfo);
	Response* rep =(Response*) repFactory->createCodec();
	string repmsg = encodeMsg(rep);
	// 解码
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