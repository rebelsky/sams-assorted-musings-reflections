# CFLAGS = -g -Wall

TARGETS = jamie jessie jessie2 jessie2b

default: $(TARGETS)

%.o: %.c utils.h

jamie: jamie.o utils.o
	$(CC) $^ -o $@

jessie: jessie.o utils.o
	$(CC) $^ -o $@

jessie2: jessie2.o utils.o
	$(CC) $^ -o $@

jessie2b: jessie2b.o utils.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o $(TARGETS)
