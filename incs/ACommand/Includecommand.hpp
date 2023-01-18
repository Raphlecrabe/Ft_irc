/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Includecommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:53:48 by raphael           #+#    #+#             */
/*   Updated: 2023/01/18 13:57:07 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDECOMMAND_HPP
# define INCLUDECOMMAND_HPP

# include "ACommand.hpp"
//Include de toutes les Acommands pour pouvoir les includes
//Dans les messager et Replyer facilement
# include "Nick.hpp"
# include "UserCmd.hpp"
# include "Ping.hpp"
# include "Cap.hpp"
# include "Join.hpp"
# include "Part.hpp"
# include "Topic.hpp"
# include "Motd.hpp"
# include "Lusers.hpp"
# include "Pass.hpp"
# include "Mode.hpp"
# include "Names.hpp"
# include "List.hpp"
# include "Invite.hpp"
# include "Kick.hpp"
# include "Oper.hpp"
# include "Help.hpp"
# include "Info.hpp"
# include "Privmsg.hpp"
# include "Quit.hpp"
# include "Notice.hpp"
# include "Kill.hpp"
//include_here

#endif
