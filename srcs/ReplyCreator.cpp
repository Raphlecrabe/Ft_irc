/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:27:22 by rmonacho          #+#    #+#             */
/*   Updated: 2023/01/06 14:38:14 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ReplyCreator.hpp"
#include "../incs/AReply/Includereply.hpp"

ReplyCreator::ReplyCreator()
{
	insert(&Welcome);
	insert(&YourHost);
	insert(&Topic);
	insert(&Namereply);
	insert(&Endofnames);
	insert(&Created);
	insert(&MyInfo);
	insert(&IsSupport);
	
	insert(&ERR_nicknameinuse);
	insert(&ERR_needmoreparams);
	insert(&ERR_erroneusnickname);
	insert(&ERR_nonicknamegiven);
	insert(&ERR_Toomanychannels);
	insert(&ERR_Channelisfull);
	insert(&ERR_Badchanmask);
	insert(&ERR_Nosuchchannel);
	insert(&ERR_notonchannel);
	insert(&rpl_luserclient);
	insert(&rpl_luserme);
	insert(&rpl_motdstart);
	insert(&rpl_motd);
	insert(&rpl_endofmotd);
	insert(&err_nosucherver);
	insert(&err_nomotd);
	insert(&rpl_liststart);
	insert(&rpl_list);
	insert(&rpl_listend);
	insert(&err_useronchannel);
	insert(&rpl_inviting);
	//insert_here;
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
		std::cout << "Could not find reply " + name << std::endl;
		return NULL;
	}
	return (reply);
}
