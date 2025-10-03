#include "Method.hpp"

Method::Method(): _target_path(""), _search_directory(""), _file(""), _file_exists(0)
{
}	

Method::~Method()
{
}	

Method::Method(const Method& a): _target_path(a._target_path), _search_directory(a._search_directory), _file(a._file), _file_exists(a._file_exists)
{
}	

Method&	Method::operator=(const Method& a)
{
	_target_path = a._target_path;
	_search_directory = a._search_directory;
	_file = a._file;
	_file_exists = a._file_exists;
	return (*this);
}

void	Method::obtainTargetPath(const ParseRequestLine& req_line)
{
	std::string	site_path;

	site_path = "function"; //sacar la función
	_target_path = site_path + "/" + req_line.getRequestTarget();
}

void	Method::obtainSearchDirectoryAndFile(const ParseRequestLine& req_line)
{
	size_t	query_pos;
	size_t	last_slash_pos;

	query_pos = _target_path.find_first_of('?');
	last_slash_pos = _target_path.rfind("/", query_pos);
	if (last_slash_pos)
		_search_directory = _target_path.substr(0, last_slash_pos - 1);
	else
		_search_directory = "/";
	if (req_line.getRequestTarget().size() > 1)
		_file = _target_path.substr(last_slash_pos + 1, query_pos);
}

int	Method::readDirectory(DIR *search_directory)
{
	dirent		*file;
	std::string	str;

	file = readdir(search_directory);
	while (file)
	{
		str = file->d_name;
		if (str.compare(".") || str.compare(".."))
			continue;
		if (str.compare(_file))
		{
			_file_exists = 1;
			return (0);
		}
		file = readdir(search_directory);
	}
	_file_exists = 0;
	return (-1);
}

int	Method::verifyFileExistence(void)
{
	DIR	*search_directory;

	search_directory = opendir(_search_directory.c_str());
	if (!search_directory)
	{
		std::cerr << OPEN_DIR << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	if (readDirectory(search_directory))
		return (NOT_FOUND);
	if (closedir(search_directory))
	{
		std::cerr << CLOSE_DIR << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	return (0);
}

int	Method::execMethod(const ParseRequestLine& req_line, ParseBodyOut& res_body)
{
	int	status;

	try
	{
//		obtainSitePath //sale de la cabecera host con un get
		obtainTargetPath(req_line);
		obtainSearchDirectoryAndFile(req_line);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	catch (std::length_error& e)
	{
		std::cerr << LENGTH_ERROR << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << OUT_OF_RANGE << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	status = verifyFileExistence();
	res_body.setTargetPath(_target_path);
	return (status);
}
