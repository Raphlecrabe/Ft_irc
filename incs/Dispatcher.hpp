/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatcher.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:28:20 by raphael           #+#    #+#             */
/*   Updated: 2022/11/18 15:10:13 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_HPP
# define DISPATCHER_HPP

# include "ACommand/Includecommand.hpp"

class Dispatcher
{
private:
	std::map<string, ACommand>	*_Commands;
	Replyer					_Replyer;
	Messager				_Messager:
	CommandCreator			_CommandCreator;
public:
	Dispatcher();
	~Dispatcher();

	int	Execute(Message	client_request, Hub hub);
};

#endif