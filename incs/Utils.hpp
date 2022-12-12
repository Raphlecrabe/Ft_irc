/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelthoi <fbelthoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:17:19 by rmonacho          #+#    #+#             */
/*   Updated: 2022/12/12 15:06:17 by fbelthoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <vector>

class Utils
{
private:
public:
	Utils();
	~Utils();

	//Split un string en fonction du delimiteur, si le delimiteur est en premier 
	//cree un argument vide, si le delimiteur est en dernier, ne cree pas d'argument
	static std::vector<std::string>	split(std::string param, char delimiteur);
	static std::string	toString(int n);
	static bool			isBetween(int n, int low, int high);
};

#endif