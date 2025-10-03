#include "CheckRcvdRequest.hpp"

CheckRcvdRequest::CheckRcvdRequest(): _reference_str(REF)
{
}	

CheckRcvdRequest::~CheckRcvdRequest()
{
}	

CheckRcvdRequest::CheckRcvdRequest(const CheckRcvdRequest& a): _reference_str(REF)
{
	(void) a;
}	

CheckRcvdRequest&	CheckRcvdRequest::operator=(const CheckRcvdRequest& a)
{
	(void) a;
	return (*this);
}

int	CheckRcvdRequest::checkAsciiCharacters(const std::string& request) const
{
	size_t	i;

	i = 0;
	while (i < request.size())
	{
		if (!(0 <= request[i] && request[i] <= 126))
			return (-1);
		i++;
	}
	return (0);
}	

int	CheckRcvdRequest::checkStartHeaderWhitespace(const std::string& request) const
{
	size_t	pos;

	pos = request.find_first_of(_reference_str);
	if (pos == std::string::npos)
		return (-1);
	else
	{
		if (isspace(static_cast<unsigned char> (request[pos - 1])))
			return (-1);
		if (isspace(static_cast<unsigned char> (request[pos + 1])))
			return (-1);
	}
	return (0);
}

int     CheckRcvdRequest::checkRcvdRequest(const std::string& request) const
{
	if (checkAsciiCharacters(request))
		return (BAD_REQUEST);	
	if (checkStartHeaderWhitespace(request))
		return (BAD_REQUEST);
	return (0);
}
