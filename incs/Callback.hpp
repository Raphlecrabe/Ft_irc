/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:26:32 by raphael           #+#    #+#             */
/*   Updated: 2023/01/18 16:49:47 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLBACK_HPP
# define CALLBACK_HPP

# include <vector>
# include <string>
# include "Message.hpp"
# include "Hub.hpp"

typedef std::pair<std::string, std::string> s_pair;

class Callback
{
	private:
		std::vector < s_pair >			_Replys;
		std::vector<Message>			_Messages;
		std::vector<std::string>		_Commands;
		
		User *							_userToDelete;

	public:
		Callback();
		~Callback();

		std::vector< s_pair >	const		&getReplys() const;
		std::vector< Message >		const	&getMessages() const;
		std::vector<std::string>	const	&getCommands() const;
		User *								GetUserToDelete() const;

		void	addReply(std::string reply);
		void	addReply(std::string reply, std::string param);
		void	addMessage(Message &message);
		void	addCommand(std::string cmd);
		void	setUserDelete(User *);
		
		void	resetReplys();
		void	resetMessages();
		void	resetCommands();
};

#endif