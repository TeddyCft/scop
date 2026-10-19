#ifndef STRUCT_HPP
#define STRUCT_HPP

typedef struct t_vertface
{
	int vertex;
	int texture;
	int normal;

} s_vertface;

typedef enum t_vertface_enum
{
	VF_VERT,
	VF_TEXT,
	VF_NORM,
} e_vertface;

typedef struct t_uv
{
	float x;
	float y;
} s_uv;

typedef struct t_clr
{
	float	r;
	float	g;
	float	b;
} s_clr;

typedef struct t_clra
{
	float	r;
	float	g;
	float	b;
	float	a;
} s_clra;

#endif