#ifndef PARTICULAR_STRUCTS_HPP
# define PARTICULAR_STRUCTS_HPP

#include "CheckRcvdRequest.hpp"
#include "ParseRequest.hpp"
#include "ParseRequestLine.hpp"
#include "CheckRequestLine.hpp"
#include "ParseHeaders.hpp"
#include "ParseSpecificHeader.hpp"
//#include "ParseSpecificHeaerOut.hpp" //puede que sea ParseSpecificHeader
#include "ParseResponse.hpp"
#include "ParseStatusLineOut.hpp"
#include "Host.hpp"
//#include "ContentLenght.hpp"
//#include "Connection.hpp"
#include "Get.hpp"
//#include "Post.hpp"
//#include "Delete.hpp"
#include "ParseBodyOut.hpp"

//PARSE VARIABLES STRUCT
typedef struct s_objects
{
	CheckRcvdRequest	check_rcvd_req;
	ParseRequest		req;
	ParseRequestLine	req_line;
	CheckRequestLine	check_req_line;
	ParseHeaders		req_heads;
	ParseSpecificHeader	specific_header;
//	ParseSpecificHeaderOut	specific_header_out;
	ParseResponse		res;
	ParseStatusLineOut	res_status_line;
//	ParseHeadersOut		res_headers;
	ParseBodyOut		res_body;
}	t_objects;

//METHODS STRUCT
typedef struct s_exec
{
//	Get	get_method;
	Get	*get_method;
//	Post	*post_method;
//	Delete	*del_method;
}	t_exec;
	
//GENERAL STRUCT
typedef struct s_particular
{
	t_objects	objs;
	t_exec		exec;
}	t_particular;

#endif //PARTICULAR_STRUCTS_HPP
