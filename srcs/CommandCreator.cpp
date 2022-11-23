/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:46:44 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/23 13:10:35 by fbelthoi         ###   ########.fr       */
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

ACommand * CommandCreator::getCommandByName(std::string name)
{
	ACommand *cmd;

	try {
		cmd = _commands.at(name);
	} catch (std::exception &e) {
		cmd = NULL;
	}

	return cmd;
}