#include "ParseHeaders.hpp"

ParseHeaders::ParseHeaders()
{}	

ParseHeaders::~ParseHeaders()
{}	

ParseHeaders::ParseHeaders(const ParseHeaders& a)
{
	(void) a;
}	

ParseHeaders&	ParseHeaders::operator=(const ParseHeaders& a)
{
	(void) a;
	return (*this);
}

void	ParseHeaders::removeWhiteSpace(std::string& head_value_str)
{
	size_t	pos_1;
	size_t	pos_2;

	pos_1 = head_value_str.find_first_not_of(OWS);
	pos_2 = head_value_str.find_last_not_of(OWS);
/*	if (pos_1 == std::string::npos) ---> si (npos - npos) da problemas
	{
		head_value_str = "";
		return ;
	}
*/	head_value_str = head_value_str.substr(pos_1, pos_2 - pos_1 + 1);
}

int	ParseHeaders::obtainHeadNameAndValue(std::list<std::string>::const_iterator it, std::string& head_name, std::string& head_value_str)
{
	size_t		pos;

	pos = (*it).find_first_of(':');
	if (pos && pos != std::string::npos)
	{
		head_name = (*it).substr(0, pos);
		head_value_str = (*it).substr(pos + 1, std::string::npos);
		removeWhiteSpace(head_value_str);
	}
	else
		return (-1);
	return (0);
}

int     ParseHeaders::checkWhiteSpaceBeforeDots(const std::string& head_name)
{
	char	last_char;

	last_char = head_name[head_name.size() - 1];
	if (isspace(static_cast<unsigned char> (last_char)))
		return (-1);
	return (0);
}

int	ParseHeaders::translateHeadersListToMap(const std::list<std::string>& headers, std::map<std::string, std::string>& heads_map)
{
	std::string				head_name;
	std::string				head_value_str;
	std::list<std::string>::const_iterator	it;

	head_name = "";
	head_value_str = "";
	it = headers.begin();
	while (it != headers.end())
	{
		if (obtainHeadNameAndValue(it, head_name, head_value_str))
			return (-1);
		if (checkWhiteSpaceBeforeDots(head_name))
			return (-1);
		heads_map.insert(std::pair<std::string, std::string>(head_name, head_value_str));
		it++;
	}
	return (0);
}

int	ParseHeaders::compareNameInsensitiveCase(const std::string& name, const std::deque<std::string>& heads_types)
{
	size_t					i;
	std::deque<std::string>::const_iterator	it;
	std::string				name_str;

	i = 0;
	it = heads_types.begin();
	
	while (i < name.size()) 
	{
		name_str[i] = tolower(name[i]);
		i++;
	}
	i = 0;
	while (it != heads_types.end())
	{
		if (name.compare(*it++))
			return (i);
		i++;
	}
	return (-1);
}

int	ParseHeaders::selectHeaderAndParse(std::map<std::string, std::string>& heads_map, const t_definitions& def, ParseSpecificHeader& specific_header)
{
	std::map<std::string, std::string>::iterator	it;
	int						type;
	int						code;

	it = heads_map.begin();
	code = 0;
	while (it != heads_map.end())
	{
		type = compareNameInsensitiveCase(it->first, def.headers);
		if (type != -1)
			specific_header.parseSpecificHeader(it->second, type);
		if (code)
			return (code);
		it++;
	}
	return (0);
}

int	ParseHeaders::parseHeaders(const std::list<std::string>& headers, t_definitions& def, ParseSpecificHeader& specific_header)
{
	std::map<std::string, std::string>	heads_map;
	int					code;

	try
	{
		if (translateHeadersListToMap(headers, heads_map))
			return (BAD_REQUEST);
		code = selectHeaderAndParse(heads_map, def, specific_header);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << OUT_OF_RANGE << e.what() << std::endl;
		return (INTERNAL_SERVER_ERROR);
	}
	return (code);
}
