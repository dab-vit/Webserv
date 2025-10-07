#include "CheckRequestLine.hpp"

CheckRequestLine::CheckRequestLine()
{
}	

CheckRequestLine::~CheckRequestLine()
{
}	

CheckRequestLine::CheckRequestLine(const CheckRequestLine& a)
{
	(void) a;
}	

CheckRequestLine&	CheckRequestLine::operator=(const CheckRequestLine& a)
{
	(void) a;
	return (*this);
}

int	CheckRequestLine::compareWithVector(const std::string& pattern, const std::vector<std::string>& vec) const
{
	size_t	i;

	i = 0;
	while (i < vec.size())
	{
		if (!pattern.compare(vec[i++]))
			return (1);
	}
	return (0);
}	

void	CheckRequestLine::checkMethod(const std::string& method, const t_definitions& def, int& status) const
{
	if (compareWithVector(method, def.implemented_methods))
		status = 0;
	else if (compareWithVector(method, def.not_implemented_methods))
		status = METHOD_NOT_ALLOWED;
	else
		status = NOT_IMPLEMENTED;
}

int	CheckRequestLine::checkTarget(const std::string& target) const
{
	std::string::const_iterator	it;

	it = target.begin();
	while (it != target.end())
	{
		if (std::isspace(static_cast<unsigned char>(*it++)))
			return (BAD_REQUEST);
	}
	return (0);
}

//VERSION 1
void	CheckRequestLine::checkVersion(const std::string& version, const t_definitions& def, int& status) const
{
	if (!compareWithVector(version, def.versions))
		status = BAD_REQUEST;
	else
		status = 0;
}
/*
//VERSION 2
int     CheckRequestLine::checkVersion(const std::string& version, int& status) const
{
	if (version.compare(0, 5, "HTTP/") || !('0' <= version[5] <= '9') || \
	    version[6] != '.' || !('0' <= version[7] <= '9'))
		status = BAD_REQUEST;
	else if (!('1' <= version[5] <= '3') || !('0' <= version[7] <= '1'))
		status = NOT_IMPLEMENTED; 
	else
		status = 0 ;
}	
*/
int	CheckRequestLine::checkRequestLine(const ParseRequestLine& parse, const t_definitions& def) const
{
	int	status;

	status = 0;
	try
	{
		checkMethod(parse.getMethodStr(), def, status);
		if (!status)
			status = checkTarget(parse.getRequestTarget());
		if (!status)	
			checkVersion(parse.getHttpRcvdVersion(), def, status);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl;
		status = INTERNAL_SERVER_ERROR;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << OUT_OF_RANGE << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	return (status);
}
