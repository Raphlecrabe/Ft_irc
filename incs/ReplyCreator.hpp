/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:24:13 by raphael           #+#    #+#             */
/*   Updated: 2022/11/25 13:12:35 by rafy             ###   ########.fr       */
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
public:
	ReplyCreator();
	~ReplyCreator();

	AReply	*getReplyByName(std::string &name) const;
};

#endif