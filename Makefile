NAME		:=	AID5

OBJ_FOLDER	:=	obj
SRC_FOLDER	:=	src

CC			:=	c++

SRCS		:=	test.cpp \
				testPunkt2D.cpp \
				testPunkt3D.cpp \
				testKreis.cpp \
				testStrecke3D.cpp \
				Punkt2D.cpp \
				Punkt3D.cpp \
				Kreis.cpp \
				Strecke3D.cpp

OBJS		:=	$(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)

CFLAGS		=	-Wall -Werror -Wextra -std=c++98 -Wfatal-errors -Wconversion
DFLAG		:=	-g -D DEBUG=1

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

debug:	CFLAGS += $(DFLAG)
debug:	all
		./$(NAME)


clean:
	rm -fr $(OBJ_FOLDER)

fclean: clean
	rm -fr $(NAME) $(NAME).dSYM docu

re: fclean all


val:
	valgrind --leak-check=full -s ./$(NAME)


.PHONY: clean fclean re val $(NAME)
