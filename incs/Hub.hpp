/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hub.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:43:46 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/23 11:03:44 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUB_HPP
# define HUB_HPP

# include <vector>
# include "User.hpp"
# include "Channel.hpp"
# include "Operator.hpp"

class Hub
{
private:
	std::vector<User>	_server_users;
	std::vector<Channel>	_server_channels;
	std::vector<Operator>	_server_operators;
public:
	Hub();
	~Hub();

	std::vector<User>		&get_users();
	std::vector<Channel>	&get_channels();
	std::vector<Operator>	&get_operators();
	void					addUser(User &new_user);
	void					addChannel(Channel &new_channel);
	void					addOperator(Operator &new_operator);
};

#endif