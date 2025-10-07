#ifndef CHECK_RCVD_REQUEST_HPP
# define CHECK_RCVD_REQUEST_HPP

#include <string>
#include "def.h"

class CheckRcvdRequest
{
	const std::string     _reference_str;

	public:
	CheckRcvdRequest();
	~CheckRcvdRequest();
	CheckRcvdRequest(const CheckRcvdRequest& a);
	CheckRcvdRequest&	operator=(const CheckRcvdRequest& a);

	int     checkAsciiCharacters(const std::string& request) const;
	int     checkStartHeaderWhitespace(const std::string& request) const;
	int     checkRcvdRequest(const std::string& request) const;
};

#endif //CHECK_RCVD_REQUEST_HPP
