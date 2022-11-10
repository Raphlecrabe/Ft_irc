/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:54 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/10 16:04:51 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// FICHIER TEST POUR LANCER UN SERVEUR A CONNECTIONS MULTIPLES

//INCLUDES

#include <iostream>
#include <sys/types.h> // DEFINIT CERTAINES STRUCTURES ET SYMBOLES UTILES POUR LA GESTION DES SOCKETS
#include <unistd.h>  
#include <sys/socket.h> // DEFINIT LES FONCTIONS ET AUTRES SYMBOLES POUR L'UTILISATION DES SOCKETS
#include <netdb.h> // EN RAPPORT AVEC DES STRUCTURES SUR LES HOTES ET SERVEUR
#include <arpa/inet.h> // UTILISATION DE HTONS ET NTOHS 
#include <string.h>
#include <string>


int	main(void)
{
	// CREATING A LISTENING SOCKET
	int	listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == -1)
	{
		std::cerr << "Can't create the listening socket" << std::endl;
		return (-1);
	}

	// LINKING IT TO A PORT AND AN IP

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000); // SECIFICATION DU PORT, BESOIN D'UNE CONVERSION 
								  // POUR EVITER LES PROBLEMES DE COMPATIBILITE ENTRE SYSTEMES

	inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); // CONVERSION DE L'ADRESSE IP EN STRUCTURE
	
	// TEST DU LIEN

	if (bind(listening, (sockaddr *)&hint, sizeof(hint)) == -1)
	{
		std::cerr << "Can't bind the listening socket" << std::endl;
		return (-1);
	}
	
	// DEFINIT LA SOCKET LISTENING COMME LA SOCKET DE REFERENCE 
	// POUR ACCEPTER DES CONNECTIONS

	if (listen(listening, SOMAXCONN) == -1)
	{
		std::cerr << "Can't listen from the listening socket" << std::endl;
		return (-1);
	}

	// SET UP D'UNE LISTE DE SOCKET DE CLIENT

	fd_set	master;
	FD_ZERO(&master);
	FD_SET(listening, &master);

	// ATTENTE ET TRAITEMENTS DES MESSAGES ET CONNECTIONS DES CLIENTS

	while (1)
	{
		fd_set	copy = master;

		int	socketCount = select(0, &copy, nullptr, nullptr, nullptr);

		if (socketCount == -1)
		{
			std::cerr << "A connection or a message from a client failed" << std::endl;
			return (-1);
		}
		
		for (int i = 0; i < socketCount; i++)
		{
			// FAUT QUE JE COMPRENNE COMMENT CREER DES SOCKETS DE
			// CLIENTS ET UTILISER ACCEPT SUR LINUX
		}
	}
}

