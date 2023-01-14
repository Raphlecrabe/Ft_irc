/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:38:18 by rmonacho          #+#    #+#             */
/*   Updated: 2023/01/14 18:53:59 by marvin           ###   ########.fr       */
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
	void	stop_connection(User *user, Hub &hub);

	int	check_nick(std::string &nickname, Hub & hub, Callback &callback);
	int	used_nick(std::string &nickname, Hub &hub, Callback &callback);
	int	wrong_nick(std::string &nickname, Callback &callback);
	int	empty_nick(std::string &nickname, Callback &callback);
	int	apply_change(std::string &nickname, Hub &hub);
	std::string	const &get_nickname(Message &message);
public:
	Nick();
	~Nick();

	Callback	&cmdExecute(Message & message, Hub & hub);
};

#endif