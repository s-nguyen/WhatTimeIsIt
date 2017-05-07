/*
 * time.c
 *
 *  Created on: May 6, 2017
 *      Author: yorha
 */
#define _POSIX_C_SOURCE 200809L
#define _BSD_SOURCE
#include <inttypes.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

/* https://linux.die.net/man/3/asctime */
/* https://linux.die.net/man/3/clock_gettime */
/* http://pubs.opengroup.org/onlinepubs/9699919799/functions/clock_gettime.html */


/*Sending current EPOCH time */
/* clock_settime */

int main() {

	struct timespec spec[30];

	time_t s[30];
	long ms[30];


	for (int i = 0; i < 30; i++) {
		clock_gettime(CLOCK_REALTIME, &spec[i]);
		s[i] = spec[i].tv_sec;
		ms[i] = round(spec[i].tv_nsec / 1.0e6);
		//ms[i] = spec[i].tv_nsec;
		usleep(33333);
	}
	for (int i = 0; i < 29; i++) {
		printf("Current time: %"PRIdMAX".%03ld seconds since the Epoch\n",
				(intmax_t) s[i], ms[i]);
	}

	char* t_ptr;
	t_ptr = ctime(&s[0]);
	printf("%s\n", t_ptr);

}
