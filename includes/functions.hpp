#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <map>
#include <string>
#include "particular_structs.hpp"

void	setErrorTypes(std::map<int, std::string>& err);
void	setSitesPath(std::map<std::string, std::string>& paths);
void	defineMethod(std::vector<std::string>& vec_1, std::vector<std::string>& vec_2);
void	defineVersions(std::vector<std::string>& vec);
void	setInitialDefinitions(t_definitions& def);
int     initMethodObjects(t_exec& exec);
int     socketDefinition(t_config& server_config);
int     epollOperation(int newsockfd, t_objects& objs);
void    parseInput(t_objects& objs, int& code, t_definitions& def);
int	parseOutput(t_objects& objs, int& code, const std::map<int, std::string>& err);
int	serverExecution(t_objects& objs, t_exec& exec, const t_definitions& def);

#endif //FUNCTION_HPP
