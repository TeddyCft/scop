#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vertex.hpp"
#include "Face.hpp"
#include <vector>
#include <iostream>
#include "struct.hpp"
#include "Material.hpp"


class Object
{
	private:

	std::string			_name;

	std::vector<Vertex>	_vertices;
	size_t				_vCount;

	std::vector<Vertex>	_vNorm;
	size_t				_vnCount;

	std::vector<s_uv>	_vText;
	size_t				_vtCount;

	std::vector<Face>	_faces;

	std::string			_currMtl;
	
	std::vector<Material> _mtllib;

	public:

	const std::string			&getName();
	void						setName(std::string name);

	const Vertex				&getVertex(size_t index);
	std::vector<Vertex>			&getVertices();
	void						addVertex(Vertex vertex);
	size_t						getVCount();

	const Vertex				&getVNorm(size_t index);
	std::vector<Vertex>			&getVNorm();
	void						addVNorm(Vertex vertex);
	size_t						getVnCount();

	const s_uv					&getVText(size_t index);
	std::vector<s_uv>			&getVText();
	void						addVText(s_uv uv);
	size_t						getVtCount();

	const Face					&getFace(size_t index);
	void						addFace(Face face);

	const std::string			&getCurrMtl();
	void						setCurrMtl(std::string name);

	const std::vector<Material>	&getMtl();
	const Material				&getMtl(size_t i);
	void						addMtl(Material mtl);
	
	void						debugPrintObject();


	Object(void);
	Object(const Object &copy);
	Object &operator=(const Object &og);
	~Object(void);
}		;

#endif