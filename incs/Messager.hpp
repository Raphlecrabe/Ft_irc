/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:41:02 by raphael           #+#    #+#             */
/*   Updated: 2022/11/24 11:44:28 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGER_HPP
# define MESSAGER_HPP

# include "Sender.hpp"
# include "Message.hpp"
# include <vector>
# include "Callback.hpp"

class Messager
{
private:
	Sender	_Sender;
	
public:
	Messager();
	~Messager();

	void	TreatMessages(Callback	&callback);
	void	Sendone(Message &Message);
};

#endif