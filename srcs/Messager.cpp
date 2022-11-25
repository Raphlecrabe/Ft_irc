/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:19 by raphael           #+#    #+#             */
/*   Updated: 2022/11/25 13:42:30 by rafy             ###   ########.fr       */
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
	if (Messages.size() == 0)
		return ;
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