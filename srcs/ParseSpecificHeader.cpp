#include "ParseSpecificHeader.hpp"

ParseSpecificHeader::ParseSpecificHeader(void)
{}	

ParseSpecificHeader::~ParseSpecificHeader(void)
{}	

ParseSpecificHeader::ParseSpecificHeader(const ParseSpecificHeader& a)
{
	(void) a;
}	

ParseSpecificHeader&	ParseSpecificHeader::operator=(const ParseSpecificHeader& a)
{
	(void) a;	
	return (*this);
}

int	ParseSpecificHeader::parseSpecificHeader(std::string& value_str, int type)
{
	int	code;

	code = 0;
	switch (type)
	{
		case host_type:
			code = host.parseHost(value_str);
			break;
/*		case content_length_type:
			code = content_length.parseContentLength(value_str);
			break;
		case connection_type:
			code = conn.parseConnection(value_str);
			break;
*/		default:
			break;
	}
	return (code);
}
