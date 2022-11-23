/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:26:31 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/23 14:09:25 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ACommand/ACommand.hpp"
#include "../../incs/Hub.hpp"

ACommand::ACommand(std::string name) : _name(name)
{
}

ACommand::~ACommand()
{
}

std::string	ACommand::getName()
{
	return (_name);
}
