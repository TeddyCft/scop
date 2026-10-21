#-variables------------------------------------------------------------#

MAKEFLAGS += --no-print-directory
QUIET = @

NAME = 		scop
INCLUDES =	./includes ./src/class ./external/glad/include
CC = $(QUIET) c++
OPENGL_FLAGS = $(shell pkg-config --cflags --libs glfw3)
FLAGS = -Wall -Wextra -Werror
CLIENT_DIR = ./uploads

FILES =		main\
			errors\
			parsing/geometry\
			parsing/mtl\
			parsing/values\
			parsing/utils

CLASS		=	Face\
				Object\
				Vertex\
				Material

SRC_DIR		= 	src/
SRC_FILES	=	$(addsuffix .cpp, $(FILES)) \
				$(addprefix class/, $(addsuffix .cpp, $(CLASS)))
SRC 		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR		= 	obj/
OBJ			=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

GLAD_SRC = external/glad/src/glad.c
GLAD_OBJ = $(OBJ_DIR)external/glad/src/glad.o

#----------------------------------------------------------------------#

all : 			$(NAME)
				@ echo "\033[0;32m$(NAME)" "is ready !\033[0m" 

#-compil---------------------------------------------------------------#

$(NAME) :		$(OBJ_DIR) $(OBJ) $(GLAD_OBJ)
				$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES)) $(OBJ) $(GLAD_OBJ) -o $(NAME) $(OPENGL_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
				$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@ $(OPENGL_FLAGS)
$(GLAD_OBJ): $(GLAD_SRC)
	$(QUIET) mkdir -p $(dir $@)
	$(QUIET) cc -Wall -Wextra $(addprefix -I, $(INCLUDES)) -c $< -o $@

$(OBJ_DIR) :
				$(QUIET) mkdir -p $(OBJ_DIR)
				$(QUIET) mkdir -p $(OBJ_DIR)class
				$(QUIET) mkdir -p $(OBJ_DIR)parsing

#-rules----------------------------------------------------------------#

clean :			
				$(QUIET) rm -rf $(OBJ_DIR)
				$(QUIET) rm -rf $(CLIENT_DIR)
				
fclean : 		clean
				$(QUIET) rm -f $(NAME)
				
re : 
				$(MAKE) fclean
				$(MAKE)

.PHONY : all clean fclean re