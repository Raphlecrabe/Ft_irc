IRC_PROCESS=$(ps | grep "ircserv" | head -1 | awk '{print $1;}' )
while true; do leaks $IRC_PROCESS; sleep 3; done