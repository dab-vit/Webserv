#ifndef NON_CLASS_STRUCTS_HPP
# define NON_CLASS_STRUCTS_HPP

#include <map>
#include <vector>
#include <string>

//INITIAL DEFINITIONS
typedef struct s_definitions
{
	std::map<int, std::string>		err;
	std::map<std::string, std::string>	paths;	
	std::vector<std::string>		implemented_methods;
	std::vector<std::string>		not_implemented_methods;
	std::vector<std::string>		versions;
}	t_definitions;

//SERVER SETTINGS STRUCT
typedef struct s_config
{
	int		port_no;
	int		connections_queue;
	std::string	site_path;
}	t_config;

typedef enum e_request_type
{
	GET,
	POST,
	DELETE
}	t_request_type;

#endif //NON_CLASS_STRUCTS_HPP
