#include <stdio.h>

// 1. Podemos calcular o produto de um número m por um inteiro n através de um somatório de n parcelas constantes.
//a uma variável r (inicialmente com o valor 0) será somado o valor de m, n vezes.

float ex1(int n, float m){

    float r = 0;

    for(int i = 0; i < n; i++){
        r += m;                         // r += m é o mesmo que r = r + m
    }

    return r;
}


// 2. Apresente uma definição alternativa da função float usando o seguinte processo. Dados dois números m e n podemos construir uma tabela em
//que vamos dividindo (divisão inteira) n por 2 e multiplicando m por 2. Para obter o valor do produto de n por m basta somar os
//valores de m correspondentes às linhas em que n é impar.

float ex2(int n, float m){

    float sum = 0;
    int i = 1;

    while(n > 1){

        if (n % 2 == 1){
            sum += m;
        }

        n / 2;
        m * 2;

    }

    return sum;
}


// 3. O cálculo do máximo divisor comum entre dois números inteiros não negativos pode ser feito, de uma forma muito pouco eficiente, procurando de entre os divisores do menor
//deles, o maior que é também divisor do outro.

int ex3(int a, int b){

    int greatest = 0;
    int lowest = 0;

    if (a > b){
        greatest = a;
        lowest = b;
    } else {
        greatest = b;
        lowest = a;
    }

    for(int i = lowest; i > 0; i--){
        if(lowest % i == 0){
            if(greatest % i == 0) return i;
        } 
    }
    return -1;
}


// 4. Apresente uma definição alternativa da função int que usa o método de Euclides

int ex4(int a, int b){

    while(a != b){

        if (a >= b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    return a;
}


// 5. Uma forma de tornar o algoritmo de Euclides mais eficiente é substituir as operações por %

int ex5(int a, int b){

    while(a != 0 && b != 0){

        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    return (a > b) ? a : b;             // Se a condição for verdadeira: a; CC: b
}


// 6. 
// a) Apresente uma definição recursiva que calcula o n-ésimo número da sequência de fibonacci.

int ex6_a(int n){

    if (n == 0) return 1;
    if (n == 1) return 1;

    return ex6_a(n - 1) + ex6_a(n - 2);
}

//  b) O cálculo do n-ésimo número de Fibonacci pode ser definido de uma forma mais eficiente 
//se repararmos que ele apenas necessita de conhecer os valores dos 2 valores anteriores.

int ex6_b(int n){

    int previous = 1;
    int pprevious = 1;
    int resp = 1;

    if (n == 0) return 1;
    if (n == 1) return 1;

    for(int i = 2; i <= n; i++){

        resp = previous + pprevious;
        pprevious = previous;
        previous = resp;

    }

    return resp;
}
