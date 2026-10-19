#include "scop.hpp"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Object.hpp"
#include "proto.hpp"

int errtype;

int main(int ac, char **av)
{
	errtype = 0;
	Object obj;
	
	try 
	{
		check_args(ac, av);
		parse_obj(obj, av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error catch" << std::endl;
		return (manage_error(errtype));
	}

	obj.debugPrintObject();
}