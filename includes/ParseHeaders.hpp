#ifndef PARSE_HEADERS_HPP
# define PARSE_HEADERS_HPP

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <list>
#include <cctype>
#include "def.h"
#include "general_structs.hpp"
#include "ParseSpecificHeader.hpp"

class ParseHeaders
{
	public:
	ParseHeaders();
	~ParseHeaders();
	ParseHeaders(const ParseHeaders& a);
	ParseHeaders&	operator=(const ParseHeaders& a);

	void	removeWhiteSpace(std::string& head_value_str);
	int	obtainHeadNameAndValue(std::list<std::string>::const_iterator it, std::string& head_name, std::string& head_value_str);
	int     checkWhiteSpaceBeforeDots(const std::string& head_name);
	int	translateHeadersListToMap(const std::list<std::string>& headers, std::map<std::string, std::string>& heads_map);
	int     compareNameInsensitiveCase(const std::string& name, const std::deque<std::string>& heads_types);
	int	parseSpecificHeader(std::string& value_str, size_t type, ParseSpecificHeader& specific_header);
	int	selectHeaderAndParse(std::map<std::string, std::string>& heads_map, const t_definitions& def, ParseSpecificHeader& specific_header);
	int	parseHeaders(const std::list<std::string>& headers, t_definitions& def, ParseSpecificHeader& specific_header);
};

#endif //PARSE_HEADERS_HPP
