#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int *prefixAverages1(int *p, int n);
int *prefixAverages2(int *p, int n);

int main() {
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    LARGE_INTEGER ticksPerSec2;
    LARGE_INTEGER start2, end2, diff2;
    int n, i;
    int *p = NULL;

    
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int)*n);
    if(p == NULL){
        printf("Not enough memory\n");
        return -1;
    }
    for(i = 0; i < n; ++i){
        p[i] = rand()%10000+1;
    }
    
    //prefixAverages1함수 실행시간 구하기
    QueryPerformanceFrequency(&ticksPerSec); 
    QueryPerformanceCounter(&start);
    prefixAverages1(p, n);
    QueryPerformanceCounter(&end);
    
    diff.QuadPart = end.QuadPart–start.QuadPart;
    printf("%.12fms\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)*1000); 
    
    //prefixAverages2함수 실행시간 구하기
    QueryPerformanceFrequency(&ticksPerSec2); 
    QueryPerformanceCounter(&start2);
    prefixAverages2(p, n);
    QueryPerformanceCounter(&end2);
    
    diff2.QuadPart = end2.QuadPart–start2.QuadPart;
    printf("%.12fms\n", ((double)diff2.QuadPart/(double)ticksPerSec2.QuadPart)*1000);
    
    free(p);
    
    return 0;
}

int *prefixAverages1(int *p, int n){
    int i, j, sum = 0;
    int *q = NULL;
    
    q = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; ++i){
        sum = 0;
        for(j = 0; j < i; ++j) 
            sum = sum + p[j];
        q[i] = sum/(i+1);
    }
    
    return q;
}

int *prefixAverages2(int *p, int n){
    int sum = 0, i;
    int *q = NULL;
    
    q = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; ++i){
        sum = sum + p[i];
        q[i] = sum/(i+1);
    }
    
    return q;
}