/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:26:32 by raphael           #+#    #+#             */
/*   Updated: 2022/11/24 13:57:24 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLBACK_HPP
# define CALLBACK_HPP

# include <vector>
# include <string>
# include "Message.hpp"

class Callback
{
	private:
		std::vector<std::string>		_Replys;
		std::vector<Message>			_Messages;

	public:
		Callback();
		~Callback();

		std::vector<std::string>	const	&getReplys() const;
		std::vector<Message>		const	&getMessages() const;
		void								addReply(std::string &reply);
		void								addMessage(Message &message);
		void								resetReplys();
		void								resetMessages();
};

#endif