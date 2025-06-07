#include <stdio.h>

// 1. Diga, justificando, qual o output de cada um dos seguintes excertos de código C.

// 1)

void ex1() {
// Inicializamos as Variáveis x, y como valores inteiros
     int x, y;
// Atribuímos o valor 3 a x
     x = 3;
// Atribuímos o valor x + 1 a y (3 + 1 = 4)
     y = x+1;
// Atribuímos o valor x * y a x (3 * 4 = 12) e atribuímos o valor x + y a y ( 12 + 4 = 16)
     x = x*y; y = x + y;
     printf("%d %d\n", x, y);
// Resultado esperado: "12 16\n"
}

// 2)

void ex2() {
// Inicializamos as Variáveis x, y como valores inteiros
     int x, y;
// Atribuímos o valor 0 a x
     x = 0;
// Neste caso como não atribuímos nenhum valor a y, o valor guardado em y será instável e vai resultar em "lixo" que esteja
//acumulado na memória naquele momento
     printf ("%d %d\n", x, y);
// Resultado esperado: "0 <Valor y>\n"
}

// 3)

void ex3() {
// Inicializamos as Variáveis a, b, c como caracteres
    char a, b, c;
// Atribuímos a, b, c os valores 'A', ' ' e '0' respetivamente
    a = 'A'; b = ' '; c = '0';
// As etiquetas %c e %d representam "Caracter unico" e "valor Decimal", portanto vamos imprimir o char a e o seu valor numérico
    printf ("%c %d\n", a, a);
// Resultado esperado: "A 65\n"
// Vamos somar uma unidade a "a" e duas unidades a "c" isto faz com que o valor numérico aumente como na tabela ASCII
//as letras e números são representados todos seguidos, isto corresponde a avançar uma letra em "a" e avançar 2 dígitos em "c"
    a = a+1; c = c+2;
// Mais uma vez vamos imprimir o valor do caracter e o valor decimal de ambas as Variáveis
    printf ("%c %d %c %d\n", a, a, c, c);
// Resultado esperado: "B 66 2 50\n"
// Vamos Atribuir a "c" o valor de "a" e de "b" ou seja c = 66 + 32 = 98
    c = a + b;
// Ora como nos diz o enunciado o valor ASCII de 'a' é 97 logo 98 corresponderá a 'b'
    printf ("%c %d\n", c, c);
// Resultado esperado:"b 98\n"
}

// 4)

void ex4() {
// Inicializamos as Variáveis x, y como valores inteiros
    int x, y;
// A x Atribuimos 200 e a y Atribuimos 100
    x = 200; y = 100;
// A x atribuimos x + y (200 + 100 = 300), a y atribuimos x - y (300 - 100 = 200), a x atribuimos x - y (300 - 200 = 100)
    x = x+y; y = x-y; x = x-y;
// Ou seja trocamos os valores de x e de y
    printf ("%d %d\n", x, y);
// Resultado esperado: "100 200\n"
}


// 2. Diga, justificando, qual o output de cada um dos seguintes excertos de código C.

// a)

void exA() {
    int x, y;
    x = 3; y = 5;
// Verificamos se o valor de x é maior que o valor de y, neste caso é falso, logo vamos ignorar a cláusula
    if (x > y)
//Afirmação Falso, ignoramos esta linha
    y = 6;
    printf ("%d %d\n", x, y);
//Resultado esperado: "3 5\n"
}

// b)

void exB() {
    int x, y;
// Nesta linha estamos a atribuir 0 a x e a y, é importante saber que não podemos fazer isto ao inicializar uma variável
//por exemplo, não poderíamos fazer int x = y = 0;
    x = y = 0;
// Vamos executar a cláusula ENQUANTO a condição for verdadeira, neste caso, vamos executar 11 vezes
    while (x != 11) {
    x = x+1; y += x;
    }
    printf ("%d %d\n", x, y);
// Resultado esperado: "11 66\n"
}

// c) 

void exC() {
    int i;
// Na "estrutura" for temos de definir o valor inicial, a condição de paragem e o incremento, neste caso vamos executar o 
//ciclo 20 vezes
    for (i = 0; (i<20) ; i++)
//Neste caso vamos verificar quando é que i é par e vamos executar uma de 2 instruções conforme o resultado
    if (i%2 == 0) putchar ('_');
// A função "putchar(...)" escreve um unico caracter
    else putchar ('#');
//Resultado esperado: _#_#_#_#_#_#_#_#_#_#
}

// d) 

// Este exercício já envolve chamar uma função com parâmetros de entrada, o "n" será definido ou pelo utilizador
//ou por alguma parte do código principal
void f (int n) {
    // vamos repetir o ciclo while enquanto o n for maior que 0 (o n vai ser o número de vezes que vamos executar o ciclo)
    while (n>0) {
    // Quando n for par escrevemos um 0 e quando for ímpar escrevemos um 1
    if (n%2 == 0) putchar ('0');
    else putchar ('1');
    // Como o n é inteiro vamos efetuar divisão inteira por 2
    n = n/2;
    }
    // (n)ew line
    putchar ('\n');
    }

    int exD () {
    int i;
    // Vamos chamar a função f 16 vezes, com o número da iteração
    for (i=0;(i<16);i++)
    f (i);
    return 0;
    }

    // Este programa vai imprimir por linha (de trás para a frente) os números até 16 em binário


//   3. Escreva programas que desenhem as seguintes figuras no ecran. Para cada um deles faça a
//   sua solução baseada numa função que recebe como argumento a dimensão da figura.

// 1) Escreva um programa que desenhe no ecran (usando o caracter #) um quadrado.

void drawSquare(int size){

    // Simplesmente percorremos as linhas e as colunas e escrevemos um '#'
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            putchar('#');
        putchar('\n');      // No fim de completarmos uma linha mudamos de linha
    }

}

// 2) Escreva um programa que desenhe no ecran (usando os caracteres # e _) um tabuleiro de xadrez.

void chessBoard(int size){

    // Raciocinio parecido ao anterior mas agora temos de verificar se a soma da posição na linha e na coluna é par, nesse caso colocamos um '#'
    //C.C. colocamos um '_'
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) 
            if((i + j) % 2 == 0) putchar('#');
            else putchar('_');
        putchar('\n');
    }
}

// 3) Escreva duas funções que desenham triangulos (usando o caracter #).
// 3.1)

void sideTriangle(int size){

    // Primeiro escrevemos as linhas do triangulo com número crescente de '#'
    for(int i = 1; i <= size; i++) {
        for(int ii = 0; ii < i; ii++)
            putchar('#');
        putchar('\n');
    }
    // Depois escrevemos por ordem crescente
    for(int i = size - 1; i > 0; i--) {
        for(int ii = 0; ii < i; ii++)
            putchar('#');
        putchar('\n');
    }
}

// 3.2)

void triangle(int size){

    // Importante reparar que a base do triangulo tem i '#''s depois 1 '#' e por fim mais i '#''s
    // A ideia aqui é escrever antes desses i espaços em branco e depois nesse intervalo entre size - i e size + i escrever '#'
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size + i; j++){
            if(j < size - i) putchar(' ');
            else putchar('#');
        }
        putchar('\n');
    }
}


// 4) Escreva um programa que desenhe no ecran (usando o caracter #) um circulo.

void circle(int radius) {

    for (int i = 0; i <= radius * 2; i++){
        for (int j = 0; j <= radius * 2; j++){
            // utilizamos estas expressões para "centrar" o circulo
            int x = j - radius;
            int y = i - radius;
            // espressão do calculo da distancia de um ponto à origem, se a distancia for <= que o raio podemos escrever '#'
            if((x*x + y*y) <= radius*radius) putchar('#');
            else putchar(' ');
        }
        putchar('\n');
    }
}

void main(){
    //Test
}