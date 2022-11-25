/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:20 by raphael           #+#    #+#             */
/*   Updated: 2022/11/23 16:05:36 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_HPP
# define DISPATCHER_HPP

# include "ACommand/Includecommand.hpp"
# include "Messager.hpp"
# include "Replyer.hpp"
# include "CommandCreator.hpp"
# include <map>
# include <string>
# include "Hub.hpp"

class Dispatcher
{
private:
	Messager				_Messager;
	CommandCreator			_CommandCreator;
	Hub						&_hub;
	Replyer					_Replyer;

public:
	Dispatcher(Hub & hub);
	~Dispatcher();

	int	Execute(Message	& client_request);
};

#endif