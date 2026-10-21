#ifndef FACE_HPP
#define FACE_HPP

#include <vector>
#include <iostream>
#include "struct.hpp"

class Face
{
	private:

	std::vector<s_vertface> _vertface;
	std::string				_mtl;

	public:	
	
	void 							addVertface(t_vertface vert);
	const std::vector<s_vertface>	&getVertface();
	const s_vertface				&getVertface(size_t index);
	const int						&getValue(size_t index, e_vertface type);

	const std::string				&getMtl();
	void							setMtl(std::string mtl);

	Face(void);
	Face(const Face &copy);
	Face &operator=(const Face &og);
	~Face(void);
}	;

#endif