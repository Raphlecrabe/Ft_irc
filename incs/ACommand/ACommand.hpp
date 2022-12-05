/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:20:07 by rmonacho          #+#    #+#             */
/*   Updated: 2022/12/02 16:45:26 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOMMAND_HPP
# define ACOMMAND_HPP

# include <string>
# include "../Callback.hpp"
# include "../Hub.hpp"
# include "../Utils.hpp"

class ACommand
{
	private:
		std::string	_name;

	protected:
		Callback	_callback;
	
	public:
		ACommand(std::string name);
		virtual	~ACommand();

		std::string	getName();
		Callback	&getCallback();
		virtual	Callback	&cmdExecute(Message & message, Hub & hub) = 0;
};

#endif