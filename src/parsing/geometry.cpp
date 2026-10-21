#include <iostream>
#include <fstream>
#include <sstream>
#include "Object.hpp"
#include "errors.hpp"

extern int errtype;

void parse_vertex(Object &obj, std::string line)
{
	std::istringstream iss(line);
	std::string token;
	Vertex vertex;
	int i = 0;
	float value;

	iss >> token; // skipping line key ("v ")/
	while (iss >> value)
	{
		switch (i)
		{
			case 0 :
				vertex.setX(value);
				break;
			case 1 :
				vertex.setY(value);
				break;
			case 2 :
				vertex.setZ(value);
				break;
			default :
				errtype = ERR_FILE_VERTICES;
				throw (std::exception());
		}
		i++;
	}
	if (!iss.eof())
	{
		errtype = ERR_FILE_VERTICES;
		throw (std::exception());
	}
	obj.addVertex(vertex);
}

s_vertface get_vertface(std::string str)
{
	s_vertface vf;
	vf.normal = 0;
	vf.texture = 0;
	
	std::string nums = "-0123456789";
	std::string split[3] = {"", "", ""};

	std::stringstream ss(str);
	std::string token;
	int i = 0;
	while (std::getline(ss, token, '/'))
	{
		if (i > 2)
		{
			errtype = ERR_FILE_FACE;
			throw(std::exception());
		}
		split[i] = token;
		for (size_t j = 0; j < split[i].size(); j++)
		{
			if (nums.find(split[i][j]) == std::string::npos)
			{
				errtype = ERR_FILE_FACE;
				throw(std::exception());
			}
		}
		i++;
	}
	vf.vertex = std::stoi(split[0]);
	if (split[1] != "")
		vf.texture = std::stoi(split[1]);
	if (split[2] != "")
		vf.normal = std::stoi(split[2]);
	return (vf);
}

void parse_face(Object &obj, std::string line)
{
	std::istringstream iss(line);
	Face face;
	int i = 0;
	std::string token;

	iss >> token; // skipping line key ("f ")
	while (iss >> token)
	{
		s_vertface vf = get_vertface(token);
		face.addVertface(vf);
		i++;
	}
	if (!iss.eof())
	{
		errtype = ERR_FILE_FACE;
		throw(std::exception());
	}
	if (obj.getCurrMtl() != "")
		face.setMtl(obj.getCurrMtl());
	obj.addFace(face);
}

void parse_texture(Object &obj, std::string line)
{
	std::istringstream iss(line);
	std::string token;
	s_uv uv;
	int i = 0;
	float value;

	iss >> token; // skipping line key ("vn")
	while (iss >> value)
	{
		switch (i)
		{
			case 0 :
				uv.x = value;
				break;
			case 1 :
				uv.y = value;
				break;
			default :
				errtype = ERR_FILE_TEXTURE;
				throw (std::exception());
		}
		i++;
	}
	if (!iss.eof())
	{
		errtype = ERR_FILE_TEXTURE;
		throw (std::exception());
	}
	obj.addVText(uv);
}

void parse_normal(Object &obj, std::string line)
{
	std::istringstream iss(line);
	std::string token;
	Vertex vertex;
	int i = 0;
	float value;

	iss >> token; // skipping line key ("vn")
	while (iss >> value)
	{
		switch (i)
		{
			case 0 :
				vertex.setX(value);
				break;
			case 1 :
				vertex.setY(value);
				break;
			case 2 :
				vertex.setZ(value);
				break;
			default :
				errtype = ERR_FILE_NORMAL;
				throw (std::exception());
		}
		i++;
	}
	if (!iss.eof())
	{
		errtype = ERR_FILE_NORMAL;
		throw (std::exception());
	}
	obj.addVNorm(vertex);
}


