//whehdwns
void dgemm(int m, int n, float *A, float *C)
{
	// FILL-IN 
	for (int j = 0; j < m; j++)
		for (int k = 0; k < n; k++)
			for (int i = 0; i < m; i++)
				C[i + j * m] += A[i + k * m] * A[j + k * m];
}	

/*
		for (int j = 0; j < m; j++){
		for (int k = 0; k < n; k++) {

			float x = A[j + k * m];

			for (int i = 0; i < m; i++){
				C[i + j * m] += A[i + k * m] * x;
			}
		}
	}

	*/
