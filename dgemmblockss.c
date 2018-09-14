#define min(X,Y) (((X) < (Y)) ? (X) : (Y))

void dgemm(int m, int n, float *A, float *C)
{
	int blocksize = 32;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			C[i + j * m] = 0;
		}
	}
	for (int k1 = 0; k1 < n; k1 += blocksize) {
		for (int j1 = 0; j1 < m; j1 += blocksize) {
			for (int i = 0; i < m; i++) {
				for (int k = k1; k < min (n, k1 + blocksize); k++) {
					for (int j = j1; j < min (m, j1 + blocksize); j++) {
						C[i + j * m] += A[i + k * m] * A[j + k * m];
					}
				}
			}
		}
	}

}					


