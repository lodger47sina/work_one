#include "RequestFactory.h"

RequestFactory::RequestFactory(string enc)
{
	m_flag = false;
	this->m_encStr = enc;
}

RequestFactory::RequestFactory(RequestInfo * info)
{
	m_flag = true;
	this->m_info = info;
}

RequestFactory::~RequestFactory()
{
}

Codec * RequestFactory::createCodec()
{
	Codec* codec = NULL;
	if (!m_flag) {
		codec =  new Request(this->m_encStr);
	}
	else
	{
		codec =  new Request(this->m_info);
	}
		return codec;	
}
