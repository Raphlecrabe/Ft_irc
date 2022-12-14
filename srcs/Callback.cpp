/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:32:58 by raphael           #+#    #+#             */
/*   Updated: 2022/12/14 15:12:23 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Callback.hpp"

Callback::Callback()
{
}

Callback::~Callback()
{
}

std::vector< s_pair >	const		&Callback::getReplys() const { return (this->_Replys); }
std::vector<Message>		const	&Callback::getMessages() const { return (this->_Messages); }
std::vector<std::string> 	const	&Callback::getCommands() const { return (this->_Commands); }

void	Callback::addMessage(Message &message)
{
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