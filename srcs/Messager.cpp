/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:19 by raphael           #+#    #+#             */
/*   Updated: 2022/11/24 11:44:25 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Messager.hpp"

Messager::Messager()
{
}

Messager::~Messager()
{
}

void	Messager::TreatMessages(Callback &callback)
{
	std::vector<Message>	Messages = callback.getMessages();
	for (std::vector<Message>::iterator it = Messages.begin();
		it != Messages.end(); it++)
	{
		this->Sendone((*it));
	}
	callback.resetMessages();
}

void	Messager::Sendone(Message &Message)
{
	this->_Sender.sendto(Message);
}