
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

typedef struct {
  pthread_t tid;
  int first;
  int last;
  } ThreadRecord;


void * mysolver ();
int threadGauth();

#endif
