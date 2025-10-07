#include "Host.hpp"

Host::Host(): _authority(""), _port(0), _host_headers_num(0)
{}	

Host::~Host()
{}	

Host::Host(const Host& a): _authority(a._authority), _port(a._port), _host_headers_num(a._host_headers_num)
{}	

Host&	Host::operator=(const Host& a)
{
	_authority = a._authority;
	_port = a._port;
	_host_headers_num = a._host_headers_num;
	return (*this);
}

const std::string&	Host::getAuthority(void) const
{
	return (_authority);
}

int	Host::getHostHeadersNum(void) const
{
	return (_host_headers_num);
}

int	Host::checkHeaderNum(void) const
{
	if (_host_headers_num != 1)
		return (-1);
	return (0);
}

int	Host::verifyAuthority(void)
{
	size_t		pos;
	std::string	final_str;

	pos = _authority.find("www.");
	if (pos)
		return (-1);
	pos = _authority.find_first_of('.');
	if (!('0' <= _authority[pos + 1] && _authority[pos + 1] <= '9') && \
		!('a' <= _authority[pos + 1] && _authority[pos + 1] <= 'z'))
		return (-1);
	pos = _authority.find_first_of('.', pos + 2);
	if (pos == std::string::npos)
		return (-1);
	pos = _authority.find_last_of('.');
	if (pos != std::string::npos)
		final_str = _authority.substr(pos + 1, std::string::npos);
	if (final_str.size() != 3)
		return (-1);
	return (0);
}

int	Host::obtainAuthority(std::string& value)
{
	size_t	pos;

	pos = value.find_first_of(':');
	if (pos != std::string::npos)
		pos = pos - 1;
	_authority = value.substr(0, pos);
	if (verifyAuthority())
		return (-1);
	return (0);
}

int	Host::obtainPort(std::string& value)
{
	size_t		pos;
	std::string	port_str;

	pos = value.find_first_of(':');
	if (pos != std::string::npos)
	{
		port_str = value.substr(pos + 1, std::string::npos);
		_port = atoi(port_str.c_str());
//		if (_port != config.port)
		if (_port != 25315)
			return (-1);
	}
	return (0);
}

int	Host::parseHost(std::string& value)
{
	_host_headers_num++;
	try
	{
		if (checkHeaderNum())
			return (BAD_REQUEST); 
		if (obtainAuthority(value))
			return (BAD_REQUEST); 	
		if (obtainPort(value))
			return (BAD_REQUEST);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << OUT_OF_RANGE << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	} 
	return (0);
}
