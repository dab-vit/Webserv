#ifndef PARSE_STATUS_LINE_OUT_HPP
# define PARSE_STATUS_LINE_OUT_HPP

#include <iostream>
#include <string>
#include <map>
#include "def.h"
#include "ParseResponse.hpp"

class ParseStatusLineOut
{
	const std::string     _server_http_version;

	public:
	ParseStatusLineOut();
	~ParseStatusLineOut();
	ParseStatusLineOut(const ParseStatusLineOut& a);
	ParseStatusLineOut&	operator=(const ParseStatusLineOut& a);

	int	parseStatusLineOut(ParseResponse& res, int& status, const std::map<int, std::string>& err);
	int	takeReasonPhrase(int& status, std::string& reason_phrase, const std::map<int, std::string>& err);
	std::string	uintToString(unsigned int num, int base);
};

#endif //PARSE_STATUS_LINE_OUT_HPP
