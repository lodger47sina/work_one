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
	reqInfo.data = "我是要成为黑贼王的男人";
	reqInfo.sign = "haha呵呵嘿嘿";

	//Request req(&reqInfo);
	// 使用工厂创建Request
	CodecFactory* factory = new RequestFactory(&reqInfo);
	Codec* codec = factory->createCodec();
	// 编码
	string str = codec->encodeMsg();
	cout << "编码: " << str << endl;
	delete factory;
	delete codec;
	// 解码
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
	repInfo.clientID = "我是小明";
	repInfo.serverID = "我是小明的秘书";
	repInfo.data = "我带了小明的钥匙";
	repInfo.status = 1;
	repInfo.seckeyID = 9527;

	factory = new RespondFactory(&repInfo);
	codec= factory->createCodec();
	str = codec->encodeMsg();
	cout << "编码:" << str << endl;
	delete factory;
	delete codec;
	// 解码
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