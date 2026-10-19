#ifndef FACE_HPP
#define FACE_HPP

#include <vector>
#include "struct.hpp"

class Face
{
	private:

	std::vector<s_vertface> _vertface;

	public:	
	
	void 							addVertface(t_vertface vert);
	const std::vector<s_vertface>	&getVertface();
	const s_vertface				&getVertface(size_t index);
	const int						&getValue(size_t index, e_vertface type);

	Face(void);
	Face(const Face &copy);
	Face &operator=(const Face &og);
	~Face(void);
}	;

#endif