/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:41:02 by raphael           #+#    #+#             */
/*   Updated: 2022/11/17 17:10:54 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGER_HPP
# define MESSAGER_HPP

class Messager
{
private:
	Sender	_Sender;
	
public:
	Messager();
	~Messager();

	void	TreatMessages(std::vector<Message> Messages);
	void	Sendone(Message Message);
};

Messager::Messager()
{
}

Messager::~Messager()
{
}

Messager::TreatMessages(vector<Message> Messages)
{
	for (vector<Message>::iterator it = Messages.begin(); 
		it != Messages.end(); it++)
	{
		this->Sendone(*it);
	}
}

Messager::Sendone(Message	Message)
{
	this->Sender.Sendto(Message._destination._socket_fd, Message);
}

#endif