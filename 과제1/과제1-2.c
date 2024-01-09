#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int countOnesButSlow(int** A, int n);
int countOnes(int** A, int n);

int main() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	int i, j, kTotal = 0, ones = 0;
	int** A = NULL;
	int* k = NULL;
	int n = 30000;

	srand(time(NULL));
	A = (int**)malloc(sizeof(int*) * n);
	if (A == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	k = (int*)malloc(sizeof(int) * n);
	if (k == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	for (i = 0; i < n; ++i) {
		A[i] = (int*)malloc(sizeof(int) * n);
		if (A[i] == NULL) {
			printf("Not enough memory\n");
			return -1;
		}
		if (i == 0) {
			k[i] = rand() % (n / 10 + 1) + n * 0.9;
		}
		else {
			k[i] = rand() % (k[i-1]/10+1) + (k[i - 1] * 0.9);
		}
		for (j = 0; j < k[i]; ++j)
			A[i][j] = 1;
		for (j = k[i]; j < n; ++j)
			A[i][j] = 0;
		kTotal += k[i];
	}
	
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnes(A, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d, %d, %.12fms\n", kTotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
	
	for (i = 0; i < n; ++i)
		free(A[i]);
	free(A);
	free(k);

	kTotal = 0;
	n = 10000;
	A = (int**)malloc(sizeof(int*) * n);
	if (A == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	k = (int*)malloc(sizeof(int) * n);
	if (k == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	for (i = 0; i < n; ++i) {
		A[i] = (int*)malloc(sizeof(int) * n);
		if (A[i] == NULL) {
			printf("Not enough memory\n");
			return -1;
		}
		if (i == 0) {
			k[i] = rand() % (n / 10 + 1) + n * 0.9;
		}
		else {
			k[i] = rand() % (k[i - 1] / 10 + 1) + (k[i - 1] * 0.9);
		}
		for (j = 0; j < k[i]; ++j)
			A[i][j] = 1;
		for (j = k[i]; j < n; ++j)
			A[i][j] = 0;
		kTotal += k[i];
	}

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnes(A, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d, %d, %.12fms\n", kTotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	for (i = 0; i < n; ++i)
		free(A[i]);
	free(A);
	free(k);

	kTotal = 0;
	n = 20000;
	A = (int**)malloc(sizeof(int*) * n);
	if (A == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	k = (int*)malloc(sizeof(int) * n);
	if (k == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	for (i = 0; i < n; ++i) {
		A[i] = (int*)malloc(sizeof(int) * n);
		if (A[i] == NULL) {
			printf("Not enough memory\n");
			return -1;
		}
		if (i == 0) {
			k[i] = rand() % (n / 10 + 1) + n * 0.9;
		}
		else {
			k[i] = rand() % (k[i - 1] / 10 + 1) + (k[i - 1] * 0.9);
		}
		for (j = 0; j < k[i]; ++j)
			A[i][j] = 1;
		for (j = k[i]; j < n; ++j)
			A[i][j] = 0;
		kTotal += k[i];
	}

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnes(A, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d, %d, %.12fms\n", kTotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	for (i = 0; i < n; ++i)
		free(A[i]);
	free(A);
	free(k);

	kTotal = 0;
	n = 30000;
	A = (int**)malloc(sizeof(int*) * n);
	if (A == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	k = (int*)malloc(sizeof(int) * n);
	if (k == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	for (i = 0; i < n; ++i) {
		A[i] = (int*)malloc(sizeof(int) * n);
		if (A[i] == NULL) {
			printf("Not enough memory\n");
			return -1;
		}
		if (i == 0) {
			k[i] = rand() % (n / 10 + 1) + n * 0.9;
		}
		else {
			k[i] = rand() % (k[i - 1] / 10 + 1) + (k[i - 1] * 0.9);
		}
		for (j = 0; j < k[i]; ++j)
			A[i][j] = 1;
		for (j = k[i]; j < n; ++j)
			A[i][j] = 0;
		kTotal += k[i];
	}

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d, %d, %.12fms\n", kTotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	for (i = 0; i < n; ++i)
		free(A[i]);
	free(A);
	free(k);

	kTotal = 0;
	n = 10000;
	A = (int**)malloc(sizeof(int*) * n);
	if (A == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	k = (int*)malloc(sizeof(int) * n);
	if (k == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	for (i = 0; i < n; ++i) {
		A[i] = (int*)malloc(sizeof(int) * n);
		if (A[i] == NULL) {
			printf("Not enough memory\n");
			return -1;
		}
		if (i == 0) {
			k[i] = rand() % (n / 10 + 1) + n * 0.9;
		}
		else {
			k[i] = rand() % (k[i - 1] / 10 + 1) + (k[i - 1] * 0.9);
		}
		for (j = 0; j < k[i]; ++j)
			A[i][j] = 1;
		for (j = k[i]; j < n; ++j)
			A[i][j] = 0;
		kTotal += k[i];
	}

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d, %d, %.12fms\n", kTotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	for (i = 0; i < n; ++i)
		free(A[i]);
	free(A);
	free(k);

	kTotal = 0;
	n = 20000;
	A = (int**)malloc(sizeof(int*) * n);
	if (A == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	k = (int*)malloc(sizeof(int) * n);
	if (k == NULL) {
		printf("Not enough memory\n");
		return -1;
	}
	for (i = 0; i < n; ++i) {
		A[i] = (int*)malloc(sizeof(int) * n);
		if (A[i] == NULL) {
			printf("Not enough memory\n");
			return -1;
		}
		if (i == 0) {
			k[i] = rand() % (n / 10 + 1) + n * 0.9;
		}
		else {
			k[i] = rand() % (k[i - 1] / 10 + 1) + (k[i - 1] * 0.9);
		}
		for (j = 0; j < k[i]; ++j)
			A[i][j] = 1;
		for (j = k[i]; j < n; ++j)
			A[i][j] = 0;
		kTotal += k[i];
	}

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	ones = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d, %d, %.12fms\n", kTotal, ones, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	for (i = 0; i < n; ++i)
		free(A[i]);
	free(A);
	free(k);

	return 0;
}

int countOnesButSlow(int** A, int n) {
	int c = 0, j = 0, i;

	for (i = 0; i < n; ++i) {
		j = 0;
		while ((j < n) && (A[i][j] == 1)) {
			++c;
			++j;
		}
	}
	return c;
}

int countOnes(int** A, int n) {
	int c = 0, j = n-1, i = 0;

	while (i < n && j >= 0)
    {
        if(A[i][j] == 1){
            c += j+1;
            ++i;
        }
        else
            --j;
    }

	return c;
}
