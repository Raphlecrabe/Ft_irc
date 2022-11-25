/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:26:31 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/24 13:29:17 by rmonacho         ###   ########lyon.fr   */
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

Callback	&ACommand::getCallback()
{
	return (_callback);
}
