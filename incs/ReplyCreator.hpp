/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplyCreator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:24:13 by raphael           #+#    #+#             */
/*   Updated: 2022/11/29 16:06:52 by fbelthoi         ###   ########.fr       */
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

	RPL_Welcome	Welcome;
	RPL_YourHost YourHost;

	std::pair<std::string, AReply *> makePair(AReply *reply);

public:
	ReplyCreator();
	~ReplyCreator();

	AReply	*getReplyByName(std::string &name) const;
};

#endif