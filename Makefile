SRCS_DIR =	srcs/

COMMAND = ACommand/

REPLY = AReply/

SRCS			= 	main.cpp \
					Server.cpp \
					Listener.cpp \
					Hub.cpp \
					User.cpp \
					Message.cpp \
					Sender.cpp \
					Replyer.cpp \
					Dispatcher.cpp \
					Receiver.cpp \
					CommandCreator.cpp \
					Callback.cpp \

SRCS_COMMAND	=	ACommand.cpp \
					Nick.cpp \
					UserCmd.cpp \

SRCS_REPLY		=	AReply.cpp \
					Rpl_Welcome.cpp \

#OBJS

OBJS_DIR = 	objs/

OBJS	= 	${SRCS:%.cpp=${OBJS_DIR}%.o} \
			${SRCS_COMMAND_ABS:%.cpp=${OBJS_DIR}%.o} \
			${SRCS_REPLY_ABS:%.cpp=${OBJS_DIR}%.o} \

SRCS_COMMAND_ABS = ${SRCS_COMMAND:%.cpp=${COMMAND}%.cpp}

SRCS_REPLY_ABS = ${SRCS_REPLY:%.cpp=${REPLY}%.cpp}

NAME	= exec

CC		= clang++

FLAGS	= -Wall -Wextra -Werror -std=c++98

INC_DIR = incs/

INCLUDES =	${INC_DIR}Server.hpp \
			${INC_DIR}Listener.hpp \
			${INC_DIR}Sender.hpp \
			${INC_DIR}Hub.hpp \
			${INC_DIR}User.hpp \
			${INC_DIR}Message.hpp \
			${INC_DIR}Replyer.hpp \
			${INC_DIR}AReply/AReply.hpp \
			${INC_DIR}AReply/Replyer.hpp \
			${INC_DIR}Rpl_Welcome.hpp \
			${INC_DIR}ACommand/ACommand.hpp \
			${INC_DIR}ACommand/Nick.hpp \
			${INC_DIR}ACommand/UserCmd.hpp \
			${INC_DIR}Dispatcher.hpp \
			${INC_DIR}Receiver.hpp \
			${INC_DIR}CommandCreator.hpp \
			${INC_DIR}Callback.hpp \


${OBJS_DIR}%.o:	${SRCS_DIR}%.cpp
				${CC} ${FLAGS} -c $< -o $@ -I.

all:		makedirs ${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

makedirs:
			@mkdir -p objs/ACommand
			@mkdir -p objs/AReply

clean:		
			rm -f ${OBJS}
			rm -rf objs

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY	= all clean fclean re makedirs