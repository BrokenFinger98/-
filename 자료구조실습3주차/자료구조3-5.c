#pragma warning(disable:4996)
#include <stdio.h>

void hanoi(int N, char from, char tmp, char to);

int main(){
    int N;
    
    scanf("%d", &N);
    hanoi(N, 'A', 'B', 'C');

    return 0;
}

void hanoi(int N, char from, char tmp, char to){
    if(N == 1){
        printf("%c %c\n", from, to);
    }
    else{
        hanoi(N-1, from, to, tmp);
        printf("%c %c\n", from, to);
        hanoi(N-1, tmp, from, to);
    }
}

