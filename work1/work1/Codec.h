#pragma once
#include <iostream>
class Codec
{
public:
	Codec();
	// –ÈŒˆππ∫Ø ˝->∂‡Ã¨
	virtual ~Codec();
	virtual std::string encodeMsg();
	virtual void* decodeMsg() ;
};


