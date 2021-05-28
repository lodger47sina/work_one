#include "CodecFactory.h"

CodecFactory::CodecFactory()
{
}

CodecFactory::~CodecFactory()
{
}

Codec * CodecFactory::createCodec()
{
	return new Codec;
}
