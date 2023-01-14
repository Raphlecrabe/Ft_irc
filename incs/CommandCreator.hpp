/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:08:32 by raphael           #+#    #+#             */
/*   Updated: 2023/01/13 13:58:37 by fbelthoi         ###   ########.fr       */
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
	Quit	quit;
	Help	help;
	Info	info;
	Privmsg    privmsg;
	//cmd_here

	void insert(ACommand *);

public:
	CommandCreator();
	~CommandCreator();

	ACommand * getCommandByName(std::string const &name) const;
};

#endif
