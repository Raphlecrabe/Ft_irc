/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:19 by raphael           #+#    #+#             */
/*   Updated: 2023/01/14 17:47:19 by marvin           ###   ########.fr       */
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

	try {
		this->_sender.sendto(message);
	} catch (std::exception &e) {
		Debug::Log << e.what() << std::endl;
		std::cout << e.what() << std::endl;
	}
}