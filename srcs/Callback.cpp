/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:32:58 by raphael           #+#    #+#             */
/*   Updated: 2022/11/23 14:11:28 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Callback.hpp"

Callback::Callback()
{
}

Callback::~Callback()
{
}

std::vector<std::string>	&Callback::getReplys()
{
	return (this->_Replys);
}

std::vector<Message>	&Callback::getMessages()
{
	return (this->_Messages);
}
