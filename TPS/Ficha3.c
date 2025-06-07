#include <stdio.h>

// 1. Diga, justificando, qual o output de cada um dos seguintes excertos de código C

// a)

int ex1_a () {
    int x [15] = {1, 2, 3, 4, 5,
                  6, 7, 8, 9,10,
                  11,12,13,14,15};


    int *y, *z, i;  // inicializamos 2 apontadores inteiros y e z, e um valor inteiro i
    y = x; // y vai apontar para o valor na memória onde começa o array x, ou seja x[0]
    z = x+3;    // z vai apontar para o valor na memória onde começa o array x, ou seja x[3]
    for (i=0; i<5; i++) {
    printf ("%d %d %d\n", x[i], *y, *z);
    y = y+1; z = z+2;   // A cada iteração vamos avançar um espaço na memória com o apontador y
                        // A cada iteração vamos avançar dois espaços na memória com o apontador z
    }

    // Resultado esperado: "1 1 4\n"
    //                     "2 2 6\n"
    //                     "3 3 8\n"
    //                     "4 4 10\n"
    //                     "5 5 12\n"
}

// b) 

int ex1_b() {
    int i, j, *a, *b; // Inicializamos dois valores inteiros i e j, e dois apontadores inteiros a e b
    i=3; j=5;        
    //a = b = 42;       
    a = &i; b = &j;   // a vai apontar para o endereço da memória onde está guardado i e b para o endereço da memória onde está guardado j
    i++;             
    j = i + *b;       // b continua a apontar para j então esta linha é o mesmo que j = i + j (4 + 5 = 9)
    b = a;            // b vai passar a apontar para a, ou seja b -> a -> i
    j = j + *b;       // Vamos somar a j o valor para onde b está a apontar que é i (indiretamente) 9 + 4 = 13
    printf ("%d\n", j);  // Resultado esperado: "13\n"
    return 0;

    // Quando temos b estamos a considerar o "sitio" para onde estamos a apontar
    // Quando temos *b estamos a considerar o valor que está guardado naquele espaço de memória
}

// 2. Defina uma função que troca o valor de duas variáveis.

void swapM (int *x, int *y){    // O objetivo deste exercício é perceber que mesmo a função não retornando nada, podemos
                                //usar apontadores para numa função auxiliar alterar os valores na função principal
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Defina uma função que troca o valor das posições i e j do vector v.

void swap (int v[], int i, int j){  // Nesta situação como o que estamos a fazer é trocar os endereços de memória
    int temp ;                      //das posições no array as alterações também se mantém na função principal
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// 4. Defina uma função que calcula a soma dos elementos de um vector v com N inteiros.

int soma (int v[], int N){

    int sum = 0; 

    for (int i = 0; i < N; i++) {   // Percorremos o array e vamos somando ao resultado final
        sum += v[i];
    }

    return sum;
}

// 5. Defina uma função que inverte um array. Escreva duas
//versões, cada uma usando uma das funções das alı́neas anteriores.

void inverteArray_2 (int v[], int N){   // Versão com a função do exercício 2

    for (int i = 0; i< N/2; i++){ // Vamos apenas até metade do array senão íamos efetuar as trocas 2 vezes o que ia 
        swapM(&v[i], &v[N-1-i]);  //resultar num array igual.
    }
}

void inverteArray_3 (int v[], int N){   // Versão com a função do exercício 3

    for (int i = 0; i < N/2; i++){
        swap(v, i, N-1-i);
    }
}

// 6. Defina uma função que coloca em *m o maior dos elementos do vector v.
// A função deverá retornar 0 sse tal for possı́vel

int maximum (int v[], int N, int *m){
    if (N <= 0) return 1;

    for (int i = 0; i < N; i++) 
        if(v[i] > *m) *m = v[i];

    return 0;
}

// 7. Defina uma função que preenche o vector q com os quadrados dos primeiros 
//N números naturais ({0,1,4,9,...}.

// Versão com potencias
void quadrados_1 (int q[], int N){

    for (int i = 0; i < N; i++){
        q[i] = i*i;
    }
}

// Note que, uma vez que (a + 1)² = a² + (2 ∗ a + 1)
// Versão com esta estratégia

void quadrados_2 (int q[], int N){

    for (int i = 1; i < N; i++){
        q[i] = q[i-1] + (2*(i-1)+1);  
    }
}

// 8. O triângulo de Pascal é uma forma de calcular os coeficientes da expansão do binómio de Newton.
// (a) Defina uma função que preenche o vector v com a N-ésima linha do triângulo de Pascal.

void pascal(int v[], int N){

    int currLine = 1; 

    v[0] = 1;

    for (int i = 1; i <= N; i++){
        for (int l = i-1; l > 0; l--){      // Temos de correr a linha do fim para o ínicio pois caso contrário íamos 
            v[l] += v[l-1];                 //estar a alterar valores que precisaríamos para outros valores na mesma linha
        }
        v[i] = 1;
    }

}

// b) Adapte a função que definiu atrás para, em vez de preencher um array com a linha N do triângulo,
//escreva no ecran as N primeiras linhas do triângulo.

void pascal_2(int v[], int N){

    int currLine = 1; 

    v[0] = 1;
    printf("%d\n", v[0]);           // Printar a primeira linha já que esta não consta no ciclo

    for (int i = 1; i <= N; i++){
        printf("%d ", v[0]);        // Printamos o primeiro 1
        for (int l = i-1; l > 0; l--){       
            v[l] += v[l-1]; 
            printf("%d ", v[l]);    // Quando calcularmos o valor numa posição printamos imediatamente         
        }
        v[i] = 1;
        printf("%d\n", v[i]);       // No fim do ciclo printamos o ultimo 1 e mudamos de linha
    }

}

void main() {
    // Test
}
