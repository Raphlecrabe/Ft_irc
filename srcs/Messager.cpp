/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:19 by raphael           #+#    #+#             */
/*   Updated: 2022/11/23 11:14:22 by rmonacho         ###   ########lyon.fr   */
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
	this->Sender.Sendto(Message);
}