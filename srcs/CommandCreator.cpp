/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:46:44 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/25 13:56:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/CommandCreator.hpp"

CommandCreator::CommandCreator()
{
	insert(&nick);
	insert(&usercmd);
}

void CommandCreator::insert(ACommand *cmd) {
	_commands.insert(std::pair<std::string, ACommand *>(cmd->getName(), cmd));
}

CommandCreator::~CommandCreator()
{
}

ACommand * CommandCreator::getCommandByName(std::string &name) const
{
	ACommand *cmd;

	try {
		cmd = _commands.at(name);
	} catch (std::exception &e) {
		cmd = NULL;
	}

	return cmd;
}