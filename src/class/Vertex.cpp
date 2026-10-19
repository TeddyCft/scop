#include "Vertex.hpp"

//= Operator overloader
Vertex	&Vertex::operator=(const Vertex &og)
{
	this->_x = og._x;
	this->_y = og._y;
	this->_z = og._z;
	return (*this);
}

//Copy constructor
Vertex::Vertex(const Vertex &copy)
{ *this = copy ; }

Vertex::Vertex(float x, float y, float z) : _x(x), _y(y), _z(z)
{}

//Default constructor
Vertex::Vertex(void) : _x(0.0f), _y(0.0f), _z(0.0f)
{}

//Destructor
Vertex::~Vertex(void)
{}


float Vertex::getX() const
{ return (this->_x); }

void Vertex::setX(float val)
{ this->_x = val; }

float Vertex::getY() const
{ return (this->_y); }

void Vertex::setY(float val)
{ this->_y = val; }

float Vertex::getZ() const
{ return (this->_z); }

void Vertex::setZ(float val)
{ this->_z = val; }