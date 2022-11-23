/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:20:07 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/23 14:09:45 by fbelthoi         ###   ########.fr       */
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
	public:
		ACommand(std::string name);
		virtual	~ACommand();

		std::string	getName();
		virtual	Callback	*cmdExecute(Message & message, Hub & hub) = 0;
};

#endif