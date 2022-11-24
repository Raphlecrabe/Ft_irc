/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:46:44 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/24 11:21:49 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/CommandCreator.hpp"

CommandCreator::CommandCreator()
{
	_commands.insert(std::pair<std::string, ACommand *>(nick.getName(), &nick));
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