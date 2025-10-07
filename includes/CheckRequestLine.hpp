#ifndef CHECK_REQUEST_LINE_HPP
# define CHECK_REQUEST_LINE_HPP

#include <iostream>
#include <cctype>
#include <vector>
#include "ParseRequestLine.hpp"
#include "def.h"
#include "general_structs.hpp"

class CheckRequestLine
{
	public:
	CheckRequestLine();
	~CheckRequestLine();
	CheckRequestLine(const CheckRequestLine& a);
	CheckRequestLine&	operator=(const CheckRequestLine& a);

	int	checkRequestLine(const ParseRequestLine& parse, const t_definitions& def) const;
	void	checkMethod(const std::string& method, const t_definitions& def, int& status) const;
	int	checkTarget(const std::string& target) const;
	void	checkVersion(const std::string& version, const t_definitions& def, int& status) const;
	void    defineMethodVectors(std::vector<std::string>& vec_1, std::vector<std::string>& vec_2) const;
	void    defineVersionsVector(std::vector<std::string>& vec) const;
	int     compareWithVector(const std::string& pattern, const std::vector<std::string>& vec) const;
};

#endif //CHECK_REQUEST_LINE_HPP
