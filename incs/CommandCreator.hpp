/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandCreator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:08:32 by raphael           #+#    #+#             */
/*   Updated: 2022/12/05 14:04:29 by rmonacho         ###   ########lyon.fr   */
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
	Join	join;
	Part	part;
	Topic	topic;

	void insert(ACommand *);

public:
	CommandCreator();
	~CommandCreator();

	ACommand * getCommandByName(std::string &name) const;
};

#endif