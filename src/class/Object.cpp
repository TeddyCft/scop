#include "Object.hpp"
#include <iostream>

//= Operator overloader
Object	&Object::operator=(const Object &og)
{
	this->_vertices = og._vertices;
	this->_vCount = og._vCount;
	this->_vNorm = og._vNorm;
	this->_vnCount = og._vnCount;
	this->_vText = og._vText;
	this->_vtCount = og._vtCount;
	this->_faces = og._faces;
	this->_facesCount = og._facesCount;
	this->_currMtl = og._currMtl;
	this->_mtllib = og._mtllib;
	return (*this);
}

//Copy constructor
Object::Object(const Object &copy)
{ *this = copy ; }

//Default constructor
Object::Object(void)
{
	//creating _vertices[0] to a null value to put the center of the object later.
	this->addVertex((Vertex(0.0f, 0.0f, 0.0f)));
	this->_vCount = 0;
	this->_vnCount = 0;
	this->_vtCount = 0;
	this->_facesCount = 0;
	this->_name = "";	
	this->_currMtl = "";
}

//Destructor
Object::~Object(void)
{}

// Name

const std::string 	&Object::getName()
{ return (this->_name); }

void				Object::setName(std::string name)
{ this->_name = name; }

// Vertex

const Vertex &Object::getVertex(size_t index)
{ 
	if (index >= this->_vertices.size())
	{
		std::cerr << "Warning : trying to access unset vertice : " << index << "." << std::endl;
		return (this->_vertices[0]);
	}
	return(this->_vertices[index]); 
}

std::vector<Vertex> &Object::getVertices()
{ return this->_vertices; }

void Object::addVertex(Vertex vertex)
{
	this->_vertices.push_back(vertex);
	this->_vCount ++;
}

size_t	Object::getVCount()
{ return (this->_vCount); }

// Normals

const Vertex &Object::getVNorm(size_t index)
{ 
	if (index >= this->_vNorm.size())
	{
		std::cerr << "Warning : trying to access unset normal : " << index << "." << std::endl;
		return (this->_vNorm[0]);
	}
	return(this->_vNorm[index]); 
}

std::vector<Vertex> &Object::getVNorm()
{ return this->_vNorm; }

void Object::addVNorm(Vertex vertex)
{
	this->_vNorm.push_back(vertex);
	this->_vnCount += 1;
}

size_t	Object::getVnCount()
{ return (this->_vnCount); }

// Textures

const s_uv &Object::getVText(size_t index)
{ 
	if (index >= this->_vText.size())
	{
		std::cerr << "Warning : trying to access unset uv : " << index << "." << std::endl;
		return (this->_vText[0]);
	}
	return(this->_vText[index]); 
}

std::vector<s_uv> &Object::getVText()
{ return this->_vText; }

void Object::addVText(s_uv uv)
{
	this->_vText.push_back(uv);
	this->_vtCount += 1;
}

size_t	Object::getVtCount()
{ return (this->_vtCount); }

// Face

const Face &Object::getFace(size_t index)
{
	if (index >= this->_faces.size())
	{
		std::cerr << "Warning : trying to access unset face : " << index << "." << std::endl;
		return (this->_faces[0]);
	}
	return (this->_faces[index]);
}

void Object::addFace(Face face)
{ this->_faces.push_back(face); }

size_t Object::getFaceCount()
{ return(this->_faces.size()); }

const std::string	&Object::getCurrMtl()
{ return(this->_currMtl); }

void				Object::setCurrMtl(std::string name)
{ this->_currMtl = name; }

const std::vector<Material>		&Object::getMtl()
{ return(this->_mtllib); }

const Material		&Object::getMtl(size_t i)
{ return(this->_mtllib[i]); }

void				Object::addMtl(Material mtl)
{ this->_mtllib.push_back(mtl); }


void Object::debugPrintObject()
{
	if (this->_name != "")
		std::cout << "o " << this->_name << std::endl;
	for (size_t i = 1; i < this->_vCount; i++)
	{
		Vertex vtx = this->_vertices[i];
		std::cout << "v " << vtx.getX() << " " << vtx.getY() << " " << vtx.getZ() << std::endl;
	}

	for (size_t i = 0; i < this->_vnCount; i++)
	{
		Vertex vtx = this->_vNorm[i];
		std::cout << "vn " << vtx.getX() << " " << vtx.getY() << " " << vtx.getZ() << std::endl;
	}

	for (size_t i = 0; i < _vtCount; i++)
	{
		s_uv uv = this->_vText[i];
		std::cout << "v " << uv.x << " " << uv.y <<  std::endl;
	}

	for (size_t i = 0; i < this->_faces.size(); i++)
	{
		Face f = this->_faces[i];
		std::cout << "f";
		for (size_t j = 0; j < f.getVertface().size(); j++)
		{
			std::cout << " ";
			s_vertface vf = f.getVertface()[j];
			std::cout << vf.vertex;
			if (vf.texture)
				std::cout << "/" << vf.texture;
			else if (vf.normal)
				std::cout << "/";
			if (vf.normal)
				std::cout << "/" << vf.normal;
			}
		std::cout << std::endl;
	}

	for (size_t i = 0; i < this->_mtllib.size(); i++)
	{
		if (i == 0)
			std::cout << "Material lib :" << std::endl;
		this->_mtllib[i].debugPrintMtl();
	}
}