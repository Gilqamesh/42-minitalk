CC = gcc
CFLAGS =
SRCCLIENT = client.c utils.c
SRCSERVER = server.c utils.c

server: $(SRCSERVER:.c=.o)
	$(CC) -o $@ $^
client: $(SRCCLIENT:.c=.o)
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean all
all:
	make server
	make client
clean:
	rm -rf *.o