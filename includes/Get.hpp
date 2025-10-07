#ifndef GET_HPP
# define GET_HPP

#include "AMethod.hpp"
#include "ParseRequestLine.hpp"
#include "ParseBodyOut.hpp"
#include "ParseSpecificHeader.hpp"

class Get: public AMethod
{
	public:
	Get();
	~Get();
	Get(const Get& a);
	Get&	operator=(const Get& a);
	
	int	execParticularMethod(const ParseRequestLine& req_line, ParseBodyOut& res_body, ParseSpecificHeader& specific_header, const t_definitions& def);
};

#endif //GET_HPP
