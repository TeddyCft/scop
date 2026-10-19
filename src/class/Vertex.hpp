#ifndef VERTEX_HPP
#define VERTEX_HPP

class Vertex
{
	private:

	float _x;
	float _y;
	float _z;

	public:

	float	getX() const;
	void	setX(float val);

	float	getY() const;
	void	setY(float val);

	float	getZ() const;
	void	setZ(float val);

	Vertex(float x, float y, float z);

	Vertex(void);
	Vertex(const Vertex &copy);
	Vertex &operator=(const Vertex &og);
	~Vertex(void);
}		;

#endif
