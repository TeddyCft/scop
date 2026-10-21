#include <iostream>
#include <fstream>
#include <sstream>
#include "Object.hpp"
#include "errors.hpp"
#include "proto.hpp"

extern int errtype;

void parse_name(Object &obj, std::string line)
{
	std::istringstream iss(line);
	std::string token;
	iss >> token;
	if (!(iss >> token))
	{
		errtype = ERR_FILE_NAME;
		throw(std::exception());
	}
	else
		obj.setName(token);
}

void parse_line(Object &obj, std::string line)
{
	std::string key;
	std::istringstream iss(line);
	iss >> key;
	if (key == "v")
		parse_vertex(obj, line);
	else if (key == "f")
		parse_face(obj, line);
	else if (key == "vt")
		parse_texture(obj, line);
	else if (key == "vn")
		parse_normal(obj, line);
	else if (key == "o")
		parse_name(obj, line);
	else if (key == "mtllib")
		parse_mtllib(obj, line);
	else if (key == "usemtl")
		set_currmtl(obj, line);
}

void parse_obj(Object &obj, std::string filepath)
{
	std::ifstream file(filepath);
	if (!file)
	{
		errtype = ERR_FILE_OPEN;
		throw(std::exception());
	}

	std::string line;
	while (std::getline(file, line))
	{
		parse_line(obj, line);
	}
	if (obj.getVCount() == 0)
	{
		errtype = ERR_FILE_EMPTY;
		throw(std::exception());
	}
	checkValues(obj);
}