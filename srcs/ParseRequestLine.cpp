#include "ParseRequestLine.hpp"

ParseRequestLine::ParseRequestLine(void): _method_str(""), _method(-1), _reference_str(REF2), _request_target(""), _http_rcvd_version("")
{
}

ParseRequestLine::~ParseRequestLine(void)
{
}

ParseRequestLine::ParseRequestLine(const ParseRequestLine& p): _method_str(p._method_str), _method(p._method), _reference_str(REF2), _request_target(p._request_target), _http_rcvd_version(p._http_rcvd_version)
{
}

ParseRequestLine&	ParseRequestLine::operator=(const ParseRequestLine& p)
{
	_method_str = p._method_str;
	_method = p._method;
	_reference_str = REF2;
	_request_target = p._request_target;
	_http_rcvd_version = p._http_rcvd_version;
	return (*this);
}

const std::string& ParseRequestLine::getMethodStr(void) const
{
	return (_method_str);
}

int	 ParseRequestLine::getMethod(void) const
{
	return (_method);
}
 
const std::string&   ParseRequestLine::getRequestTarget(void) const
{
	return (_request_target);
}

const std::string& ParseRequestLine::getHttpRcvdVersion(void) const
{
	return (_http_rcvd_version);
}

void	ParseRequestLine::assignValueToField(const std::string& value, const int option, const std::vector<std::string>& implemented_methods)
{
	std::vector<std::string>::const_iterator	it;
	int	i;

	it = implemented_methods.begin();
	i = 0;
	if (option == METHOD)
	{
		_method_str = value;
		while (it != implemented_methods.end())
		{
			if (!value.compare(*it++))
			{
				_method = i;
				return ;
			}
			i++;
		}
	}
	else if (option == REQUEST_TARGET)
		_request_target = value;
}

int	ParseRequestLine::parseRequestLineField(size_t& pos, std::string& remaining_request_str, int option, const std::vector<std::string>& implemented_methods)
{
	std::string	value;

	pos = remaining_request_str.find(_reference_str);
	if (pos && pos != std::string::npos)
	{
		value = remaining_request_str.substr(0, pos);
		remaining_request_str = remaining_request_str.substr(pos + _reference_str.size(), std::string::npos);
		assignValueToField(value, option, implemented_methods);
	}
	else
		return (-1);
	return (0);	
}

void	ParseRequestLine::parseHttpRcvdVersion(std::string& remaining_request_str)
{
	_http_rcvd_version = remaining_request_str;
}

int	ParseRequestLine::parseRequestLine(const std::string& request, const std::vector<std::string>& implemented_methods)
{
	size_t		pos;
	std::string	remaining_request_str;
	
	pos = 0;
	remaining_request_str = request;
	try
	{
		if (parseRequestLineField(pos, remaining_request_str, METHOD, implemented_methods))
			return (BAD_REQUEST);
		if (parseRequestLineField(pos, remaining_request_str, REQUEST_TARGET, implemented_methods))
			return (BAD_REQUEST);
		parseHttpRcvdVersion(remaining_request_str);
	}
	catch(std::out_of_range& e)
	{
		std::cerr << OUT_OF_RANGE << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	catch(std::bad_alloc& e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	return (0);
}

void	ParseRequestLine::print(void) const
{
	std::cout << "REQUEST LINE" << std::endl;
	std::cout << "Method: " << _method_str << ", " <<  _method << std::endl;
	std::cout << "Reference str: " << _reference_str << std::endl;
	std::cout << "Request target " << _request_target << std::endl;
	std::cout << "HTTP received version " << _http_rcvd_version << std::endl;
}
