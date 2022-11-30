/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafy <rafy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:26:32 by raphael           #+#    #+#             */
/*   Updated: 2022/11/29 11:40:30 by rafy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLBACK_HPP
# define CALLBACK_HPP

# include <vector>
# include <string>
# include "Message.hpp"
# include "Hub.hpp"

class Callback
{
	private:
		std::vector<std::string>		_Replys;
		std::vector<std::string>		_Replyparams;
		std::vector<Message>			_Messages;

	public:
		Callback();
		~Callback();

		std::vector<std::string>	const	&getReplys() const;
		std::vector<Message>		const	&getMessages() const;
		std::vector<std::string>	const	&getReplyParams() const;

		void	addReply(std::string reply);
		void	addMessage(Message &message);
		void	addReplyparam(std::string &param);
		void	resetReplys();
		void	resetMessages();
		void	resetReplyparams();
		
		void	generateMessagesForChannel(Channel *channel, std::string &command, User &user);
};

#endif