#ifndef METHOD_HPP
# define METHOD_HPP

#include <iostream>
#include <dirent.h>
#include "ParseRequestLine.hpp"
#include "ParseBodyOut.hpp"

class Method 
{
	protected:
	std::string	_target_path;
	std::string	_search_directory;
	std::string	_file;
	bool		_file_exists;

	public:
	Method();
	virtual ~Method();
	Method(const Method& a);
	Method&	operator=(const Method& a);

	int	execMethod(const ParseRequestLine& req_line, ParseBodyOut& res_body);
	void	obtainTargetPath(const ParseRequestLine& req_line);
	void	obtainSearchDirectoryAndFile(const ParseRequestLine& req_line);
	int     readDirectory(DIR *search_directory);
	int	verifyFileExistence(void);
	virtual	int	execParticularMethod(const ParseRequestLine& req_line, const ParseBodyOut& res_body) = 0;
};

#endif //METHOD_HPP
