#include "parallel.h"
double *A,*B,*C;
int  N;
 int done;
 ThreadRecord *threads; // Массив индексов границ лент матрицы
 pthread_barrier_t barr2;

void threadFunc(double **A,double *B, int th_amount, int th_num) 
{
  printf("%d - thread start\n",th_num);
  printf("%d - thread end\n".th_num);
}
double *ParallelGauss(int N,double *SOLE, int th_amount) 
{
    size_t num = sizeof(double)*N*(N+1);
   double *matrix =(double *) operator new(num);
   memcpy(matrix,SOLE,num);
   double* A[N];
   double* X = new double[N]; 

   for(int i=0;i<N;i++)
     A[i]= &(matrix[(N+1)*i]);

	    for(int i=0;i<N-1;i++)
	      {
		      double maxEl = abs(A[i][i]);
		      int maxRow = i;
		      for (int k=i+1; k<N; k++) 
		      {
			if (abs(A[k][i]) > maxEl) 
			{
			  maxEl = abs(A[k][i]);
			  maxRow = k;
			}
		      }

		      // Swap maximum row with current row (column by column)
		      register double tmp;
		      for (int k=i; k<N+1;k++)
			{
			  tmp = A[maxRow][k];
			  A[maxRow][k] = A[i][k];
			  A[i][k] = tmp;
			}
	      }

	     for(int i=0;i<N-1;i++)
	      {

		for (int k=i+1; k<=N; k++) 
		{
		  
		    double c = A[i][k]/A[i][i];
		    for (int j=i+1; j<N; j++) 
		    {
			A[j][k]-= c * A[j][i];
		    }
		}
	      }

	    A[N-1][N]/=A[N-1][N-1];
	    X[N-1]=A[N-1][N];
    for (int i=N-2; i>=0; i--) 
      {
        for (int k=i+1;k<N; k++) 
	  {
            A[i][N] -= A[i][k]*A[k][N];
	  }
	X[i]=A[i][N];
      }   
    return X;
}
