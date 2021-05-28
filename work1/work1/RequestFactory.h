#pragma once
#include "CodecFactory.h"
#include "Request.h"
#include <string>

class RequestFactory :
	public CodecFactory
{
public:
	RequestFactory(string enc);
	RequestFactory(RequestInfo *info);
	~RequestFactory();
	virtual Codec* createCodec();
private:
	bool m_flag;
	string m_encStr;
	RequestInfo *m_info;
};

