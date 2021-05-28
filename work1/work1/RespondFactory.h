#pragma once
#include "CodecFactory.h"
#include "Response.h"
class RespondFactory :
	public CodecFactory
{
public:
	RespondFactory(string enc);
	RespondFactory(ResponseInfo *info);
	~RespondFactory();
	virtual Codec* createCodec();
private:
	bool m_flag;
	string m_encStr;
	ResponseInfo *m_info;
};

