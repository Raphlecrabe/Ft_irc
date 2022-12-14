/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:38:18 by rmonacho          #+#    #+#             */
/*   Updated: 2022/12/14 15:42:45 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICK_HPP
# define NICK_HPP

# include "ACommand.hpp"
# include "../Hub.hpp"
# include <string>
# include <vector>
# include <cctype>

class Nick : public ACommand
{
private:
	void	wrong_password();

public:
	Nick();
	~Nick();

	Callback	&cmdExecute(Message & message, Hub & hub);
	int	check_nick(std::string &nickname, Hub & hub, Callback &callback);
	int	used_nick(std::string &nickname, Hub &hub, Callback &callback);
	int	wrong_nick(std::string &nickname, Callback &callback);
	int	empty_nick(std::string &nickname, Callback &callback);
	int	apply_change(std::string &nickname, Hub &hub);
	std::string	const &get_nickname(Message &message);
};

#endif