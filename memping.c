#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char **argv) {
	int c;
	long size = 64;
	int lock;
	char *buf;
	struct timespec s, e;
	double elapsed;

	// Handle options
	while((c = getopt(argc, argv, "hls:")) != -1)
		switch(c) {
			case 's':
				size = (long) atoi(optarg);
			break;
			case 'l':
				lock = 1;
			break;
			case 'h':
			default:
				printf("usage: %s [-s size] [-l] [-h]\n\n", argv[0]);
				printf("optional parameters:\n");
				printf("  -s size   size in kilobytes\n");
				printf("  -l        attempt to lock pages in physical memory\n");
				exit(1);
		}

	// Allocate buffer
	buf = malloc(size*1024);
	if(!buf){
		perror("malloc");
		exit(1);
	}

	// Lock if required
	if(lock && mlock(buf, size*1024) == -1){
		perror("mlock");
		exit(1);
	}

	while(1){
		// Timed fill of buffer	
		clock_gettime(CLOCK_REALTIME, &s);
		memset(buf, 0xff, size*1024);
		clock_gettime(CLOCK_REALTIME, &e);

		// Calculate elapsed
		elapsed = (double)(e.tv_sec - s.tv_sec) * 1000 + 
			(double)(e.tv_nsec - s.tv_nsec) / 1.0e6;

		// Print and sleep
		printf("filled %d kb buffer in %0.2f ms\n", size, elapsed);
		sleep(1);
	}
}
