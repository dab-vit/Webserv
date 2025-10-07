#include <map>
#include <vector>
#include <string>
#include "general_structs.hpp"
#include "def.h"

void	setErrorTypes(std::map<int, std::string>& err) 
{
	err.insert(std::pair<int, std::string>(200, "OK"));
	err.insert(std::pair<int, std::string>(201, "Created"));
	err.insert(std::pair<int, std::string>(204, "No Content"));
	err.insert(std::pair<int, std::string>(301, "Moved Permanently"));
	err.insert(std::pair<int, std::string>(302, "Found"));
	err.insert(std::pair<int, std::string>(400, "Bad Request"));
	err.insert(std::pair<int, std::string>(403, "Forbidden"));
	err.insert(std::pair<int, std::string>(404, "Not Found"));
	err.insert(std::pair<int, std::string>(405, "Method Not Allowed"));
	err.insert(std::pair<int, std::string>(413, "Payload Too Large"));
	err.insert(std::pair<int, std::string>(500, "Internal Server Error"));
	err.insert(std::pair<int, std::string>(501, "Not Implemented"));
	err.insert(std::pair<int, std::string>(502, "Bad Gateway"));
	err.insert(std::pair<int, std::string>(503, "Service Unavailable"));
	err.insert(std::pair<int, std::string>(504, "Gateway Timeout"));
	err.insert(std::pair<int, std::string>(505, "HTTP Version Not Supported"));
}

void	setSitesPath(std::map<std::string, std::string>& sites)
{
	sites.insert(std::pair<std::string, std::string>(ADDRESS, DEFAULT_SITE));
	sites.insert(std::pair<std::string, std::string>(SITE1, PATH1));
	sites.insert(std::pair<std::string, std::string>(SITE2, PATH2));
	sites.insert(std::pair<std::string, std::string>(SITE3, PATH3));
}

void	defineMethods(std::vector<std::string>& implemented, std::vector<std::string>& not_implemented)
{
	implemented.push_back("GET");
	implemented.push_back("POST");
	implemented.push_back("DELETE");
	not_implemented.push_back("HEAD");
	not_implemented.push_back("PUT");
	not_implemented.push_back("CONNECT");
	not_implemented.push_back("OPTIONS");
	not_implemented.push_back("TRACE");
}

void	defineVersions(std::vector<std::string>& versions)
{
	versions.push_back("HTTP/1.0");
	versions.push_back("HTTP/1.1");
	versions.push_back("HTTP/2.0");
	versions.push_back("HTTP/3.0");
}

void	defineHeaders(std::deque<std::string>& heads)
{
	heads.push_back("host");
	heads.push_back("contentlength");
	heads.push_back("connection");
}

void	setInitialDefinitions(t_definitions& def) 
{
	setErrorTypes(def.err);
	setSitesPath(def.sites);
	defineMethods(def.implemented_methods, def.not_implemented_methods);
	defineVersions(def.versions);
	defineHeaders(def.headers);
}
