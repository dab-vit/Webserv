#ifndef PARSE_RESPONSE_HPP
# define PARSE_RESPONSE_HPP

#include <iostream>
#include <list>
#include "def.h"

class ParseResponse
{
	std::string		_response_str;
	std::string		_reference_str;
	std::string		_status_line;
	std::list<std::string>	_heads;	
	std::string		_body;

	public:
	ParseResponse(void);
	~ParseResponse(void);
	ParseResponse(const ParseResponse& r);
	ParseResponse& operator=(const ParseResponse& r);

	void	setStatusLine(const std::string& status_line);
	void	setHeaders(const std::list<std::string>& headers);
	void	setBody(const std::string& body);
	void	setResponseStr(const std::string& response);

	int	parseResponse(void);
	void	joinStatusLine(std::string& response);
	void	joinHeaders(std::string& response);
	void	joinBody(std::string& response);
	void	saveResponse(std::string& response);
	void	print(void) const;
};

#endif //PARSE_RESPONSE_HPP
