
#include "sequential.h"
#include "parallel.h"
#include <exception>
#define clockType _POSIX_CPUTIME

int printColumn(int N,int ColNum,double **A);
int printVector(int N, double *A);
int main  (int argc, char* argv[]) {

  int i, j, k;

  if (argc != 3) {
    fprintf(stderr, "Исп:[Размер матрицы:N] [Число потоков]\n"); 
    exit (1);
    };

  int N = atoi(argv[1]);
  int  nt = atoi(argv[2]);//Thread amount

     //   assert(N%nt!=0);
  
  //Memory allocation

 srand(time(NULL));
 double *A =(double*) operator new(sizeof(double)*N*(N+1));
  for(i=0;i<N;i++)
  {
    for (j=0; j<N; j++)
    {
      A[i*(N+1)+j] = (double) ((i+1+j%100)%1000-500)/500;
    }
    A[i*(N+1)+N]=1;
  }
  timespec StartTime,EndTime;
  
  clock_gettime(clockType,&StartTime); //Start timer

  double *X =gauss(N,A);  //Sequential Gauss method

  clock_gettime(clockType,&EndTime); //End timer

  long long timePassSeq = EndTime.tv_sec-StartTime.tv_sec;

  printf("Seq took t=%lld\n",timePassSeq);

  clock_gettime(clockType,&StartTime); //Start

  X=ParallelGauss(N,A,nt); 

  clock_gettime(clockType,&EndTime);//End

  long long timePassPar = EndTime.tv_sec-StartTime.tv_sec;
 printf("Par took t=%lld\n",timePassPar);
  //result
 double boost= ((double)(timePassSeq))/timePassPar; 
  printf("Boost S=%f\n",boost);

  // printVector(N,X);
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
      std::cout<<std::setw(4)<<std::endl;
    }
  catch(std::exception &ex)
    {
      std::cerr<<"Print Error"<<ex.what()<<std::endl;
    }
  return 0;
}
