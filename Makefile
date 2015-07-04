SYSTEM=$(shell uname -s)

CC=gcc

LIBS_Darwin=
LIBS_Linux=-l rt
LIBS=$(LIBS_$(SYSTEM))

memping: 
	$(CC) -o memping memping.c $(LIBS)

.PHONY: clean

clean:
	rm -rf memping
