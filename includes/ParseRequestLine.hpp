#ifndef PARSE_REQUEST_LINE_HPP
# define PARSE_REQUEST_LINE_HPP

#include <iostream>
#include <list>
#include <vector>
#include "def.h"

class ParseRequestLine
{
	std::string	_method_str;
	int		_method;
	std::string	_reference_str;
	std::string	_request_target;
	std::string	_http_rcvd_version;

	public:
	ParseRequestLine(void);
	~ParseRequestLine(void);
	ParseRequestLine(const ParseRequestLine& p);
	ParseRequestLine& operator=(const ParseRequestLine& p);

	const std::string&	getMethodStr(void) const;
	int			getMethod(void) const;
	const std::string&	getRequestTarget(void) const;
	const std::string&      getHttpRcvdVersion(void) const;

	int	parseRequestLine(const std::string& request, const std::vector<std::string>& vec);
	int     parseRequestLineField(size_t& pos, std::string& remaining_request_str, int option, const std::vector<std::string>& vec);
	void	parseHttpRcvdVersion(std::string& remaining_request_str);
	void    assignValueToField(const std::string& value, int option, const std::vector<std::string>& vec);
	void	print(void) const;
};

#endif //PARSE_REQUEST_LINE_HPP
