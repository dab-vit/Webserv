#ifndef AMETHOD_HPP
# define AMETHOD_HPP

#include <iostream>
#include <dirent.h>
#include "ParseRequestLine.hpp"
#include "ParseBodyOut.hpp"
#include "ParseSpecificHeader.hpp"
#include "general_structs.hpp"

class AMethod 
{
	protected:
	std::string	_site_path;
	std::string	_target_path;
	std::string	_search_directory;
	std::string	_file;
	bool		_file_exists;

	public:
	AMethod(void);
	virtual ~AMethod(void);
	AMethod(const AMethod& a);
	AMethod&	operator=(const AMethod& a);

	int	execMethod(const ParseRequestLine& req_line, ParseBodyOut& res_body, ParseSpecificHeader& specific_header, const t_definitions& def);
	int	obtainSitePath(Host& host, const std::map<std::string, std::string>& sites);
	void	obtainTargetPath(const ParseRequestLine& req_line);
	void	obtainSearchDirectoryAndFile(const ParseRequestLine& req_line);
	int     readDirectory(DIR *search_directory);
	int	verifyFileExistence(void);
	virtual	int	execParticularMethod(const ParseRequestLine& req_line, ParseBodyOut& res_body, ParseSpecificHeader& specific_header, const t_definitions& def) = 0;
};

#endif //AMETHOD_HPP
