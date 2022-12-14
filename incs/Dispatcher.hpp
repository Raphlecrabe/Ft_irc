/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:20 by raphael           #+#    #+#             */
/*   Updated: 2022/12/14 13:48:49 by fbelthoi         ###   ########.fr       */
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
	CommandCreator			_CommandCreator;
	Hub						&_hub;
	Replyer					_Replyer;
	Messager				_Messager;

	int		TreatCommands(Callback &callback, User *sender);
	int		Execute(std::string const &cmdname, Message &);

public:
	Dispatcher(Sender &sender, Hub & hub);
	~Dispatcher();

	int	Execute(Message	& client_request);
};

#endif