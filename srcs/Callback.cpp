/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:32:58 by raphael           #+#    #+#             */
/*   Updated: 2022/11/30 14:48:42 by fbelthoi         ###   ########.fr       */
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

std::vector<std::string>	const	&Callback::getReplyParams() const
{
	return (this->_Replyparams);
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

void	Callback::addReplyparam(std::string &param)
{
	_Replyparams.push_back(param);
}

void	Callback::resetReplys()
{
	_Replys.clear();
}

void	Callback::resetMessages()
{
	_Messages.clear();
}

void	Callback::resetReplyparams()
{
	_Replyparams.clear();
}