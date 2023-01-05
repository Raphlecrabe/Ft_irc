/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:41:02 by raphael           #+#    #+#             */
/*   Updated: 2022/12/14 13:49:17 by fbelthoi         ###   ########.fr       */
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
	Sender	_sender;
	
public:
	Messager(Sender &);
	~Messager();

	void	TreatMessages(Callback	&callback);
	void	Sendone(Message &Message);
};

#endif