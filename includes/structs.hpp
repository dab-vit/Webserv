#ifndef STRUCTS_HPP
# define STRUCTS_HPP

#include "non_class_structs.hpp"
#include "CheckRcvdRequest.hpp"
#include "ParseRequest.hpp"
#include "ParseRequestLine.hpp"
#include "CheckRequestLine.hpp"
#include "ParseResponse.hpp"
#include "ParseStatusLineOut.hpp"
#include "Method.hpp"
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
//	ParseHeaders		req_heads;
	ParseResponse		res;
	ParseStatusLineOut	res_status_line;
//	ParseHeadersOut		res_headers;
	ParseBodyOut		res_body;
}	t_objects;

//METHODS STRUCT
typedef struct s_exec
{
	Get	*get_method;
//	Post	*post_method;
//	Delete	*del_method;
}		t_exec;

//GENERAL STRUCT
typedef struct s_general
{
	t_definitions	def;
	t_objects	objs;
	t_config	server_config;
	t_exec		exec;
}	t_general;

#endif //STRUCTS_HPP
