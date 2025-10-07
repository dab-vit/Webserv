#ifndef GENERAL_STRUCTS_HPP
# define GENERAL_STRUCTS_HPP

#include <map>
#include <vector>
#include <string>
#include <deque>

//INITIAL DEFINITIONS
typedef struct s_definitions
{
	std::map<int, std::string>		err;
	std::map<std::string, std::string>	sites;
	std::vector<std::string>		implemented_methods;
	std::vector<std::string>		not_implemented_methods;
	std::vector<std::string>		versions;
	std::deque<std::string>			headers;
}	t_definitions;

//SERVER SETTINGS STRUCT
typedef struct s_config
{
	int		port_no;
	int		connections_queue;
	std::string	site_path;
}	t_config;

typedef struct s_general
{
	t_definitions	def;
	t_config	server_config;
}	t_general;

typedef enum e_request_type
{
	GET,
	POST,
	DELETE
}	t_request_type;

typedef enum e_headers
{
	host_type,
	content_length_type,
	connection_type
}	t_headers;

#endif //GENERAL_STRUCTS_HPP
