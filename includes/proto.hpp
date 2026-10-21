#ifndef PROTO_HPP
#define PROTO_HPP

#include <iostream>

int		manage_error(int errtype);
int		check_args(int ac, char **av);

// PARSING

void	parse_obj(Object &obj, std::string filepath);
void	parse_vertex(Object &obj, std::string line);
void	parse_normal(Object &obj, std::string line);
void	parse_texture(Object &obj, std::string line);
void	parse_face(Object &obj, std::string line);
void	parse_mtllib(Object &obj, std::string line);
void	set_currmtl(Object &obj, std::string line);

void	checkValues(Object &obj);

#endif