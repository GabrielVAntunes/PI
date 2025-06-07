#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct aluno {  // Vamos definir a struct aluno
    int numero;         // Esta estrutura tem tudo o que está no seu interior, neste caso:
    char nome[100];     //um aluno é definido por número, nome, nota nos miniTestes e nota do teste
    int miniT [6];
    float teste;
    } Aluno;            // podemos definir variáveis deste tipo com: struct aluno x ou Aluno x;

// 1. Defina uma função que calcula a nota de um aluno (de acordo com as regras definidas para Programação Imperativa).
//A função deverá retornar 0 se o aluno não tiver aproveitamento.

//NOTA*: 80% Teste + 20% mini testes

int nota (Aluno a) {

    float finalGrade;
    float mTGrade;

    for (int i = 0; i < 6; i++){
        mTGrade += a.miniT[i];      // quando fazemos <struct>.variável estamos a aceder á variável com aquele nome dentro da struct
    }

    mTGrade /= 6;
    mTGrade *= 0.2;

    finalGrade = a.teste * 0.8 + mTGrade;

    if(finalGrade >= 9.5) return (finalGrade + 0.5);
    else return 0;
}

//2. Defina uma função que recebe um número de aluno e um array de alunos ordenado por ordem crescente de número
//de aluno e retorna o ı́ndice onde esse aluno está armazenado (retorna -1 se o número não existir).

int procuraNum (int num, Aluno t[], int N) {
    
    for (int i = 0; i < N; i++){    // Simplesmente percorremos o array de alunos e comparamos com o número que estamos à procura
        if (t[i].numero == num) return i;
    }
    return -1;
}

// 3. Defina uma função que ordena um array t de N alunos, por ordem crescente do seu número.

void ordenaPorNum (Aluno t[], int N){

    int i = 0;

    while(i < N - 1){
        if (t[i].numero > t[i+1].numero) {
            Aluno temp = t[i];
            t[i] = t[i+1];
            t[i+1] = temp;
            i = -1;
        }
        i++;
    }
}

// 4. Uma alternativa à função anterior consiste em calcular um array de ı́ndices em que na posição i se encontra 
//o ı́ndice correespondente ao i-ésimo elemento. Defina uma função que preenche o vector ind com os indices correspondentes
//a uma ordenação do array t por ordem crescente do número de aluno.

void criaIndPorNum (Aluno t [], int N, int ind[]) { // Vou assumir que recebemos um array de índices regular ou seja {0,1,2,...,N}

    int i = 0;

    while(i < N - 1){
        if (t[ind[i]].numero > t[ind[i+1]].numero) {    // Exatamente o mesmo raciocínio do anterior mas em vez de 
            int temp = ind[i];                          //fazer as trocas no array de alunos, fazemos no de índices
            ind[i] = ind[i+1];
            ind[i+1] = temp;
            i = -1;
        }
        i++;
    }
}

// 5. Defina uma função que recebe uma turma e um array tal como produzido pela função da alı́nea anterior
//e imprime os números, nomes e notas dos alunos por ordem crescente do número de aluno.

void imprimeTurma (int ind[], Aluno t[], int N){ // Se o array de índices já está consoante a ordem, basta percorrê-lo

    for(int i = 0; i < N; i++){                 //Percorrer pela lista de índices e depois aceder ao que queremos printar
        printf("Nome: %s\n", t[ind[i]].nome);
        printf("Número: %d\n", t[ind[i]].numero);
        printf("Mini-Testes:\n");
        for(int j = 0; j < 6; j++){
            printf("Mini-Teste %d: %d\n", j+1, t[ind[i]].miniT[j]);
        }
        printf("Teste: %f", t[ind[i]].teste);
        printf("\n");
    }
}

// 6. Adapte a função de procura definida na alinea 2 de forma a receber um array de alunos e um array tal como produzido
//pela função criaIndPorNum.

int procuraNum_2 (int num, Aluno t[], int N, int ind[]) {   // Não entendi bem qual era o objetivo desta pergunta mas está aí...
    
    for(int i = 0; i < N; i++){
        if(t[ind[i]].numero == num) return ind[i];
    }

    return -1;
}

// 7. Defina uma outra função que preenche o vector ind com os indices correspondentes a uma ordenação do array t
// por ordem crescente do nome do aluno.

void criaIndPorNome (Aluno t [], int N, int ind[]){

    for(int i = 0; i < N - 1; i++){

// Para utilizar a função strcmp(s1, s2) temos de dar import a <string.h> e vai retornar: {0-são iguais/<0-s1 é menor que s2/>0-s1 é maior que s2}
        if (strcmp(t[ind[i]].nome, t[ind[i+1]].nome) > 0){    //Raciocínio igual à criaIndPorNum, mas desta vez ordenamos alfabeticamente
            int temp = ind[i];
            ind[i] = ind[i+1];
            ind[i+1] = temp;
            i = -1;
        }
    }
}

void main(){
    //Test
}