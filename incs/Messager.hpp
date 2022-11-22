/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphael <raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:41:02 by raphael           #+#    #+#             */
/*   Updated: 2022/11/18 10:04:41 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGER_HPP
# define MESSAGER_HPP

class Messager
{
private:
	Sender	_Sender;
	
public:
	Messager();
	~Messager();

	void	TreatMessages(std::vector<Message> Messages);
	void	Sendone(Message Message);
};

#endif