#include "Face.hpp"

//= Operator overloader
Face	&Face::operator=(const Face &og)
{
	this->_vertface = og._vertface;
	return (*this);
}

//Copy constructor
Face::Face(const Face &copy)
{ *this = copy ; }

//Default constructor
Face::Face(void)
{}

//Destructor
Face::~Face(void)
{}

void Face::addVertface(t_vertface vert)
{this->_vertface.push_back(vert); }

const std::vector<s_vertface>	&Face::getVertface()
{ return(this->_vertface); }

const s_vertface				&Face::getVertface(size_t index)
{ return(this->_vertface[index]); }

const int						&Face::getValue(size_t index, e_vertface type)
{ 
	switch (type)
	{
		case VF_NORM :
			return this->_vertface[index].normal;
		case VF_TEXT :
			return this->_vertface[index].texture;
		default :
			return this->_vertface[index].vertex;
	}
}

const std::string				&Face::getMtl()
{ return (this->_mtl); }

void							Face::setMtl(std::string mtl)
{ this->_mtl = mtl; }