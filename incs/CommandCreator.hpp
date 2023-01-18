/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:08:32 by raphael           #+#    #+#             */
/*   Updated: 2023/01/18 13:56:42 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDCREATOR_HPP
# define COMMANDCREATOR_HPP

# include "ACommand/Includecommand.hpp"
# include <map>
# include <string>

class CommandCreator
{
private:
	std::map<std::string, ACommand *> _commands;

	Nick nick;
	UserCmd usercmd;
	Ping	ping;
	Cap		cap;
	Join	join;
	Part	part;
	Topic	topic;
	Motd	motd;
	Lusers	lusers;
	Pass	pass;
	Mode	mode;
	Names	names;
	List	list;
	Invite	invite;
	Kick	kick;
	Oper	oper;
	Help	help;
	Info	info;
	Privmsg    privmsg;
	Quit    quit;
	Notice    notice;
	Kill    kill;
	//cmd_here

	void insert(ACommand *);

public:
	CommandCreator();
	~CommandCreator();

	ACommand * getCommandByName(std::string const &name) const;
};

#endif
