//whehdwns
void dgemm(int m, int n, float *A, float *C) {
	//m is row / column length
	
	for (int i = 0; i < m; i++)
		for (int k = 0; k < n; k++)
			for (int j = 0; j < m; j += 4) {	//unrolling 4 times
				int f = m - j; 
				//f =boundry to read correct row during unrolling

				if (f > 3 )  //unroll 4 times or more
				{
					C[i + j * m] += A[i + k * m] * A[j + k * m];
					C[i + (j + 1)*m] += A[i + k * m] * A[(j + 1) + k * m];
					C[i + (j + 2)*m] += A[i + k * m] * A[(j + 2) + k * m];
					C[i + (j + 3)*m] += A[i + k * m] * A[(j + 3) + k * m];
				}
				
				else  if (f == 3) //unroll 3 times
				{
					C[i + j * m] += A[i + k * m] * A[j + k * m];
					C[i + (j + 1)*m] += A[i + k * m] * A[(j + 1) + k * m];
					C[i + (j + 2)*m] += A[i + k * m] * A[(j + 2) + k * m];
				}

				else if (f == 2)  //unroll 2 times
				{
					C[i + j * m] += A[i + k * m] * A[j + k * m];
					C[i + (j + 1)*m] += A[i + k * m] * A[(j + 1) + k * m];
				}

				else C[i + j * m] += A[i + k * m] * A[j + k * m];  //normal dgemm-naive.c

			}

}
