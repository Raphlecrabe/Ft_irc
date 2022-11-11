/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonacho <rmonacho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:54 by rmonacho          #+#    #+#             */
/*   Updated: 2022/11/11 16:12:34 by rmonacho         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// FICHIER TEST POUR LANCER UN SERVEUR A CONNECTIONS MULTIPLES

//INCLUDES

#include <iostream>
#include <sys/types.h> // DEFINIT CERTAINES STRUCTURES ET SYMBOLES UTILES POUR LA GESTION DES SOCKETS
#include <unistd.h>  
#include <sys/socket.h> // DEFINIT LES FONCTIONS ET AUTRES SYMBOLES POUR L'UTILISATION DES SOCKETS
#include <netinet/in.h>
#include <arpa/inet.h> // UTILISATION DE HTONS ET NTOHS 
#include <netdb.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>


int	main(void)
{


	struct addrinfo	hint, *ai, *p;
	memset(&hint, 0, sizeof(hint));
	hint.ai_family = AF_INET;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_flags = AI_PASSIVE;

	int rv = getaddrinfo(NULL, "9034", &hint, &ai); // ON TROUVE UNE LISTE D'ADRESSE DISPO POUR 
													// Y METTRE NOTRE SERVEUR
	if (rv != 0)
	{
		std::cerr << "Can't find a usable IP address" << std::endl;
		return (-1);
	}

	int	listening;
	int	yes = 1;

	for (p = ai; p != NULL; p = p->ai_next) // ON TESTE CHACUNE DES ADRESSES POUR EN TROUVER UNE VALIDE
	{
		listening = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (listening < 0)
			continue ;
		setsockopt(listening, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)); // CA CA SERT A ENLEVER UN TYPE D'ERREUR
		if (bind(listening, p->ai_addr, p->ai_addrlen) < 0) // TEST DU LIEN ENTRE L'ADRESSE ET LA SOCKET
		{
			close(listening);
			continue;
		}
		break;
	}

	if (p == NULL) // ZERO ADRESSE VALIDE
	{
		std::cerr << "Couldn't link any address with a socket on this port" << std::endl;
		return (-1);
	}
	
	freeaddrinfo(ai);

	
	// DEFINIT LA SOCKET LISTENING COMME LA SOCKET DE REFERENCE 
	// POUR ACCEPTER DES CONNECTIONS

	if (listen(listening, SOMAXCONN) == -1)
	{
		std::cerr << "Can't listen from the listening socket" << std::endl;
		return (-1);
	}

	// SET UP D'UNE LISTE DE SOCKET DE CLIENT

	fd_set	master;
	fd_set	reads;
	FD_ZERO(&master);
	FD_SET(listening, &master);

	// SET UP DES STRUCTURES NECESSAIRES POUR ECOUTER UN CLIENT
	
	sockaddr_in	client;
	socklen_t	addrlen = sizeof(client);
	int			newfd;
	char		host[NI_MAXHOST];

	memset(host, 0, NI_MAXHOST);
	int	n_bytes = 0;
	int	fd_max = listening;

	// ATTENTE ET TRAITEMENTS DES MESSAGES ET CONNECTIONS DES CLIENTS
	while (1)
	{
		reads = master;
		int	socketCount = select(fd_max + 1, &reads, nullptr, nullptr, nullptr);

		if (socketCount == -1)
		{
			std::cerr << "A connection or a message from a client failed" << std::endl;
			return (-1);
		}
		for (int i = 0; i <= fd_max; i++)
		{
			if (FD_ISSET(i, &reads))
			{
				if (i == listening) // UNE NOUVELLE CONNECTION A ETE DETECTE
				{
					newfd = accept(listening, (sockaddr *)&client, &addrlen);
					if (newfd == -1)
					{
						std::cerr << "Can't accept a new connection" << std::endl;
						return (-1);
					}
					else
					{
						if (newfd > fd_max)
							fd_max = newfd;
						FD_SET(newfd, &master); // AJOUT DE LA CONNECTION AU MASTER
					}
				}
				else // ON A RECU UNE COMMUNICATION
				{
					memset(host, 0, NI_MAXHOST);
					n_bytes = recv(i, host, sizeof(host), 0);
					if (n_bytes <= 0) // LE CLIENT A FERME LA CONNECTION OU IL Y A EU UNE ERREUR
					{
						if (n_bytes != 0)
							std::cerr << "Problem receiving a message from a client, removing the client" << std::endl;
						close(i); // DANS LES DEUX CAS ON SE CASSE
						FD_CLR(i, &master);
					}
					else // ON A VRAIMENT RECU UN MESSAGE
					{
						for (int j = 0; j <= fd_max; j++) // ON L'ENVOIE A TOUS LE MONDE
						{
							if (FD_ISSET(j, &master))
							{
								if (j != listening && j != i) // SAUF AU LISTENING ET L'ENVOYEUR
								{
									if (send(j, host, n_bytes, 0) == -1)
									{
										std::cerr << "Probleme envoie de message" << std::endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

