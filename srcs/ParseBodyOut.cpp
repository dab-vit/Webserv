#include "ParseBodyOut.hpp"

ParseBodyOut::ParseBodyOut(): _target_path(""), _body("")
{
}	

ParseBodyOut::~ParseBodyOut()
{
}	

ParseBodyOut::ParseBodyOut(const ParseBodyOut& a): _target_path(a._target_path), _body(a._body)
{
}	

ParseBodyOut::ParseBodyOut&	operator=(const ParseBodyOut& a)
{
	_target_path = a._target_path;
	_body = a._body;
	return (*this);
}

void    ParseBodyOut::setTargetPath(std::string& target_path)
{
	_target_path = target_path;
}

void	ParseBodyOut::obtainErrorPath(int status)
{
	_target_path = ERRORS_PATH + "/" + error_file;
	//error file: 1 por cada error en un mapa o lo genero en cada caso
}

int	modifyResponse(int status, const ParseResponse& res, ParseStatusLineOut& res_status_line)
{
	std::cerr << MODIFY << std::endl;
	if (res_status_line.parseStatusLineOut(res, status, err))
		return (-1);
//	if (objs.parseHeaders)
//		return (-1);
	if (parseBodyOut(status, const ParseResponse& res, ParseStatusLineOut& res_status_line))
		return (-1);
	return (0);
}

int	ParseBodyOut::obtainBody(int status, const ParseResponse& res, ParseStatusLineOut& res_status_line)
{
	ifstream	read_stream;
//	ifstream	read_stream(_target_path.c_str(), ios_base::in);

	read_stream.open(_target_path.c_str());
	if (!read_stream.is_open())
	{
		std::cerr << OPEN_FILE << std::endl;
		if (status != INTERNAL_SERVER_ERROR)
		{
			ret = modifyResponse(INTERNAL_SERVER_ERROR, res, res_status_line)
			if (ret == -1)
				return (-1);
			else
				return (0);
		}
		else
			return (-1);
	}
	read_stream >> _body; //falta cómo leer
	read_stream.close();
	return (0);
}

int	ParseBodyOut::parseBodyOut(int status, const ParseResponse& res,ParseStatusLineOut& res_status_line)
{
/*	if (!_necessary)
	{
		_body = "";
		return (0);
	}
*/	if (status)
		obtainErrorPath(status);
	if (_target_path != "") //supongo que POST y DELETE no tienen body
	{
		if (_body_str = obtainBody(status, res, res_status_line))
			return (-1);
	}	
	res.setBody(_body);
	return (0);
}
