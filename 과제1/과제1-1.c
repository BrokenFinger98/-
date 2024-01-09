#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int countOnesButSlow(int **A, int n);
int countOnes(int **A, int n);

int main(){
	int i, j, n;
	int **A = NULL;

	scanf("%d", &n);
	A = (int **)malloc(sizeof(int *)*n);
	if(A == NULL){
		printf("Not enough memory\n");
		return -1;
	}

	for(i = 0; i < n; ++i){
		A[i] = (int *)malloc(sizeof(int)*n);
		if(A[i] == NULL){
			printf("Not enough memory\n");
			return -1;
		}
		for(j = 0; j < n; ++j)
			scanf("%d", &A[i][j]);
	}

	printf("%d\n", countOnesButSlow(A, n));
	printf("%d\n", countOnes(A, n));
	
	for(i = 0; i < n; ++i)
		free(A[i]);
	free(A);

	return 0;
}

int countOnesButSlow(int **A, int n){
	int c = 0, j = 0, i;

	for(i = 0; i < n; ++i){
		j = 0;
		while ((j<n) && (A[i][j] == 1)){
			++c;
			++j;
		}
	}
	return c;
}

int countOnes(int **A, int n){
	int c = 0, j = 0, i = n-1;

	while ((i >= 0) && (j < n)){
		if(A[i][j] == 0){
			c += j;
			--i;
		}
		else
			++j;
	}
	if(i >= 0){
		while (i >= 0){
			c += j;
			--i;
		}
	}
	
	return c;
}
