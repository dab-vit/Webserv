#ifndef GET_HPP
# define GET_HPP

#include "Method.hpp"
#include "ParseRequestLine.hpp"
#include "ParseBodyOut.hpp"

class Get: public Method
{
	public:
	Get();
	~Get();
	Get(const Get& a);
	Get&	operator=(const Get& a);
	
	int	execParticularMethod(const ParseRequestLine& req_line, ParseBodyOut& res_body);
};

#endif //GET_HPP
