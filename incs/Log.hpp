#ifndef LOG_HPP
# define LOG_HPP

# include <iostream>
# include <stdexcept>
# include <fstream>
# include <cstdlib>

class Log {
	private:
		static Log* _instance;
		std::string _fileName = "log.txt";

		void _log(std::string &m) {
			std::ofstream file(_fileName.c_str(), ios::app);

			file.exceptions(std::ofstream::badbit | std::ofstream::failbit);

			try
			{
				file << m;
				file.close();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

	public:
		Log() {
			std::ofstream file;
			
			file.open(_fileName.c_str(), std::ofstream::out | std::ofstream::trunc);

			file.close();
		}

		~Log() {}

	static void Log(std::string &m) {
		if (_instance == NULL)
			_instance = new _instance();

		_instance.log(m);
	}
};

#endif
