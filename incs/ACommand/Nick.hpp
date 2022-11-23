/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:38:18 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/22 15:53:18 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICK_HPP
# define NICK_HPP

# include "ACommand.hpp"
# include "Hub.hpp"
# include <string>
# include <vector>
# include <cctype>

class Nick : ACommand
{
private:

public:
	~Nick();

	virtual	Callback	*getmsg(Message message, Hub hub);
	int	check_nick(std::string nickname, Hub hub);
	int	used_nick(std::string nickname, Hub hub);
	int	wrong_nick(std::string nickname);
	int	empty_nick(std::string nickname);
	int	apply_change(std::string nickname, Hub hub);
	std::string	get_nickname(Message message);
};

#endif