#include <iostream>
#include <fstream>
#include <sstream>
#include "Object.hpp"
#include "errors.hpp"
#include "scop.hpp"

extern int errtype;

t_clr parse_color(std::string line)
{
	std::istringstream	iss(line);
	std::string			token;
	float				value;

	int 				i = 0;
	t_clr				clr;
	iss >> token; // skipping key
	while (iss >> value)
	{
		switch (i)
		{
			case 0:
				clr.r = value;
				break;
			case 1:
				clr.g = value;
				break;
			case 2:
				clr.b = value;
				break;
			default:
				errtype = ERR_MTL_CONTENT;
				throw(std::exception());
		}
		i++;
	}
	if (!iss.eof())
	{
		errtype = ERR_MTL_CONTENT;
		throw(std::exception());
	}
	return (clr);
}

void parse_line(Material &mtl, std::string &line)
{
	std::istringstream	iss(line);
	std::string			key;

	iss >> key;
	if (key[0] == 'K' || key[0] == 'k')
	{
		t_clr clr = parse_color(line);
		switch (key[1])
		{
			case 'a':
				mtl.setKa(clr);
				break;
			case 'd':
				mtl.setKd(clr);
				break;
			case 's':
				mtl.setKs(clr);
				break;
			case 'e':
				mtl.setKe(clr);
				break;
			default :
				errtype = ERR_MTL_CONTENT;
				throw(std::exception());
		}
		return;
	}
	else if (key == "illum")
	{
		int i;
		if (!(iss >> i))
		{
			errtype = ERR_MTL_CONTENT;
			throw(std::exception());
		}
		mtl.setIllum(i);
		return ;
	}
	else if (key == "newmtl")
	{
		std::string name;
		if (!(iss >> name))
		{
			errtype = ERR_MTL_CONTENT;
			throw(std::exception());
		}
		mtl.setname(name);
	}
	if (key == "Ns" || key == "Ni" || key == "d")
	{
		float fval;
		if (!(iss >> fval))
		{
			errtype = ERR_MTL_CONTENT;
			throw(std::exception());
		}
		if (key == "Ns")
			mtl.setNs(fval);
		else if (key == "Ni")
			mtl.setNi(fval);
		else
			mtl.setD(fval);
		return ;
	}
}

std::string buildpath(std::string path)
{
	std::string prefix = SCOP_ASSETS_PATH;
	std::istringstream iss(path);
	std::string suffix;
	iss >> suffix;
	iss >> suffix;
	return ( prefix + suffix);
}

void parse_mtllib(Object &obj, std::string path)
{
	path = buildpath(path);
	std::cerr << "path = " << path << std::endl;
	std::ifstream 	lib(path);
	if (!lib)
	{
		errtype = ERR_FILE_OPEN;
		throw(std::exception());
	}
	
	std::string line;
	Material newmtl;

	while (!lib.eof())
	{
		std::getline(lib, line);
		parse_line(newmtl, line);
	}
	obj.addMtl(newmtl);
}

void set_currmtl(Object &obj, std::string line)
{
	(void) obj;
	(void) line;
}