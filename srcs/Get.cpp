#include "Get.hpp"

Get::Get(void) 
{
}	

Get::~Get(void)
{
}	

Get::Get(const Get& a): AMethod(a)
{
}	

Get&	Get::operator=(const Get& a)
{
	_target_path = a._target_path;
	_search_directory = a._search_directory;
	_file = a._file;
	_file_exists = a._file_exists;
	return (*this);
}

int    Get::execParticularMethod(const ParseRequestLine& req_line, ParseBodyOut& res_body, ParseSpecificHeader& specific_header, const t_definitions& def)
{
	int	status;

	status = execMethod(req_line, res_body, specific_header, def);
	if (!status)
	{
		if (_file_exists)
			return (0);
		else
			return (NOT_FOUND);
	}
	return (status);
}
