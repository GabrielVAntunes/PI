#include <stdio.h>

void triangulo(int N){
    
    for (int i = 1; i < N; i++){
        for (int j = i; j > 0; j--){
            putchar('#');
        }
        putchar('\n');
    }

    for (int i = N; i > 0; i--){
        for (int j = i; j > 0; j--){
            putchar('#');
        }
        putchar('\n');
    }

}

void trianguloAlt(int N){

    int c = 1;
    int direction = 1;

    while(c > 0){

        for(int i = c; i > 0; i--){
            putchar('#');
        }
        putchar('\n');

        if (c == N) direction *= -1;         // Enquanto a direção for crescente, o c vai incrementar, depois de escrever a N-ésima linha mudamos o sinal de "direction" para que c decremente

        c += direction;
    }
}