#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>

class Debug {
	private:
		static Debug *_instance;
		std::string _fileName;

		void _log(std::string &);

	public:
		Debug();
		~Debug();

		static void Log(std::string);
};

#endif