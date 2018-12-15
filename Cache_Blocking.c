//whehdwns
void dgemm(int m, int n, float *A, float *C)
{
	int blocksize = 128; // if the blocksize size is smaller than 128, then it stopped running
	for (int jj = 0; jj < m; jj+=blocksize){
		for (int kk = 0; kk < n; kk+=blocksize){
			for (int i = 0; i < m; i++){
				for (int j = jj; j < m; j++) {
					int temp = 0;
						for (int k = kk; k <n; k++) {
								temp += A[i+ k * m] * A[j + k * m];
						}
						C[i + j * m] += temp;
				}
			}
		}
	}
}
//need to change number
