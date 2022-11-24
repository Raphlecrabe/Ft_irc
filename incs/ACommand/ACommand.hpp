/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:20:07 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/24 13:25:00 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOMMAND_HPP
# define ACOMMAND_HPP

# include <string>
# include "../Callback.hpp"
# include "../Hub.hpp"

class ACommand
{
	private:
		std::string	_name;
		Callback	_callback;
	public:
		ACommand(std::string name);
		virtual	~ACommand();

		std::string	getName();
		Callback	&getCallback();
		virtual	Callback	&cmdExecute(Message & message, Hub & hub) = 0;
};

#endif