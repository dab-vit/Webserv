#ifndef PARSE_SPECIFIC_HEADER_HPP
# define PARSE_SPECIFIC_HEADER_HPP

//#include <iostream>
#include "general_structs.hpp"
#include "Host.hpp"
//#include "ContentLength.hpp"
//#include "Connection.hpp"

class ParseSpecificHeader
{
	public:
	Host		host;
//	ContentLength	content_length;
//	Connection	conn;

	ParseSpecificHeader(void);
	~ParseSpecificHeader(void);
	ParseSpecificHeader(const ParseSpecificHeader& a);
	ParseSpecificHeader&	operator=(const ParseSpecificHeader& a);

	int	parseSpecificHeader(std::string& value_str, int type);
};

#endif //PARSE_SPECIFIC_HEADER_HPP
