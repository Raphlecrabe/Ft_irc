/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Includecommand.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:53:48 by raphael           #+#    #+#             */
/*   Updated: 2022/12/05 14:04:19 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDECOMMAND_HPP
# define INCLUDECOMMAND_HPP

# include "ACommand.hpp"
//Include de toutes les Acommands pour pouvoir les includes
//Dans les messager et Replyer facilement
# include "Nick.hpp"
# include "UserCmd.hpp"
# include "Ping.hpp"
# include "Cap.hpp"
# include "Join.hpp"
# include "Part.hpp"
# include "Topic.hpp"

#endif