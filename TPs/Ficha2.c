#include <stdio.h>

// 1. Podemos calcular o produto de um número m por um inteiro n através de um somatório
//de n parcelas constantes (e iguais a m).

float multInt1 (int n, float m){

    float r = 0;

    for (int i = 0; i < n; i++){
        r += m;
    }

    return r;
}

// 2. Uma forma alternativa (e muito mais eficiente) consiste em aproveitar a representação binária dos inteiros 
//(onde a multiplicação e divisão por 2 são pelo menos tão eficiente como a adição).

float multInt2 (int n, float m){

    float oddIndexSum = 0;
    int i = 1;

    for (; n > 0; n /= 2, i++){     // Neste caso como a variável n já tem um valor associado é desnecessário atribuir-lhe um valor
            //   ^^^^^^^^^^^^^  ao colocar uma vírgula no ultimo parâmetro podemos indicar que é para incrementar das duas formas


        if (i % 2 != 0)      // Se o resto de i / 2 for diferente de 0 (se i for ímpar)
            oddIndexSum += m;   // vamos fazendo o somatório do valor m quando o Indice é ímpar

        m *= 2;         // m = m * 2
    }

    return oddIndexSum;
}

// 3. O cálculo do máximo divisor comum entre dois números inteiros não negativos pode ser feito, de uma forma 
//muito pouco eficiente, procurando de entre os divisores do menor deles, o maior que é também divisor do outro.

int mdc1 (int a, int b) {

    int greater, lower, mdc;

    if (a > b) {    // Verificamos qual é o maior entre a e b
        greater = a;
        lower = b;
    } else {
        greater = b;
        lower = a;
    }

    for(int i = lower; i > 0; i--){
        if (lower % i == 0 && greater % i == 0){    //Verificamos se é divisor de ambos
            mdc = i;
            i -= lower; // Aqui em vez de usar um "break" para sair do ciclo facilmente podemos subtrair lower a i, que 
            //independentemente do valor de i atualmente vai quebrar a condição "i > 0"
        }
    }

    return mdc;
}

// 4. Uma forma alternativa de calcular o máximo divisor comum (mdc) baseia-se na propriedade demonstrada por Euclides

int mdc2 (int a, int b){

    int greater, lower, mdc;

    if (a > b) {    
        greater = a;
        lower = b;
    } else {
        greater = b;
        lower = a;
    }

    while (greater != 0) {

        if (greater < lower) {   
            int temp = greater;         // Aqui temos de utilizar uma variável temporária para não perder nenhum dos valores
            greater = lower;
            lower = temp;
        }

        greater -= lower;
    }

    return lower;       // Como estamos sempre a subtrair no "greater" este vai ser o que atinge 0, quebrando a condição
                    //consequentemente o lower será a resposta
}

// 5. Uma forma de melhorar o comportamento do algoritmo de Euclides consiste em substituir as operações de subtracção 
//por operações de % (resto da divisão inteira).

int mdc3 (int a, int b){

    int greater, lower, mdc;

    if (a > b) {    
        greater = a;
        lower = b;
    } else {
        greater = b;
        lower = a;
    }

    while (greater != 0) {

        if (greater < lower) {   
            int temp = greater;         // Aqui temos de utilizar uma variável temporária para não perder nenhum dos valores
            greater = lower;
            lower = temp;
        }

        greater %= lower;
    }

    return lower;       // Como estamos sempre a subtrair no "greater" este vai ser o que atinge 0, quebrando a condição
                    //consequentemente o lower será a resposta
}

// 6. a) Apresente uma definição recursiva de uma função que calcula o n-ésimo número da sequência de Fibonacci.

int fib1 (int n) {

    if (n == 0 || n == 1) return 1; //quando chegarmos a n == 0 ou n == 1 retornamos 1 e quebramos a recursividade

    return fib1(n-1) + fib1(n-2); //retornamos a soma dos 2 anteriores
}

// b) O cálculo do n-ésimo número de Fibonacci pode ser definido de uma forma mais eficiente (e iterativa) se repararmos que ele apenas necessita de 
//conhecer os valores dos 2 valores anteriores. Apresente uma definição alternativa (e iterativa) da função da alı́nea anterior que calcula o 
//n-ésimo número de Fibonacci, usando duas variáveis auxiliares que guardam os dois valores anteriores.

int fib2 (int n) {

    if (n == 0 || n == 1) return 1;

    int previous = 1;
    int pprevious = 1;
    int resp;

    for (int i = 2; i <= n; i++){
        resp = pprevious + previous;
        pprevious = previous;
        previous = resp;
    }

    return resp;
}

void main(){
    //Test
}