all:
	g++ server.cpp -lpthread -lsqlite3 -Wall -o server
	g++ client.cpp -lpthread -lsqlite3 -Wall -o client

clean:
	rm -f server
	rm -f client