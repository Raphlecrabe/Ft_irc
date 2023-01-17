/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:24:13 by raphael           #+#    #+#             */
/*   Updated: 2023/01/16 18:41:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REPLYCREATOR_HPP
# define REPLYCREATOR_HPP

# include <map>
# include <string>
# include "AReply/Includereply.hpp"


class ReplyCreator
{
private:
	std::map<std::string, AReply *> _replys;

	RPL_Welcome				Welcome;
	RPL_YourHost 			YourHost;
	RPL_Topic				Topic;
	RPL_Namereply			Namereply;
	RPL_Endofnames			Endofnames;
	RPL_Created				Created;
	RPL_MyInfo				MyInfo;
	RPL_IsSupport			IsSupport;

	ERR_nicknameinuse		E_nicknameinuse;
	ERR_needmoreparams		E_needmoreparams;
	ERR_erroneusnickname	E_erroneusnickname;
	ERR_nonicknamegiven		E_nonicknamegiven;
	ERR_Toomanychannels		E_Toomanychannels;
	ERR_Channelisfull		E_Channelisfull;
	ERR_Badchanmask			E_Badchanmask;
	ERR_Nosuchchannel		E_Nosuchchannel;
	ERR_notonchannel		E_notonchannel;
	RPL_Luserclient rpl_luserclient;
	RPL_Luserme rpl_luserme;
	RPL_Motdstart rpl_motdstart;
	RPL_Motd rpl_motd;
	RPL_Endofmotd rpl_endofmotd;
	ERR_Nosucherver err_nosucherver;
	ERR_Nomotd err_nomotd;
	RPL_Liststart rpl_liststart;
	RPL_List rpl_list;
	RPL_Listend rpl_listend;
	ERR_Useronchannel err_useronchannel;
	RPL_Inviting rpl_inviting;
	ERR_Usernotinchannel err_usernotinchannel;
	ERR_Chanoprivsneeded err_chanoprivsneeded;
	ERR_Passwdmismatch err_passwdmismatch;
	RPL_Youreoper rpl_youreoper;
	ERR_Helpnotfound err_helpnotfound;
	RPL_Info rpl_info;
	RPL_Endofinfo rpl_endofinfo;
	Error error;
	ERR_AlreadyRegistered err_alreadyregistered;
	RPL_ChannelModeIs rpl_channelmodeis;
	//reply_here

	void	insert(AReply *newreply);
public:
	ReplyCreator();
	~ReplyCreator();

	AReply	*getReplyByName(std::string &name) const;

};

#endif
