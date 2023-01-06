/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Includereply.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:56:51 by raphael           #+#    #+#             */
/*   Updated: 2023/01/06 14:37:56 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDEREPLY_HPP
# define INCLUDEREPLY_HPP

#include "AReply.hpp"
# include "ERR_erroneusnickname.hpp"
# include "ERR_needmoreparams.hpp"
# include "ERR_nonicknamegiven.hpp"
# include "ERR_nicknameinuse.hpp"
# include "ERR_Toomanychannels.hpp"
# include "ERR_Channelisfull.hpp"
# include "ERR_Badchanmask.hpp"
# include "ERR_Nosuchchannel.hpp"
# include "ERR_notonchannel.hpp"

# include "RPL_Welcome.hpp"
# include "RPL_YourHost.hpp"
# include "RPL_Created.hpp"
# include "RPL_MyInfo.hpp"
# include "RPL_IsSupport.hpp"
# include "RPL_Topic.hpp"
# include "RPL_Namereply.hpp"
# include "RPL_Endofnames.hpp"
# include "RPL_Luserclient.hpp"
# include "RPL_Luserme.hpp"
# include "RPL_Motdstart.hpp"
# include "RPL_Motd.hpp"
# include "RPL_Endofmotd.hpp"
# include "ERR_Nosucherver.hpp"
# include "ERR_Nomotd.hpp"
# include "RPL_Liststart.hpp"
# include "RPL_List.hpp"
# include "RPL_Listend.hpp"
# include "ERR_Useronchannel.hpp"
# include "RPL_Inviting.hpp"
//include_here

#endif
