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
	// 空对象
	Request();
	// 构造出的对象用于 解码 的场景
	Request(string encstr);
	// 构造出的对象用于 编码 场景
	Request(RequestInfo *info);
	// 解码使用
	void initMessage(string encstr);
	// 编码使用
	void initMessage(RequestInfo *info);
	// 重写的父类函数 -> 序列化函数
	string encodeMsg();
	// 重写的父类函数 -> 反序列化函数
	void* decodeMsg();
	~Request();
	

private:
	string m_encStr;
	RequestMsg m_msg;
};

