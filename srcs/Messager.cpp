/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:19 by raphael           #+#    #+#             */
/*   Updated: 2022/12/12 11:55:30 by fbelthoi         ###   ########.fr       */
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

void	Messager::Sendone(Message &message)
{
	try {
		this->_Sender.sendto(message);
	} catch (std::exception &e) {
		Debug::Log(e.what());
		std::cout << e.what() << std::endl;
	}
}