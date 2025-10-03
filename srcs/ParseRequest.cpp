#include "ParseRequest.hpp"

ParseRequest::ParseRequest(void): _request_str(""), _reference_str(REF), _request_line(""), _body("")
{
}

ParseRequest::~ParseRequest(void)
{
}

ParseRequest::ParseRequest(const ParseRequest& p): _request_str(p._request_str), _reference_str(REF), _request_line(p._request_line), _heads(p._heads), _body(p._body)
{
}

ParseRequest&	ParseRequest::operator=(const ParseRequest& p)
{
	_request_str = p._request_str;
	_reference_str = REF;
	_request_line = p._request_line;
	_heads = p._heads;
	_body = p._body;
	return (*this);
}

const std::string&	ParseRequest::getRequestStr(void) const
{
	return (_request_str);
}

const std::string& ParseRequest::getRequestLine(void) const
{
	return (_request_line);
}
 
const std::list<std::string>   ParseRequest::getHeaders(void) const
{
	return (_heads);
}

const std::string& ParseRequest::getBody(void) const
{
	return (_body);
}

void	ParseRequest::setRequestStr(const std::string& request_str)
{
	_request_str = request_str;
}

int	ParseRequest::parseRequestLine(size_t *pos, std::string& remaining_request_str)
{
	*pos = _request_str.find(_reference_str);
	if (*pos && *pos != std::string::npos)
	{
		_request_line = _request_str.substr(0, *pos);
		remaining_request_str = _request_str.substr(*pos + _reference_str.size(), std::string::npos);
	}
	else
		return (-1);
	return (0);	
}

int	ParseRequest::parseHeaders(size_t *pos, std::string& remaining_request_str)
{
	std::string     header_str;

	while (*pos && *pos != std::string::npos)
	{
		*pos = remaining_request_str.find(_reference_str);
		if (*pos && *pos != std::string::npos)
		{
			header_str = remaining_request_str.substr(0, *pos);
			_heads.insert(_heads.end(), header_str);
			remaining_request_str = remaining_request_str.substr(*pos + _reference_str.size(), std::string::npos);
		}
	}
	if (*pos == std::string::npos)
		return (-1);
	return (0);
}

void	ParseRequest::parseBody(size_t *pos, std::string& remaining_request_str, size_t body_length)
{
	_body = remaining_request_str.substr(*pos + _reference_str.size(), body_length);
}

int	ParseRequest::parseRequest(void)
{
	size_t		pos;
	std::string	remaining_request_str;
	size_t		body_length = 10; //eliminar
	
	pos = 0;
	remaining_request_str = "";
	try
	{
		if (parseRequestLine(&pos, remaining_request_str))
			return (NOT_FOUND);
		if (parseHeaders(&pos, remaining_request_str))
			return (NOT_FOUND);
		parseBody(&pos, remaining_request_str, body_length);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << OUT_OF_RANGE << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	catch (std::length_error& e)
	{
		std::cerr << LENGTH_ERROR << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	return (0);
}

void	ParseRequest::print(void) const
{
	std::list<std::string>::const_iterator	it;
	size_t					i;

	it = _heads.begin();
	i = 1;
	std::cout << "REQUEST" << std::endl;
	std::cout << "Request received: " << _request_str << std::endl;
	std::cout << "Reference str: " << _reference_str << std::endl;
	std::cout << "Request line: " << _request_line << std::endl;
	std::cout << "Headers: " << std::endl;
	while (it != _heads.end())
	{
		std::cout << "Head " << i++ << ": " << *it++ << std::endl;
	}
	std::cout << "Body: " << _body << std::endl;
}
