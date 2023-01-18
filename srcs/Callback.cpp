/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:32:58 by raphael           #+#    #+#             */
/*   Updated: 2023/01/18 16:50:43 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Callback.hpp"

Callback::Callback() : _userToDelete(NULL) {
	
}

Callback::~Callback()
{
}

std::vector< s_pair >	const		&Callback::getReplys() const { return (this->_Replys); }
std::vector<Message>		const	&Callback::getMessages() const { return (this->_Messages); }
std::vector<std::string> 	const	&Callback::getCommands() const { return (this->_Commands); }
User *								Callback::GetUserToDelete() const { return (this->_userToDelete); }
void								Callback::setUserDelete(User *u) { this->_userToDelete = u; }

void	Callback::addMessage(Message &message)
{
	Debug::Log << "Callback: adding message " << message.Format();
	_Messages.push_back(message);
}

void	Callback::addReply(std::string reply)
{
	s_pair p(reply, "");
	_Replys.push_back(p);
}

void	Callback::addReply(std::string reply, std::string param)
{
	s_pair p(reply, param);
	_Replys.push_back(p);
}

void	Callback::addCommand(std::string cmd)
{
	_Commands.push_back(cmd);
}

void	Callback::resetReplys()
{
	_Replys.clear();
}

void	Callback::resetMessages()
{
	_Messages.clear();
}

void	Callback::resetCommands() { _Commands.clear(); }