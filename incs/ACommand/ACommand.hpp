/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:20:07 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/25 14:00:23 by marvin           ###   ########.fr       */
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