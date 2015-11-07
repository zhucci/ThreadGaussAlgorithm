#include "parallel.h"

  double **A;
  int N;
  int th_amount;
  pthread_barrier_t barrLoop,barrOut;
  sem_t writeRight;


void *threadFunc(void *arg) {
  int Num = ((ThreadArg *)(arg))->th_num;
  
 
  // printf("%d -start\n",Num);

 for(int i=0;i<N;i++)
	      {

		for (int k=i+Num; k<=N; k+=th_amount) 
		{
		  
		     A[i][k]/=A[i][i];
		    for (int j=i+1; j<N; j++) 
		    {
			A[j][k]-= A[i][k]*A[j][i];
		    }  
		}
	         pthread_barrier_wait(&barrLoop);
	      }
 
	    
    for (int i=N-2; i>=0; i--) 
      {
	double accum=0;
        for (int k=i+Num;k<N; k+=Num) 
	  {
           accum += A[i][k]*A[k][N];
	  }
	//Take right for change value      
	sem_wait(&writeRight);
	A[i][N]-=accum;
	sem_post(&writeRight);
	//reliese rights

	pthread_barrier_wait(&barrLoop);
      }   
  
    //    printf("%d - end\n",Num);
  pthread_barrier_wait(&barrOut);
}
double *ParallelGauss(int MatrixSize,double *SOLE, int nt) 
{
   N=MatrixSize;
   th_amount=nt;
   size_t num = sizeof(double)*N*(N+1);
   double *matrix =(double *) operator new(num);
   memcpy(matrix,SOLE,num);
       A = new double*[N];
   double* X = new double[N]; 
   
   for(int i=0;i<N;i++)
     A[i]= &(matrix[(N+1)*i]);


   //Create threads

   pthread_t *tid= new pthread_t[nt];

    pthread_attr_t pattr;
    //Attribute specify
  pthread_attr_init (&pattr);
  pthread_attr_setscope (&pattr, PTHREAD_SCOPE_SYSTEM);
  pthread_attr_setdetachstate (&pattr,PTHREAD_CREATE_JOINABLE);

  ThreadArg *threads = new ThreadArg[th_amount];

  pthread_barrier_init(&barrLoop, NULL, nt);
  pthread_barrier_init(&barrOut, NULL, nt+1);
  sem_init(&writeRight,1,1);
  for (int i=0; i<nt; i++) {
    threads[i].th_num=i+1;
    if ( pthread_create (&(threads[i].tid), &pattr, threadFunc, (void *) &(threads[i])) )
      perror("pthread_create");
    }
  pthread_barrier_wait(&barrOut); //wait while threads are working


    for (int i=0; i<N-1; i++)
	X[i]=A[i][N];
      
    operator delete(matrix); 
    return X;
}
