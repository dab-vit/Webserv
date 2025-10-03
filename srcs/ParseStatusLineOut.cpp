#include "ParseStatusLineOut.hpp"

ParseStatusLineOut::ParseStatusLineOut(): _server_http_version(VER)
{
}	

ParseStatusLineOut::~ParseStatusLineOut()
{
}	

ParseStatusLineOut::ParseStatusLineOut(const ParseStatusLineOut& a): _server_http_version(VER)
{
	(void) a;
}	

ParseStatusLineOut&	ParseStatusLineOut::operator=(const ParseStatusLineOut& a)
{
	(void) a;
	return (*this);
}

int	ParseStatusLineOut::takeReasonPhrase(int& status, std::string& reason_phrase, const std::map<int, std::string>& err)
{
	std::map<int, std::string>::const_iterator	it;

	if (!status)
		status = OK;
	it = err.find(status);
	if (it == err.end())
		return (-1);
	else
		reason_phrase = it->second;
	return (0);
}		

std::string	ParseStatusLineOut::uintToString(unsigned int num, int base)
{
	char		digit;
	std::string	status_str;
	
	digit = (num % base) + '0';
	num = num / base;
	if (num > 0)
		status_str = uintToString(num, 10);
	status_str.append(1, digit);
	return (status_str);
}
	
int	ParseStatusLineOut::parseStatusLineOut(ParseResponse& res, int& status, const std::map<int, std::string>& err)
{
	std::string	status_line;
	std::string	reason_phrase;
	std::string	line;
	if (takeReasonPhrase(status, reason_phrase, err))
	{
		status = INTERNAL_SERVER_ERROR;
		reason_phrase = INTERNAL_SERVER_ERROR_PHRASE;
	}
	try
	{
		status_line = _server_http_version + REF2;
		status_line += uintToString(static_cast<unsigned int> (status), 10) + REF2;
		status_line += reason_phrase;
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl; 
		return (-1);
	}
	catch (std::length_error& e)
	{
		std::cerr << LENGTH_ERROR << e.what() << std::endl;
		return (-1);
	}
	res.setStatusLine(status_line);
	return (0);
}
