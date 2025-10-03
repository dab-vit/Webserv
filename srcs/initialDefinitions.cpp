#include <map>
#include <vector>
#include "functions.cpp"

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
	err.insert(std::pair<int, std::string>(505, "HTTP Version Error"));
}

void	setSitesPath(std::map<std::string, std::string> paths)
{
	paths.insert(std::pair<std::string, std::string>(SITE1, PATH1));
	paths.insert(std::pair<std::string, std::string>(SITE2, PATH2));
	paths.insert(std::pair<std::string, std::string>(SITE3, PATH3));
}

void	defineMethods(std::vector<std::string>& vec_1, std::vector<std::string>& vec_2)
{
	vec_1.push_back("GET");
	vec_1.push_back("POST");
	vec_1.push_back("DELETE");
	vec_2.push_back("HEAD");
	vec_2.push_back("PUT");
	vec_2.push_back("CONNECT");
	vec_2.push_back("OPTIONS");
	vec_2.push_back("TRACE");
}

void	defineVersions(std::vector<std::string>& vec)
{
	vec.push_back("HTTP/1.0");
	vec.push_back("HTTP/1.1");
	vec.push_back("HTTP/2.0");
	vec.push_back("HTTP/3.0");
}

void	setInitialDefinitions(t_definitions& def) 
{
	setErrorTypes(def.err);
	setSitesPath(def.paths);
	defineMethods(def.implemented_methods, def.not_implemented_methods);
	defineVersions(def.versions);
}
