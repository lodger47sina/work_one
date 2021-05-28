#include "Response.h"
Response::Response()
{
}
std::string Response::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);
	return output;
}
void * Response::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}
Response::Response(string encstr)
{
	ititMessage(encstr);
}
Response::Response(ResponseInfo * info)
{
	initMessage(info);
}
void Response::ititMessage(string encstr)
{
	m_encStr = encstr;
}
void Response::initMessage(ResponseInfo * info)
{
	m_msg.set_data(info->data);
	m_msg.set_serverid(info->serverID);
	m_msg.set_seckeyid(info->seckeyID);
	m_msg.set_clientid(info->clientID);
	m_msg.set_rv(info->status);
}
Response::~Response()
{
}