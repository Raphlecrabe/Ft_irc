/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:08:32 by raphael           #+#    #+#             */
/*   Updated: 2022/11/18 14:57:25 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDCREATOR_HPP
# define COMMANDCREATOR_HPP

# include "ACommand/Includecommand.hpp"

class CommandCreator
{
private:
	
public:
	CommandCreator();
	~CommandCreator();

	std::map<string, ACommand>	*CreateCommand();
};

CommandCreator::CommandCreator()
{
}

CommandCreator::~CommandCreator()
{
}

std::map<string, ACommand>	*CommandCreator::CreateCommands()
{
	
}

#endif