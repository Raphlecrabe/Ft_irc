/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:24:13 by raphael           #+#    #+#             */
/*   Updated: 2022/11/28 11:43:29 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLYCREATOR_HPP
# define REPLYCREATOR_HPP

# include <map>
# include <string>
# include "AReply/Includereply.hpp"


class ReplyCreator
{
private:
	std::map<std::string, AReply *> _replys;
	Rpl_Welcome	Welcome;
	Pong		Pong;
	Err_nicknameinuse	Err_nicknameinuse;
	Err_needmoreparams	Err_needmoreparams;
	Err_erroneusnickname	Err_erroneusnickname;
	Err_nonicknamegiven		Err_nonicknamegiven;

	void	insert(AReply *newreply);
public:
	ReplyCreator();
	~ReplyCreator();

	AReply	*getReplyByName(std::string &name) const;

};

#endif