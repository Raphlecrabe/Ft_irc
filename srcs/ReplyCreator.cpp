/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:27:22 by rmonacho          #+#    #+#             */
/*   Updated: 2023/01/16 10:16:21 by raphael          ###   ########.fr       */
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
	
	insert(&E_nicknameinuse);
	insert(&E_needmoreparams);
	insert(&E_erroneusnickname);
	insert(&E_nonicknamegiven);
	insert(&E_Toomanychannels);
	insert(&E_Channelisfull);
	insert(&E_Badchanmask);
	insert(&E_Nosuchchannel);
	insert(&E_notonchannel);
	insert(&rpl_luserclient);
	insert(&rpl_luserme);
	insert(&rpl_motdstart);
	insert(&rpl_motd);
	insert(&rpl_endofmotd);
	insert(&err_nosucherver);
	insert(&err_nomotd);
	insert(&err_channelmodeis);
	insert(&rpl_liststart);
	insert(&rpl_list);
	insert(&rpl_listend);
	insert(&err_useronchannel);
	insert(&rpl_inviting);
	insert(&err_usernotinchannel);
	insert(&err_chanoprivsneeded);
	insert(&err_passwdmismatch);
	insert(&rpl_youreoper);
	insert(&err_helpnotfound);
	insert(&rpl_info);
	insert(&rpl_endofinfo);
	insert(&error);
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
