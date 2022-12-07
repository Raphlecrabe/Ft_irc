/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:24:13 by raphael           #+#    #+#             */
/*   Updated: 2022/12/01 15:37:14 by rmonacho         ###   ########lyon.fr   */
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

	ERR_nicknameinuse		ERR_nicknameinuse;
	ERR_needmoreparams		ERR_needmoreparams;
	ERR_erroneusnickname	ERR_erroneusnickname;
	ERR_nonicknamegiven		ERR_nonicknamegiven;
	ERR_Toomanychannels		ERR_Toomanychannels;
	ERR_Channelisfull		ERR_Channelisfull;
	ERR_Badchanmask			ERR_Badchanmask;

	void	insert(AReply *newreply);
public:
	ReplyCreator();
	~ReplyCreator();

	AReply	*getReplyByName(std::string &name) const;

};

#endif