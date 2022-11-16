SRCS_DIR =	srcs/

SRCS	= 	main.cpp \
			Server.cpp \
			Channel.cpp \
			Sender.cpp \
			AReply.cpp \
			Rpl_Welcome.cpp \
			Replier.cpp \
			Format.cpp \

OBJS_DIR = 	objs/

OBJS	= ${SRCS:%.cpp=${OBJS_DIR}%.o}

NAME	= exec

CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

INC_DIR = incs/

INCLUDES =	${INC_DIR}Server.hpp \
			${INC_DIR}Channel.hpp \
			${INC_DIR}Sender.hpp \
			${INC_DIR}AReply.hpp \
			${INC_DIR}Format.hpp \
			${INC_DIR}Replier.hpp \
			${INC_DIR}Rpl_Welcome.hpp \

${OBJS_DIR}%.o:	${SRCS_DIR}%.cpp ${INCLUDES}
				mkdir -p objs
				${CC} ${FLAGS} -c $< -o $@ -I.

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:		
			rm -f ${OBJS}
			rm -rf objs

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY	= all clean fclean re