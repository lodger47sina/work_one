#include "RequestFactory.h"

RequestFactory::RequestFactory(string enc)
{
	this->m_encStr = enc;
}

RequestFactory::RequestFactory(RequestInfo * info)
{
	this->m_info = info;
}

RequestFactory::~RequestFactory()
{
}

Codec * RequestFactory::createCodec()
{
	if (!this->m_encStr.empty()) {
		return new Request(this->m_encStr);
	}
	else if (NULL != this->m_info)
	{
		return new Request(this->m_info);
	}
	else
	{
		return new Request;
	}
	
}
