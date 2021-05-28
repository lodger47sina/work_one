#include "RespondFactory.h"

RespondFactory::RespondFactory(string enc)
{
	this->m_encStr = enc;
}

RespondFactory::RespondFactory(ResponseInfo * info)
{
	this->m_info = info;
}

RespondFactory::~RespondFactory()
{
}

Codec * RespondFactory::createCodec()
{
	if (!this->m_encStr.empty())
	{
		return new Response(this->m_encStr);
	}
	else if (NULL != this->m_info)
	{
		return new Response(this->m_info);
	}
	else {
		return new Response;
	}
	
}
