#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>
# include <fstream>

class Debug {
	private:
		static Debug	*_instance;
		std::string		_fileName;
		long int		_startTime;

		void _log(std::string &);

	public:
		Debug();
		~Debug();

		static std::ofstream Logstream;

		static void Log(std::string);
};

#endif