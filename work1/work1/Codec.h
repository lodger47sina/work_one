#pragma once
#include <iostream>
class Codec
{
public:
	Codec();
	// ����������->��̬
	virtual ~Codec();
	virtual std::string encodeMsg();
	virtual void* decodeMsg() ;
};


