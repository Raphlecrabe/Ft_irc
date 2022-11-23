/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:20 by raphael           #+#    #+#             */
/*   Updated: 2022/11/23 14:13:47 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_HPP
# define DISPATCHER_HPP

# include "ACommand/Includecommand.hpp"
//# include "Messager.hpp"
# include "Replyer.hpp"
# include "CommandCreator.hpp"
# include <map>
# include <string>
# include "Hub.hpp"

class Dispatcher
{
private:
	Replyer					_Replyer;
	//Messager				_Messager;
	CommandCreator			_CommandCreator;
	Hub						_hub;

public:
	Dispatcher(Hub & hub);
	~Dispatcher();

	int	Execute(Message	& client_request);
};

#endif