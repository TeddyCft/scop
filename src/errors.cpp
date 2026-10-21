#include <iostream>
#include "errors.hpp"

extern int errtype;

int manage_error(int errtype)
{
	std::string errs[] = {
		"No Error (?)",
		"Argument count error.",
		"Wrong argument",
		"Argument file name error",
		"Error in file concerning vertices",
		"Error in file concerning normal",
		"Error in file concerning texture",
		"Error in file concerning faces",
		"Cant open file",
		"File is empty",
		"Error in mtl lib content",
		"Error with mtl name in obj file"
	};

	std::cerr << "Error : " << errs[errtype] << std::endl;
	return (1);
}

int check_args(int ac, char **av)
{
	if (ac != 2)
		errtype = ERR_ARGS_COUNT;
	else
	{
		std::string filename(av[1]);
		size_t extension_pos = filename.find_last_of(".");
		if (extension_pos != std::string::npos && filename.substr(extension_pos) == ".obj")
			return (0);
		errtype = ERR_FILE_NAME;
	}
	throw(std::exception());
}