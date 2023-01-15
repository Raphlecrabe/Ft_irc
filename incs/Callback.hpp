/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Callback.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:26:32 by raphael           #+#    #+#             */
/*   Updated: 2023/01/15 17:01:00 by marvin           ###   ########.fr       */
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
		
		bool							_stop;

	public:
		Callback();
		~Callback();

		std::vector< s_pair >	const		&getReplys() const;
		std::vector< Message >		const	&getMessages() const;
		std::vector<std::string>	const	&getCommands() const;
		bool								askForStop() const;

		void	addReply(std::string reply);
		void	addReply(std::string reply, std::string param);
		void	addMessage(Message &message);
		void	addCommand(std::string cmd);
		void	setStop(bool);
		
		void	resetReplys();
		void	resetMessages();
		void	resetCommands();
};

#endif