#ifndef PARSE_BODY_OUT_HPP
# define PARSE_BODY_OUT_HPP

#include <iostream>
#include "ParseResponse.hpp"
#include "ParseStatusLineOut.hpp"

class ParseBodyOut
{
	std::string	_target_path;
//	int		_connection_fd; No está aquí sino en ParseResponse
	std::string	_body;

	public:
	ParseBodyOut();
	~ParseBodyOut();
	ParseBodyOut(const ParseBodyOut& a);
	ParseBodyOut&	operator=(const ParseBodyOut& a);

	void	setTargetPath(std::string& target_path);

	int	parseBodyOut(int status, const ParseResponse& res, ParseStatusLineOut& res_status_line);
	void	obtainErrorPath(int status);
	int     modifyResponse(int status, const ParseResponse& res, ParseStatusLineOut& res_status_line);
	int	obtainBody(int status, const ParseResponse& res, ParseStatusLineOut& res_status_line);	
//		openFile
//	readFileInStream
//	passStreamToString
//	saveStringIntoParseResponse
};

#endif //PARSE_BODY_OUT_HPP
