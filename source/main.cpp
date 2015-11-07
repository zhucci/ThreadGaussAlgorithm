
#include "sequential.h"
#include "parallel.h"


int N;	// Размер матрицы A и векторов B, C
double *A, *B, *C;

int done=0;
ThreadRecord *threads; // Массив индексов границ лент матрицы
pthread_barrier_t barr1, barr2;


int main  (int argc, char* argv[]) {
  int nt;	// Кол-во расчетных потоков
  int nc;	// Кол-во циклов
  int i, j, k;

  pthread_attr_t pattr;

  if (argc != 4) {
    fprintf(stderr, "Исп: %s размерность #потоков #циклов\n", argv[0]);
    exit (1);
    };

  N = atoi(argv[1]);
  nt = atoi(argv[2]);
  nc = atoi(argv[3]);

  if ( N%nt ) {
    fprintf(stderr, "Размерность д.б. кратна кол-ву потоков\n");
    exit (2);
    };

  // Выделение памяти
  A = static_cast<double *>(::operator new(sizeof(double)*N*N));
  B = (double *) ::operator new(sizeof(double)*N );
  C = (double *) ::operator new( sizeof(double)*N );

  // Инициализация A и B случ. значениями
  srand(time(NULL));
  for (i=0; i<N; i++) {
    B[i] = (double) rand();
    for (j=0; j<N; j++)
      A[i*N+j] = (double) rand();
    };
  
}


