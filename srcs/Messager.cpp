/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:19 by raphael           #+#    #+#             */
/*   Updated: 2023/01/19 16:12:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Messager.hpp"

Messager::Messager(Sender &sender) : _sender(sender)
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
		
	std::vector<Message>::iterator it;

	for (it = Messages.begin(); it != Messages.end(); it++)
	{
		this->Sendone((*it));
	}
	
	callback.resetMessages();
}

void	Messager::Sendone(Message message)
{
	Debug::Log << "Messager: Sendone: " << message.Format();

	this->_sender.sendto(message);
}