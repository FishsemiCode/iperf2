/*--------------------------------------------------------------- 
 * Copyright (c) 1999,2000,2001,2002,2003                              
 * The Board of Trustees of the University of Illinois            
 * All Rights Reserved.                                           
 *--------------------------------------------------------------- 
 * Permission is hereby granted, free of charge, to any person    
 * obtaining a copy of this software (Iperf) and associated       
 * documentation files (the "Software"), to deal in the Software  
 * without restriction, including without limitation the          
 * rights to use, copy, modify, merge, publish, distribute,        
 * sublicense, and/or sell copies of the Software, and to permit     
 * persons to whom the Software is furnished to do
 * so, subject to the following conditions: 
 *
 *     
 * Redistributions of source code must retain the above 
 * copyright notice, this list of conditions and 
 * the following disclaimers. 
 *
 *     
 * Redistributions in binary form must reproduce the above 
 * copyright notice, this list of conditions and the following 
 * disclaimers in the documentation and/or other materials 
 * provided with the distribution. 
 * 
 *     
 * Neither the names of the University of Illinois, NCSA, 
 * nor the names of its contributors may be used to endorse 
 * or promote products derived from this Software without
 * specific prior written permission. 
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE CONTIBUTORS OR COPYRIGHT 
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
 * ________________________________________________________________
 * National Laboratory for Applied Network Research 
 * National Center for Supercomputing Applications 
 * University of Illinois at Urbana-Champaign 
 * http://www.ncsa.uiuc.edu
 * ________________________________________________________________ 
 *
 * delay.c
 * by Mark Gates <mgates@nlanr.net>
 * updates 
 * by Robert J. McMahon <rmcmahon@broadcom.com> <rjmcmahon@rjmcmahon.com>
 * -------------------------------------------------------------------
 * accurate microsecond delay
 * ------------------------------------------------------------------- */

#include "Timestamp.hpp"
#include "util.h"
#include "delay.hpp"


/* -------------------------------------------------------------------
 * A micro-second delay function
 * o Use a busy loop or nanosleep
 * 
 * Some notes:
 * o clock_gettime (if available) is preferred over gettimeofday because 
 *   there are no time adjustments (e.g. ntp) and support nanoseconds
 * o Not using Timestamp object because these functions are about 
 *   accurate delays (vs accurate timestamps.)
 * o The syscalls such as nanosleep gaurantee at least the request time
 *   and will lose accuracy, particularly due to things like context switching
 * o Kalman filtering is used for better delay accuracy.  This can cause the delay
 *   to return faster than the request.  
 * o Remember the Client is keeping a running average delay for the thread
 *   so errors in delay will be adjusted there. (Assuming it's possible)
 * POSIX nanosleep(). This allowss a higher timing resolution 
 * (under Linux e.g. it uses hrtimers), does not affect any signals, 
 * and will use up remaining time when interrupted.
 * ------------------------------------------------------------------- */
void delay_loop(unsigned long usec)
{
    // Context switching greatly affects accuracy of nanosleep
    // Use nanosleep syscall for values of 1 ms or greater
    // otherwise use a busy loop
    if (usec < 1000) {
      delay_busyloop(usec);
    } else {
      delay_nanosleep(usec);
    }
}
#if HAVE_CLOCK_GETTIME
// A cpu busy loop
void delay_busyloop (unsigned long usec) {
    struct timespec t1, t2; 
    double time1, time2, sec;

    sec = usec / 1000000.0;
    clock_gettime(CLOCK_REALTIME, &t1);
    time1 = t1.tv_sec + (t1.tv_nsec / 1000000000.0);
    while (1) {
	clock_gettime(CLOCK_REALTIME, &t2);
	time2 = t2.tv_sec + (t2.tv_nsec / 1000000000.0);
	if ((time2 - time1) >= sec) {
	    break;
	}
    }
}
#else
void delay_busyloop (unsigned long usec) {
    struct timeval t1, t2;
    double time1, time2, sec;

    sec = usec / 1000000.0;
    gettimeofday( &t1, NULL );
    time1 = t1.tv_sec + (t1.tv_usec / 1000000.0);
    while (1) {
	gettimeofday( &t2, NULL );
	time2 = t2.tv_sec + (t2.tv_usec / 1000000.0);
	if ((time2 - time1) >= sec) 
	    break;
    }
}
#endif
// Use the nanosleep syscall
void delay_nanosleep (unsigned long usec) {
    struct timespec requested, remaining;

    requested.tv_sec  = 0;
    requested.tv_nsec = usec * 1000L;

    if (nanosleep(&requested, &remaining) < 0) {
	fprintf(stderr,"Nanosleep failed\n");
	exit(-1);
    }
}
// Kalman versions below that should support accuracy
// over a minimum gauranteed delay.  The ideal function
// to use is delay_nanosleep_kalman
#if HAVE_CLOCK_GETTIME
void kalman_update (kalman_state *state, double measurement) {
    //prediction update
    state->p = state->p + state->q;
    //measurement update
    state->k = state->p / (state->p + state->r);
    state->x = state->x + (state->k * (measurement - state->x));
    state->p = (1 - state->k) * state->p; 
}
void delay_nanosleep_kalman (unsigned long usec) {
    struct timespec requested, remaining;
    struct timespec t1, t2; 
    double time1, time2, sec, err;
    static kalman_state kalmanerr={
	0.00001, //q process noise covariance
	0.1, //r measurement noise covariance
	0.0, //x value
	1, //p estimation error covariance
	1 //k kalman gain
    };
    sec = (usec / 1000000.0) - kalmanerr.x;
    if (sec > 0) {
	requested.tv_sec  = (long) sec;
	requested.tv_nsec = (sec - requested.tv_sec) * 1e9;
    } else {
	sec = 0.0;
    }
    clock_gettime(CLOCK_REALTIME, &t1);
    time1 = t1.tv_sec + (t1.tv_nsec / 1000000000.0);
    if (sec > 1000) {
	if (nanosleep(&requested, &remaining) < 0) {
	    fprintf(stderr,"Nanosleep failed\n");
	    exit(-1);
	}
    }
    while (1) {
	clock_gettime(CLOCK_REALTIME, &t2);
	time2 = t2.tv_sec + (t2.tv_nsec / 1000000000.0);
	if ((time2 - time1) >= sec) {
	    break;
	}
    }
    err = (time2 - time1) - sec;
    kalman_update(&kalmanerr, err);
}
void delay_busyloop_kalman (unsigned long usec) {
    struct timespec t1, t2;
    double time1, time2, sec, err;
    static kalman_state kalmanerr={
	0.00001, //q process noise covariance
	0.1, //r measurement noise covariance
	0.0, //x value
	1, //p estimation error covariance
	1 //k kalman gain
    };
    sec = (usec / 1000000.0) - kalmanerr.x;
    clock_gettime(CLOCK_REALTIME, &t1);
    time1 = t1.tv_sec + (t1.tv_nsec / 1000000000.0);
    while (1) {
	clock_gettime(CLOCK_REALTIME, &t2);
	time2 = t2.tv_sec + (t2.tv_nsec / 1000000000.0);
	if ((time2 - time1) >= sec) {
	    err = (time2 - time1) - sec;
	    kalman_update(&kalmanerr, err);
	    break;
	}
    }
}
#endif