#include <iostream>
#include "Object.hpp"
#include "errors.hpp"
#include "proto.hpp"
#include <cmath>
#include <algorithm>

extern int errtype;

void checkVtx(Vertex vtx)
{
	float val;
	for (size_t i = 0; i < 3; i++)
	{
		switch (i)
		{
			case 0:
				val = vtx.getX();
				break;
			case 1:
				val = vtx.getY();
				break;
			case 2:
				val = vtx.getZ();
				break;
		}
		if (std::isnan(val) || std::isinf(val))
		{
			errtype = ERR_FILE_VERTICES;
			throw(std::exception());
		}
	}
}

bool checkDouble(std::vector<int> &vtx, std::vector<int> &norm, std::vector<int> &text, s_vertface vf)
{
	if (std::find(vtx.begin(), vtx.end(), vf.vertex) != vtx.end())
		return true;
	else
		vtx.push_back(vf.vertex);

	if (std::find(norm.begin(), norm.end(), vf.normal) != norm.end())
		return true;
	else
		vtx.push_back(vf.vertex);

	if (std::find(text.begin(), text.end(), vf.texture) != text.end())
		return true;
	else
		vtx.push_back(vf.vertex);
	return false;
}

void checkFace(Face face, Object &obj)
{
	s_vertface vf;

	std::vector<int> 	vtx;
	std::vector<int> 	norm;
	std::vector<int> 	text;

	int vnCount = (int)obj.getVnCount();
	int vtCount = (int)obj.getVtCount();


	for (size_t i = 0; i < face.getVertface().size(); i++)
	{
		vf = face.getVertface(i);
		
		if (checkDouble(vtx, norm, text, vf))
		{
			errtype = ERR_FILE_FACE;
			throw(std::exception());
		}

		if ((vnCount && (vf.normal == 0 || vf.normal > vnCount)) ||
			(vtCount && (vf.texture == 0 || vf.texture > vtCount)) ||
			vf.vertex == 0 || vf.vertex > (int)obj.getVCount() )
		{
			errtype = ERR_FILE_FACE;
			throw(std::exception());
		}
	}
	if (face.getVertface().size() <= 2)
	{
		errtype = ERR_FILE_FACE;
		throw(std::exception());
	}
}

void	checkValues(Object &obj)
{
	for (size_t i = 0; i < obj.getVCount(); i++)
		checkVtx(obj.getVertex(i));

	for (size_t i = 0; i < obj.getVnCount(); i++)
		checkVtx(obj.getVNorm(i));

	for (size_t i = 0; i < obj.getFaceCount(); i++)
		checkFace(obj.getFace(i), obj);
}