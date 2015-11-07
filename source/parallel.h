
#ifndef Parallel
#define Parallel

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#define _REENTRANT
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <new>
#include <sys/time.h>
typedef struct {
  pthread_t tid;
  int th_num;
  } ThreadArg;


void * threadFunc (void *);
double *ParallelGauss(int MatrixSize,double *SystemLinearEqu, int ThreadAmount);

#endif
