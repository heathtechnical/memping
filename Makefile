CC=gcc
LIBS=-lrt

memping: 
	$(CC) -o memping memping.c $(LIBS)

.PHONY: clean

clean:
	rm -rf memping
