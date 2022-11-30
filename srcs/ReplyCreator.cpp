/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:27:22 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/30 14:52:39 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ReplyCreator.hpp"

ReplyCreator::ReplyCreator()
{
	insert(&Welcome);
	insert(&YourHost);
	
	insert(&ERR_nicknameinuse);
	insert(&ERR_needmoreparams);
	insert(&ERR_erroneusnickname);
	insert(&ERR_nonicknamegiven);
}

ReplyCreator::~ReplyCreator()
{
}

void	ReplyCreator::insert(AReply	*newreply)
{
	_replys.insert(std::pair<std::string, AReply *>(newreply->getName(), newreply));
}

AReply	*ReplyCreator::getReplyByName(std::string &name) const
{
	AReply *reply;
	try
	{
		reply = _replys.at(name);
	}
	catch (std::exception &e)
	{
		reply = NULL;
		std::cout << "Could not find reply " + name << std::endl;
	}
	return (reply);
}
