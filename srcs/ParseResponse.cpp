#include "ParseResponse.hpp"

ParseResponse::ParseResponse(void): _response_str(""), _reference_str(REF), _status_line(""), _body("")
{
}

ParseResponse::~ParseResponse(void)
{
}

ParseResponse::ParseResponse(const ParseResponse& r): _response_str(r._response_str), _reference_str(REF), _status_line(r._status_line), _heads(r._heads), _body(r._body)
{
}

ParseResponse&	ParseResponse::operator=(const ParseResponse& r)
{
	_response_str = r._response_str;
	_reference_str = REF;
	_status_line = r._status_line;
	_heads = r._heads;
	_body = r._body;
	return (*this);
}

void	ParseResponse::setStatusLine(const std::string& status_line)
{
	_status_line = status_line;
}

void	ParseResponse::setHeaders(const std::list<std::string>& headers)
{
	_heads = headers;
}

void	ParseResponse::setBody(const std::string& body)
{
	_body = body;
}

void	ParseResponse::setResponseStr(const std::string& response)
{
	_response_str = response;
}

void	ParseResponse::joinStatusLine(std::string& response)
{
	response = _status_line;
	response += _reference_str;
}

void	ParseResponse::joinHeaders(std::string& response)
{
	std::list<std::string>::const_iterator	it;

	it = _heads.begin();
	while (it != _heads.end())
	{
		response += *it++;
		response += _reference_str;
	}
	response += _reference_str; 
}

void	ParseResponse::joinBody(std::string& response)
{
	response += _body;
}

int	ParseResponse::parseResponse(void)
{
	std::string	response;

	response = "";
	try
	{
		joinStatusLine(response);
		joinHeaders(response);
		joinBody(response);
	}
	catch(std::length_error& e)
	{
		std::cerr << LENGTH_ERROR << e.what() << std::endl;
		return (-2);
	}
	catch(std::bad_alloc& e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl;
		return (-2);
	}
	setResponseStr(response);
	return (0);
}

void	ParseResponse::print(void) const
{
	std::list<std::string>::const_iterator	it;
	size_t					i;

	it = _heads.begin();
	i = 1;
	std::cout << "RESPONSE" << std::endl;
	std::cout << "Response: " << _response_str << std::endl;
	std::cout << "Reference str: " << _reference_str << std::endl;
	std::cout << "Status line: " << _status_line << std::endl;
	std::cout << "Headers: " << std::endl;
	while (it != _heads.end())
	{
		std::cout << "Head " << i++ << ": " << *it++ << std::endl;
	}
	std::cout << "Body: " << _body << std::endl;
}
