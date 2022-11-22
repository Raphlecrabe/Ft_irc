/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:24:13 by raphael           #+#    #+#             */
/*   Updated: 2022/11/18 15:22:01 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLYCREATOR_HPP
# define REPLYCREATOR_HPP

class ReplyCreator
{
private:
	
public:
	ReplyCreator();
	~ReplyCreator();

	std::map<std::string, AReply>	*CreateReplys();
};

ReplyCreator::ReplyCreator()
{
}

ReplyCreator::~ReplyCreator()
{
}

std::map<std::string, AReply>	*CreateReplys()
{
}

#endif