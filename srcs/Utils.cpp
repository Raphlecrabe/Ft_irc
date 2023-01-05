/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:20:37 by rmonacho          #+#    #+#             */
/*   Updated: 2022/12/12 15:06:15 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Utils.hpp"
#include <sstream>

Utils::Utils()
{
}

Utils::~Utils()
{
}

std::vector<std::string>	Utils::split(std::string param, char delimiteur)
{
	std::vector<std::string>	result;
	size_t	i = 0;
	size_t	j = 0;
	std::string	word;

	if (param.size() == 0)
	{
		return (result);
	}
	while (i < param.size())
	{
		while (i < param.size() && param[i] != delimiteur)
		{
			j++;
			i++;
		}
		if (i == param.size() && i - j == 0)
		{
			result.push_back(param);
			return (result);
		}
		word = param.substr(i - j, j);
		j = 0;
		result.push_back(word);
		i++;
	}
	return (result);
}

std::string Utils::toString(int n) {
	std::stringstream ss;

	ss << n;

	return ss.str();
}

bool	Utils::isBetween(int n, int low, int high) {
	return (n >= low && n <= high);
}