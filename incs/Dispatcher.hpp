/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:20 by raphael           #+#    #+#             */
/*   Updated: 2023/01/15 17:18:53 by marvin           ###   ########.fr       */
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

	std::map<User *, Message>	on_hold;

	int		TreatCommands(Callback &callback, User *sender);
	int		Execute(std::string const &cmdname, Message &);

	void PutUserCommandOnHold(User *user, Message &message);
	bool HasUserCommandOnHold(User *user);
	int	CheckUserCommandOnHold(Message &client_request, int returnValue);

	bool HoldConnectionProtocol(std::string const &, Message &);

public:
	Dispatcher(Sender &sender, Hub & hub);
	~Dispatcher();

	int	Execute(Message	& client_request);
};

#endif