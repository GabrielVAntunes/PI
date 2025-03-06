#include <stdio.h>

void triangulo(int N){

    for (int i = 1; i <= N; i++){

        for (int c = N - i; c > 0; c--){
            putchar(' ');
        }

        for (int j = 2 * i - 1; j > 0; j--){
            putchar('#');
        }

        putchar('\n');

    }

}