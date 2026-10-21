#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include "struct.hpp"

class Material
{
	private:
	
	std::string	_name;

	// ------------------------

	// 		colors			
	
	// ------------------------
	t_clr		_ka; // ambient
	t_clr		_kd; // diffuse 
	t_clr		_ks; // specular
	t_clr		_ke; //	emitted

	// * optionnal * //
	// t_clr		_tf; // transmission
	// ------------------------
	
	// 		optical properties

	// ------------------------
	float		_d; // dissolution (opacity)
	float		_ns; // specular shine
	float		_ni; // optical refraction
	int			_illum; // illumination

	// * optionnal * //

	// float		_tr; // transparency (oposite of d)
	// ------------------------

	// 		texture

	// ------------------------
	// std::string	_mapKd; // diffuse texture path

	// * optionnal * //

	// std::string	_mapKa; // ambiante texture path
	// std::string	_mapKs; // specular texture path
	// std::string	_mapKe; // emissive texture path
	// std::string	_mapNs; // speculare shine path
	// std::string	_mapD; // diffusion map path (opacity)
	// std::string	_bump; // bump map path
	// std::string	_disp; // displacement map path
	// std::string	_decal; // decalc map path
	// std::string	_refl; // reflection map path
	// ------------------------


	public:

	// get/set 

	std::string	&getname();
	void		setname(std::string name);

	const t_clr	&getKa();
	void		setKa(t_clr clr);
	const t_clr	&getKd();
	void		setKd(t_clr clr);
	const t_clr	&getKs();
	void		setKs(t_clr clr);
	const t_clr	&getKe();
	void		setKe(t_clr clr);

	const float	&getD();
	void		setD(float f);
	const float	&getNs();
	void		setNs(float f);
	const float	&getNi();
	void		setNi(float f);
	const int	&getIllum();
	void		setIllum(int i);

	void		debugPrintMtl();
	
	Material(void);
	Material(const Material &copy);
	Material &operator=(const Material &og);
	~Material(void);
}		;

#endif
