#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <vector>

class Channel {
	private:
		std::vector<int> _fds;

	public:
		Channel();
		~Channel();

		void add_fd(int fd);
		void send_all(int sender_fd, char *msg, int len);
};

#endif