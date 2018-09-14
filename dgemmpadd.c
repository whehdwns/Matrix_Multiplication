#include <stdlib.h>
void dgemm(int m, int n, float *A, float *C)
{
	if (n % 2 == 1) {

		//make rows = columns so we operate on square matrix
		int newN = n + 1;
		//allocate new memory for padded matrix
		float *paddedA = (float*)malloc(m * (newN) * sizeof(float));

		//initialize matrix to 0
		for (int i = 0; i < (m * newN); i++) {
			paddedA[i] = 0;
		}

		//copy original matrix to padded matrix
		for (int i = 0; i < (m * n); i++) {
			paddedA[i] = A[i];

		}

		//multiply
		for (int i = 0; i < m; i++)
			for (int k = 0; k < newN; k++)
				for (int j = 0; j < m; j++)
					C[i + j * m] += paddedA[i + k * m] * paddedA[j + k * m];
	}

	else if (m % 2 == 1) {

		//make colomns = rows so we operate on square matrix
		int newM = m + 1;
		int dif = 1;

		//allocate new memory for padded matrix
		float *paddedA = (float*)malloc(newM * n * sizeof(float));

		for (int i = 0; i < (newM * n); i++) {
			paddedA[i] = 0;
		}

		int j = 0;
		for (int i = 0; i < m * n; i++) {
			if (i % m == 0 && i != 0)
				j++;

			paddedA[j] = A[i];
			j++;
		}

		for (int i = 0; i < m; i++)
			for (int k = 0; k < n; k++)
				for (int j = 0; j < m; j++)
					C[i + j * m] += A[i + k * m] * A[j + k * m];
	}

	else {

		//multiply
		for (int i = 0; i < m; i++)
			for (int k = 0; k < n; k++)
				for (int j = 0; j < m; j++)
					C[i + j * m] += A[i + k * m] * A[j + k * m];
	}
}

