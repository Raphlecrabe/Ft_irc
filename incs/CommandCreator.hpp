/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:08:32 by raphael           #+#    #+#             */
/*   Updated: 2022/11/30 14:27:18 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDCREATOR_HPP
# define COMMANDCREATOR_HPP

# include "ACommand/Includecommand.hpp"
# include <map>
# include <string>

class CommandCreator
{
private:
	std::map<std::string, ACommand *> _commands;

	Nick nick;
	UserCmd usercmd;
	Ping	ping;
	Cap		cap;

	void insert(ACommand *);

public:
	CommandCreator();
	~CommandCreator();

	ACommand * getCommandByName(std::string &name) const;
};

#endif