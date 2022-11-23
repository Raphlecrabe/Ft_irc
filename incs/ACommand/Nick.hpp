/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:38:18 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/23 14:01:25 by fbelthoi         ###   ########.fr       */
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

public:
	Nick();
	~Nick();

	Callback	*cmdExecute(Message & message, Hub & hub);
	int	check_nick(std::string nickname, Hub & hub);
	int	used_nick(std::string nickname, Hub hub);
	int	wrong_nick(std::string nickname);
	int	empty_nick(std::string nickname);
	int	apply_change(std::string nickname, Hub hub);
	std::string	get_nickname(Message message);
};

#endif