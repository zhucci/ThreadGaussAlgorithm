#include "sequential.h"

using namespace std;


double *gauss(int N, double **A)
 {
        // Swap maximum row with current row (column by column)
      
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        
	    for(int i=0;i<N-2;i++)
	      {
		
		      double maxEl = abs(A[i][i]);
		      int maxRow = i;
		      for (int k=i+1; k<N; k++) {
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

    for (int i=N-2; i>=0; i--) 
      {
        for (int k=i+1;k<N; k--) 
	  {
            A[i][N] -= A[i][k]*A[k][N];
	  }
      }   
}
