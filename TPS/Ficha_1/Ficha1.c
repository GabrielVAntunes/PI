// Ficha 1

// 1. Diga, justificando, qual o output de cada um dos seguintes excertos de código em C.

// 1.

// int x, y;                    Inicializamos x e y como inteiros
// x = 3; y = x+1;              Atribuimos a x o valor 3 e a y o valor x + 1 (3 + 1 = 4)
// x = x*y; y = x + y;          x vai passar a ser x*y (3 * 4 = 12) e y vai passar a ser x + y (12 + 4 = 16)
// printf("%d %d\n", x, y);     Escrevemos os valores finais de x e de y, 12 e 16 respetivamente


// 2. 

// int x, y;                    Inicializamos x e y como inteiros       
// x = 0;                       Atribuimos a x o valor 0
// printf ("%d %d\n", x, y);    Escrevemos os valores de x e y. Note-se que como y não foi declarado este irá assumir um valor 
//                               aleatório que pode gerar comportamentos imprevisiveis no programa


// 3. 

// char a, b, c;                            Inicializamos a, b, c como caracteres
// a = ’A’; b = ’ ’; c = ’0’;               Atribuimos ao a o valor 'A', ao b o valor ' ' e ao c o valor '0' (Nota: este 0 não é um número mas sim a "letra" 0)
// printf ("%c %d\n", a, a);                As "eqtiquetas" %c: caracter e %d: decimal, indicam o tipo de valor que será escrito, no caso vamos escrever 'A' e 65 (valor de 'A' na tabela ASCII)
// a = a+1; c = c+2;                        a vai passar a ser a + 1 (65 + 1 = 66 ('B') ) e c vai passar a ser c + 2 (48 + 2 = 50 ('2'))
// printf ("%c %d %c %d\n", a, a, c, c);    Análogo à 3ª linha. Será escrito 'B' 66 '2' 50
// c = a + b;                               c vai passar a ser a + b (66 + 32 = 98 ('b') )
// printf ("%c %d\n", c, c);                Escrevemos 'b' 98


// 4.

// int x, y;                                Incializamos x e y como inteiros
// x = 200; y = 100;                        Atribuimos a x o valor 200 e a y o valor 100
// x = x+y; y = x-y; x = x-y;               x vai passar a ser x + y (200 + 100 = 300), y vai passar a ser x - y (300 - 100 = 200) e x vai passar a ser x - y (300 - 200 = 100)
// printf ("%d %d\n", x, y);                Escrevemos os valores de x e de y, 100 200 respetivamente


// 2. Diga justificando, qual o output dos seguintes excertos de código C.

// a) 

// int x, y;
// x = 3; y = 5;
// if (x > y)                       Chegamos ao if como 3 > 5, uma vez que a condição é falsa ignoramos a linha seguinte  
// y = 6;
// printf ("%d %d\n", x, y);        O programa escreve 3 5


// b) 

// int x, y;
// x = y = 0;                       x e y são iguais a 0
// while (x != 11) {                Vamos repetir o ciclo enquanto x for diferente de 11
// x = x+1; y += x;                 a cada iteração vamos somar 1 a x, ou seja o programa vai realizar o ciclo 11 vezes
// }                                y = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 = 66
// printf ("%d %d\n", x, y);        Escrevemos os resultados, 11 66


// c)

// int i;                           inicializamos i como um inteiro
// for (i=0; (i<20) ; i++)          Criamos um ciclo for que atribui a i o valor 0, itera até a condição ser falsa e no fim de cada iteração incrementa uma unidade ao i, ou seja, vai repetir o ciclo 20 vezes
// if (i%2 == 0) putchar (’_’);     A cada iteração a função verifica se o i é par e caso seja escreve '_', caso contrário escreve '#'
// else putchar (’#’);              O resultado final será uma linha de 10 caracteres alternadas com "_" e "#": "_#_#_#_#_#_#_#_#_#_#"


// d)

// void f (int n) {                       A função guarda em n o valor que recebeu como argumento ao ser chamada, neste caso o número da iteração
// while (n>0) {                          Vai percorrer o ciclo enquanto o n for positivo
    // if (n%2 == 0) putchar (’0’);       Se for par, escreve 0
    // else putchar (’1’);                CC. (se for impár) escreve 1
    // n = n/2;                           por fim divide o n por 2
    // }
// putchar (’\n’);                        depois de sair do ciclo while faz um parágrafo (\n = new line) para ficarem mais claros os resultados
// }

// int main () {                Começamos pela função main
// int i;                       Inicializamos o i como um inteiro
// for (i=0;(i<16);i++)         Criamos o ciclo for que vai iterar 16 vezes
//     f (i);                   A cada iteração do ciclo for, vamos chamar a função f com o argumento i
// return 0;
// }                            Nota: Esta função vai escrever os números todos em binário ao contrário, do 1 ao 15


// 3. Escreva programas que desenhem as seguintes figuras no ecra

void ex3_1(int N){
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}


void ex3_2(int N){
    int j = 0;
    for (int i = 0; i < N; i++) {
        for(j; j < N * (i+1); j++) {
            if (j % 2 == 0) putchar('#');
            else putchar('_');
        }
        putchar('\n');
    }
}


// 4) Escreva um programa que desenhe no ecran (usando o caracter #) um circulo. Faça com que a função que desenha o círculo retorne o número de ’#’ impressos, e
//inspeccione os resultados obtidos em algumas experiências.

int ex4(int raio){

    int counter = 0; 

    for (int y = -raio; y <= raio; y++){        // o x e o y vão funcionar como coordenadas e vamos decidir o caracter escrito nessa posição consoante a distancia ao centro
        for (int x = -raio; x <= raio; x++){

            if(x*x + y*y <= raio*raio){         // Expressão matemática do círculo.
                putchar('#');
                counter++;
            } else putchar(' ');
        }

        putchar('\n');
    }
    return counter;
}


int main () {                

printf("%d", ex4(4));
return 0;

}
