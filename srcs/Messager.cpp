/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:19 by raphael           #+#    #+#             */
/*   Updated: 2022/11/18 10:05:44 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Messager.hpp"

Messager::Messager()
{
}

Messager::~Messager()
{
}

void	Messager::TreatMessages(std::vector<Message> Messages)
{
	for (std::vector<Message>::iterator it = Messages.begin(); 
		it != Messages.end(); it++)
	{
		this->Sendone(*it);
	}
}

Messager::Sendone(Message	Message)
{
	this->Sender.Sendto(Message._destination._socket_fd, Message);
}