/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:46:44 by rmonacho          #+#    #+#             */
/*   Updated: 2023/01/13 14:05:48 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/CommandCreator.hpp"

CommandCreator::CommandCreator()
{
	insert(&nick);
	insert(&usercmd);
	insert(&ping);
	insert(&cap);
	insert(&join);
	insert(&part);
	insert(&topic);
	insert(&motd);
	insert(&lusers);
	insert(&pass);
	insert(&mode);
	insert(&names);
	insert(&list);
	insert(&invite);
	insert(&kick);
	insert(&oper);
	insert(&quit);
	insert(&help);
	insert(&info);
	insert(&privmsg);
	insert(&quit);
	insert(&notice);
	//insert_here
}

void CommandCreator::insert(ACommand *cmd) {
	_commands.insert(std::pair<std::string, ACommand *>(cmd->getName(), cmd));
}

CommandCreator::~CommandCreator()
{
}

ACommand * CommandCreator::getCommandByName(std::string const &name) const
{
	ACommand *cmd;

	try {
		cmd = _commands.at(name);
	} catch (std::exception &e) {
		return NULL;
	}

	return cmd;
}
