/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:44:20 by rmonacho          #+#    #+#             */
/*   Updated: 2023/01/19 11:19:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ACommand/ACommand.hpp"
#include "../../incs/ACommand/Nick.hpp"
#include "../../incs/Callback.hpp"

Nick::Nick() : ACommand("NICK") {
	
}

Nick::~Nick() {
	
}

Callback	&Nick::cmdExecute(Message & message, Hub & hub)
{
	std::string nickname = message.getParams();

	if (check_nick(nickname, hub, this->getCallback()) == -1)
		return this->_callback;

	std::string param = nickname;
	
	Message newmessage;
	if (message.getSender()->NicknameIsSet() == false)
	{
		newmessage = Message(hub.getServerName(), "NICK", param);
	} else {
		newmessage = Message(message.getSender()->getNickname(), "NICK", param);
		message.getSender()->addAllConnectedUsersToMessage(newmessage);
	}
	
	newmessage.addDestinator(message.getSender());
	_callback.addMessage(newmessage);

	message.getSender()->setNickname(nickname);

	Debug::Log << "Nick : nickname has been set to : " << message.getSender()->getNickname() << std::endl;

	return (this->_callback);
}

int	Nick::check_nick(std::string &nickname, Hub & hub, Callback &callback)
{
	if (empty_nick(nickname, callback) == -1)
	{
		return (-1);
	}
	if (wrong_nick(nickname, callback) == -1)
	{
		return (-1);
	}
	if (used_nick(nickname, hub, callback) == -1)
	{
		return (-1);
	}
	return 0;
}

int	Nick::used_nick(std::string &nickname, Hub &hub, Callback &callback)
{
	std::vector<User *> _userlist = hub.getUserList();

	if (_userlist.size() == 0)
		return 0;

	std::vector<User *>::iterator it;

	for (it = _userlist.begin(); it != _userlist.end(); it++)
	{
		if ((*it)->getNickname() == nickname)
		{
			std::string	reply = "ERR_NICKNAMEINUSE";
			callback.addReply(reply, nickname);
			return (-1);
		}
	}
	return (0);
}

int	Nick::wrong_nick(std::string &nickname, Callback &callback)
{
	int size = nickname.size();
	
	for (int i = 0; i < size - 1; i++)
	{
		if (std::isalnum(nickname[i]) == 0)
		{
			std::string	reply = "ERR_ERRONEUSNICKNAME";
			callback.addReply(reply, nickname);
			return (-1);
		}
	}
	return (0);
}

int	Nick::empty_nick(std::string &nickname, Callback &callback)
{
	if (nickname.empty() == 1)
	{
		std::string	reply = "ERR_NONICKNAMEGIVEN";
		callback.addReply(reply);
		return (-1);
	}
	return (0);
}