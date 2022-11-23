/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hub.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:52:57 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/22 12:57:39 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Hub.hpp"

Hub::Hub()
{
}

Hub::~Hub()
{
}

std::vector<User>	&Hub::get_users();
{
	return (_server_users);
}

std::vector<Channel>	&Hub::get_channels()
{
	return (_server_channels);
}

std::vector<Operator>	&Hub::get_operators()
{
	return (_server_operators);
}

void	Hub::addUser(User &new_user)
{
	_server_users.push_back(new_user);
}

void	Hub::addChannel(Channel &new_channel)
{
	_server_channels.push_back(new_channel);
}

void	Hub::addOperator(Operator &new_operator)
{
	_server_operators.push_back(new_operator);
}