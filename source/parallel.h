
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

extern int N;	// Размер матрицы A и векторов B, C
extern double *A, *B, *C;

extern int done;
extern ThreadRecord *threads; // Массив индексов границ лент матрицы
extern pthread_barrier_t barr1, barr2;

void * mysolver (void *arg_p);
int threadGauth(int argc,char* argv[]);

#endif
