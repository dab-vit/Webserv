#ifndef HOST_HPP
# define HOST_HPP

#include <iostream>
#include <cstdlib>
#include "def.h"

class Host
{
	std::string	_authority;
	int		_port;
	size_t		_host_headers_num;


	public:
	Host(void);
	~Host(void);
	Host(const Host& a);
	Host&	operator=(const Host& a);

	const std::string&	getAuthority(void) const;
	int      		getHostHeadersNum(void) const;

	int	checkHeaderNum(void) const;
	int     verifyAuthority(void);
	int     obtainAuthority(std::string& value);
	int     obtainPort(std::string& value);
	int	parseHost(std::string& value);
};

#endif //HOST_HPP
