#include "Material.hpp"

//= Operator overloader
Material	&Material::operator=(const Material &og)
{
	this->_d = og._d;
	this->_illum = og._illum;
	this->_ka = og._ka;
	this->_kd = og._kd;
	this->_ke = og._ke;
	this->_ks = og._ks;
	this->_name = og._name;
	this->_ni = og._ni;
	this->_ns = og._ns;
	return (*this);
}

//Copy constructor
Material::Material(const Material &copy)
{ *this = copy ; }

//Default constructor
Material::Material(void)// : args(0), ...
{}

//Destructor
Material::~Material(void)
{}

const std::string	&Material::getname()
{ return (this->_name); }

void				Material::setname(std::string name)
{ this->_name = name; }

const t_clr	&Material::getKa()
{ return(this->_ka); }

void		Material::setKa(t_clr clr)
{ this->_ka = clr; }

const t_clr	&Material::getKd()
{ return(this->_kd); }

void		Material::setKd(t_clr clr)
{ this->_kd = clr; }

const t_clr	&Material::getKs()
{ return(this->_ks); }

void		Material::setKs(t_clr clr)
{ this->_ks = clr; }

const t_clr	&Material::getKe()
{ return(this->_ke); }

void		Material::setKe(t_clr clr)
{ this->_ke = clr;}

const float	&Material::getD()
{ return(this->_d); }

void		Material::setD(float f)
{ this->_d = f; }

const float	&Material::getNs()
{ return(this->_ns); }

void		Material::setNs(float f)
{ this->_ns = f;}

const float	&Material::getNi()
{ return(this->_ni); }

void		Material::setNi(float f)
{ this->_ni = f;}

const int	&Material::getIllum()
{ return(this->_illum); }

void		Material::setIllum(int i)
{ this->_illum = i; }