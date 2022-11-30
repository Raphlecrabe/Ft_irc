#ifndef LOG_HPP
# define LOG_HPP

# include <iostream>

class Log {
	private:
		static Log* instance;

	public:
		Log();
		~Log();

	static void print(std::string);
};

#endif
