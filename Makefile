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
					Channel.cpp \
					Messager.cpp \
					ReplyCreator.cpp \
					Debug.cpp \
					Utils.cpp \

SRCS_COMMAND	=	ACommand.cpp \
					Topic.cpp  \
					Part.cpp  \
					Join.cpp  \
					Nick.cpp \
					UserCmd.cpp \
					Cap.cpp \
					Ping.cpp \
					#NEW_CMD_HERE

#OBJS

OBJS_DIR = 	objs/

OBJS	= 	${SRCS:%.cpp=${OBJS_DIR}%.o} \
			${SRCS_COMMAND_ABS:%.cpp=${OBJS_DIR}%.o} \

SRCS_COMMAND_ABS = ${SRCS_COMMAND:%.cpp=${COMMAND}%.cpp}

NAME	= exec

CC		= clang++

FLAGS	= -Wall -Wextra -Werror -std=c++98

SANITIZE = -fsanitize=address -g3

INC_DIR = incs

HEADERS =		Debug.hpp \
				Server.hpp \
				Listener.hpp \
				Sender.hpp \
				Hub.hpp \
				User.hpp \
				Message.hpp \
				Replyer.hpp \
				AReply/AReply.hpp \
				ACommand/ACommand.hpp \
				Dispatcher.hpp \
				Receiver.hpp \
				CommandCreator.hpp \
				Callback.hpp \
				ReplyCreator.hpp \
				Messager.hpp \

COMMANDS =		ACommand.hpp \
				Includecommand.hpp \
				#NEW_CMDHPP_HERE

REPLIES =		AReply.hpp \
				Includereply.hpp \
				ERR_erroneusnickname.hpp \
				ERR_needmoreparams.hpp \
				ERR_nicknameinuse.hpp \
				ERR_nonicknamegiven.hpp \
				ERR_notonchannel.hpp \
				ERR_Nosuchchannel.hpp \
				RPL_Created.hpp \
				RPL_IsSupport.hpp \
				RPL_MyInfo.hpp \
				RPL_Welcome.hpp \
				RPL_YourHost.hpp \
				RPL_Topic.hpp \
				RPL_Luserclient.hpp \
				RPL_Luserme.hpp \
				#NEW_REPLY_HERE

INCS_HEADERS = ${HEADERS:%=${INC_DIR}/%}

INCS_REPLIES = 	${REPLIES:%=${INC_DIR}/AReply/%}

INCLUDES = ${INCS_HEADERS} \
			${INCS_REPLIES}

${OBJS_DIR}%.o:	${SRCS_DIR}%.cpp ${INCLUDES}
				${CC} ${FLAGS} -c $< -o $@ -I.

all:		makedirs ${NAME}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${SANITIZE} ${OBJS} -o ${NAME}

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
