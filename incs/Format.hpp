#ifndef FORMAT_HPP
# define FORMAT_HPP

#include <iostream>

typedef struct 	s_msginfo {
	std::string src;
	std::string cmd;
	std::string params;
}				t_msginfo;

class Format {
	private:

	public:
		Format();
		~Format();

		void		getmsginfo(std::string msg, t_msginfo *msginfo);
		std::string cat(t_msginfo msginfo);

		class WrongFormatException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif