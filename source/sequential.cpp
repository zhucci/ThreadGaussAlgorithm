#include "sequential.h"

using namespace std;


double * gauss(int N, double *B)
 {
   size_t num = sizeof(double)*N*(N+1);
   double *matrix =(double *) operator new(num);
   memcpy(matrix,B,num);
   double* A[N];
   double* X = new double[N]; 
   for(int i=0;i<N;i++)
     A[i]= &(matrix[(N+1)*i]);
   /*
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
   */
	     for(int i=0;i<N;i++)
	      {
		for (int k=i+1; k<=N; k++) 
		{
		  
		    A[i][k]/=A[i][i];
		    for (int j=i+1; j<N; j++) 
		    {
			A[j][k]-= A[i][k]*A[j][i];
		    }
		}
	      }

	    X[N-1]=A[N-1][N];
    for (int i=N-2; i>=0; i--) 
      {
        for (int k=i+1;k<N; k++) 
	  {
            A[i][N] -= A[i][k]*A[k][N];
	  }
	X[i]=A[i][N];
      }   
    operator delete(matrix);
    return X;
}
