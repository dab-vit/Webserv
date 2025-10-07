#ifndef PARSE_BODY_OUT_HPP
# define PARSE_BODY_OUT_HPP

#include <iostream>
#include <fstream>
#include "ParseResponse.hpp"
#include "ParseStatusLineOut.hpp"

class ParseBodyOut
{
	std::string	_target_path;
//	int		_connection_fd; No está aquí sino en ParseResponse
	std::string	_body_str;

	public:
	ParseBodyOut();
	~ParseBodyOut();
	ParseBodyOut(const ParseBodyOut& a);
	ParseBodyOut&	operator=(const ParseBodyOut& a);

	void	setTargetPath(std::string& target_path);

	int	parseBodyOut(int status, ParseResponse& res, ParseStatusLineOut& res_status_line, const std::map<int, std::string>& err);
	void	obtainErrorPath(int status);
	int     modifyResponse(int status, ParseResponse& res, ParseStatusLineOut& res_status_line, const std::map<int, std::string>& err);
	int	obtainBody(int status, ParseResponse& res, ParseStatusLineOut& res_status_line, const std::map<int, std::string>& err);	
//		openFile
//	readFileInStream
//	passStreamToString
//	saveStringIntoParseResponse
};

#endif //PARSE_BODY_OUT_HPP
