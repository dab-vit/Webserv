#ifndef PARSE_REQUEST_HPP 
# define PARSE_REQUEST_HPP

#include <iostream>
#include <list>
#include "def.h"

class ParseRequest
{
	std::string		_request_str;
	std::string		_reference_str;
	std::string		_request_line;
	std::list<std::string>	_heads;	
	std::string		_body;

	public:
	ParseRequest(void);
	~ParseRequest(void);
	ParseRequest(const ParseRequest& p);
	ParseRequest& operator=(const ParseRequest& p);

	const std::string&		getRequestStr(void) const;
	const std::string&		getRequestLine(void) const;
	const std::list<std::string>	getHeaders(void) const;
	const std::string&      	getBody(void) const;

	void	setRequestStr(const std::string& request_str);

	int	parseRequest(void);
	int	parseRequestLine(size_t *pos, std::string& remaining_request_str);
	int	parseHeaders(size_t *pos, std::string& remaining_request_str);
	void	parseBody(size_t *pos, std::string& remaining_request_str, size_t body_length);
	void	print(void) const;
};

#endif //PARSE_REQUEST_HPP
