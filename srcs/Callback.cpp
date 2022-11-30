/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:32:58 by raphael           #+#    #+#             */
/*   Updated: 2022/11/30 13:59:23 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Callback.hpp"

Callback::Callback()
{
}

Callback::~Callback()
{
}

std::vector<std::string>	const	&Callback::getReplys() const
{
	return (this->_Replys);
}

std::vector<Message>	const	&Callback::getMessages() const
{
	return (this->_Messages);
}

void	Callback::addMessage(Message &message)
{
	_Messages.push_back(message);
}

void	Callback::addReply(std::string reply)
{
	_Replys.push_back(reply);
}

void	Callback::resetReplys()
{
	_Replys.clear();
}

void	Callback::resetMessages()
{
	_Messages.clear();
}