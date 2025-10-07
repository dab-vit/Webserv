#include "general_structs.hpp"
#include "particular_structs.hpp"
#include <map>
#include "functions.hpp"

int	runWebserver(std::string config_file, bool flag)
{
	t_general	gral;
	t_particular	part;	//mover
	int		status_code;
	std::string	str;

	(void) config_file;
	(void) flag;
	status_code = 0;
//	str = "GET Target HTTP/1.1\\r\\nhead1\\r\\nhead2\\r\\n\\r\\nqwertasdfg";	
	//1. setInitialDefinitions and init
	setInitialDefinitions(gral.def);
	status_code = initMethodObjects(part.exec); //mover
	//2. parseConfigFile(config_file, flag);
	//3. socketDefinition -- falta bucle y non-blocking
	if (!status_code)
		status_code = socketDefinition(gral.server_config);
	//4. epollOperation
	if (status_code != -1)
		status_code = epollOperation(status_code, part.objs); //sacar part.objs
	else
		status_code = INTERNAL_SERVER_ERROR; 
	//5. parseInput
	if (!status_code)
		parseInput(part.objs, status_code, gral.def);
	part.objs.req.print();
	part.objs.req_line.print();
	//if (!status_code)
	//6. serverExecution
	if (!status_code)
		status_code = serverExecution(part.objs, part.exec, gral.def);
	//7. parseOutput(status_code);
	if (parseOutput(part.objs, status_code, gral.def.err))
		return (-1);
	part.objs.res.setHeaders(part.objs.req.getHeaders()); //eliminar
	part.objs.res.setBody("aghhsoiemf"); //eliminar		
	part.objs.res.print();
	//8. sendResponse with message
	//9. freeFunction (if needed)
	return (0);
}

int	main(int argc, char **argv)
{
	bool	flag;

	if (argc == 1)
	{
		flag = false;
		if (runWebserver("", flag))
			return (-1);
	}
	else if (argc == 2)
	{
		flag = true;
		if (runWebserver(argv[1], flag))
			return (-1);
	}
	else
	{
		std::cerr << ARGS << std::endl;
		return (-1);
	}
	return (0);
}
