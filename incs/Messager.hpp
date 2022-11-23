/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:41:02 by raphael           #+#    #+#             */
/*   Updated: 2022/11/22 11:11:18 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGER_HPP
# define MESSAGER_HPP

# include "Sender.hpp"
# include "Message.hpp"
# include <vector>

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

#endif