#include "Get.hpp"
#include "Post.hpp"
#include "Delete.hpp"
#include "def.h"

int	initMethodObjects(t_exec& exec)
{
	try
	{
		exec.get_method = new Get;
		exec.post_method = new Post;
		exec.del_method = new Delete;
	}
	catch (std::bad_alloc e)
	{
		std::cerr << BAD_ALLOC << e.what() << std::endl; 
		return (INTERNAL_SERVER_ERROR);
	}
	return (0);
}
