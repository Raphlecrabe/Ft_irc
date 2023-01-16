/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:32:58 by raphael           #+#    #+#             */
/*   Updated: 2023/01/15 17:19:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Callback.hpp"

Callback::Callback() : _stop(false) {
	
}

Callback::~Callback()
{
}

std::vector< s_pair >	const		&Callback::getReplys() const { return (this->_Replys); }
std::vector<Message>		const	&Callback::getMessages() const { return (this->_Messages); }
std::vector<std::string> 	const	&Callback::getCommands() const { return (this->_Commands); }
bool								Callback::askForStop() const { return (this->_stop); }
void								Callback::setStop(bool b) { this->_stop = b; }

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