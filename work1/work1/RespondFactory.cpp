#include "RespondFactory.h"

RespondFactory::RespondFactory(string enc)
{
	m_flag = false;
	this->m_encStr = enc;
}

RespondFactory::RespondFactory(ResponseInfo * info)
{
	m_flag = true;
	this->m_info = info;
}

RespondFactory::~RespondFactory()
{
}

Codec * RespondFactory::createCodec()
{
	Codec* codec = NULL;
	if (!m_flag)
	{
		codec = new Response(this->m_encStr);
	}
	else
	{
		codec = new Response(this->m_info);
	}
		return codec;
}
