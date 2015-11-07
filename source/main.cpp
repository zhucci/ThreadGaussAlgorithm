
#include "sequential.h"
#include "parallel.h"
#include <exception>

int printColumn(int N,int ColNum,double **A);
int printVector(int N, double *A);
int main  (int argc, char* argv[]) {
  
  //  int nt=1;	// Кол-во расчетных потоков
  //  int nc;	// Кол-во циклов
  int i, j, k;

  pthread_attr_t pattr;

  if (argc != 2) {
    fprintf(stderr, "Исп: %s размерность #потоков #циклов\n", argv[0]);
    exit (1);
    };

  int N = atoi(argv[1]);
  //   nt = atoi(argv[2]);

    //   assert(N%nt!=0);
  
  // Выделение памяти
  // Инициализация A  случ. значениями

 srand(time(NULL));
 double *A =(double*) operator new(sizeof(double)*N*(N+1));
  for(i=0;i<N;i++)
  {
    for (j=0; j<N; j++)
    {
      A[i*(N+1)+j] = (double) (rand()%1000-500)/500;
    }
    A[i*(N+1)+N]=1;
  }

  double *X =gauss(N,A);
  printVector(N,X);
  return 0;
}

int printColumn(int N,int Col, double **A)
{
  try{
  for(int j=0;j<N;j++)
    {
      std::cout<<A[Col][j]<<" ";
    }
  std::cout<<std::endl;
  }
  catch(std::exception &ex)
    {
      std::cerr<<"Print Error"<<ex.what()<<std::endl;
      
    }
  return 0;
}
int printVector(int N, double *A)
{
  try
    {
      for(int j=0;j<N;j++)
	{
	  std::cout<<A[j]<<" ";
	}
      std::cout<<std::endl;
    }
  catch(std::exception &ex)
    {
      std::cerr<<"Print Error"<<ex.what()<<std::endl;
    }
  return 0;
}
