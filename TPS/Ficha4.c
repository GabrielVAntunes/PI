#include <stdio.h>

// 1. Defina uma função que conta quantas vogais uma string tem.

int contaVogais (char *s) {

    int i = 0;
    int vCounter = 0;

    while(s[i] != '\0'){   // '\0' indica o final de uma string, desta forma conseguimos executar o ciclo enquanto a string existir
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'         
        || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            vCounter++; // Verificamos se é vogal e se for incrementamos
        i++;
    }

    return vCounter;
}

// 2. Defina uma função  que remove de uma string todas as repetições consecutivas de vogais.
//A função deverá retornar o número de vogas removidas.

//NOTA*: Fiz apenas a versão sem o array auxiliar

// Função auxiliar que nos indica se um char é uma vogal
int isVowel(char s) {

    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'         
        || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
        return 1;
    else return 0;
}

int retiraVogaisRep (char *s){

    int read = 1;       // Este será o índice que indica onde estamos a ler
    int write = 1;      // Este será o índice que indica onde estamos a escrever
    int vCounter = 0;

    while(s[read] != '\0'){ // Lemos enquanto conseguirmos 
       
        if (isVowel(s[read]) && s[read] == s[read-1]){  // Se for vogal e for igual á anterior...
            vCounter ++;             // Contamos uma vogal removida
            read++;                  // Avançamos o índice onde estamos a ler
        } else {
            s[write] = s[read];      // Apenas escrevemos se não cumprir a condição de cima
            write++;                 // só quando escrevemos é que avançamos o sitio onde vamos escrever a seguir
        }
            
        read++;          // Quer tenhamos removido uma vogal quer não avançamos uma vez o índice que vamos ler
    }                   //No caso de termos removido avançamos uma vez pela vogal e uma vez para efetivamente ir para a proxima letra

    s[write] = '\0';    // Indicamos que a string terminou 

    return vCounter;
}

// 3. Defina uma função que duplica todas as vogais de uma string. A função deve retornar o número 
//de caracteres acrescentados. Assuma que o array recebido como argumento tem capacidade para armazenar 
//o resultado pretendido.

int duplicaVogais (char *s){

    int read = 0;
    int vCounter = 0;

    while (s[read] != '\0'){       // Vamos percorrer uma vez para saber de onde começar a escrever
        if (isVowel(s[read])) vCounter ++;  // Contamos já as vogais
        read++;
    }

    read--; // quado sair do ciclo o read vai ser o índice com '\0' então temos de recuar um para começar no indice do ultimo char
    int write = read + vCounter;

    while(read >= 0) {      // Agora vamos percorrer de novo só que do fim para o ínicio e escrever todas as duplicadas
        if(isVowel(s[read])){
            s[write--] = s[read];   //s[write--] faz com que o write seja decrementado depois da operação
            s[write] = s[read];
        } else {
            s[write] = s[read];
        }

        write--;
        read--;
    }

    return vCounter;
}

// ---------------------------  Arrays Ordenados ------------------------------- //

// 1. Defina uma função que testa se um array de inteiros está ordenado por ordem crescente.

int ordenado (int v[], int N){  // 0 corresponde a falso e 1 a verdadeiro

    for(int i = 0; i < N - 1 ; i++){    // Simplesmente comparamos o elemento atual com o proximo e vemos se este estão crescentes
        if(v[i] > v[i+1]) return 0;     // Se o ciclo terminar está ordenado, CC não está.
    }
    return 1;
}

// 2. Defina uma função que recebe dois arrays ordenados a e b (com tamanhos na e nb respectivamente) 
//e os funde num só array ordenado r. 
//Assuma que o array r tem capacidade para armazenar os na+nb elementos.

void merge (int a[], int na, int b[], int nb, int r[]){

    int ia = 0;
    int ib = 0;

    while (ia < na && ib < nb){ // Percorremos ambos os arrays colocando o valor mais baixo em r
        if(a[ia] < b[ib]) {
            r[ia + ib] = a[ia]; // Repare-se que a soma dos índices que já vimos corresponde ao total de números escritos em r
            ia++;               //logo ia+ib será o índice para onde temos de escrever
        } else {
            r[ia + ib] = b[ib];
            ib++;
        }
    } // Saímos do ciclo quando algum dos arrays terminar

    if (ia == na) { // Verificamos qual dos arrays terminou e escrevemos tudo o que restou no outro
        while(ib < nb) {
            r[ia + ib] = b[ib];
            ib++;
        }
    } else { 
        while (ia < na){ r[ia + ib] = a[ia];
        ia++;
        }
    }
}

// 3. Defina uma função  que, dado um array v de tamanho N e um inteiro x, 
//reorganiza o array de forma a que começam por aparecer todos os elementos menores ou iguais a x 
//seguidos dos restantes elementos. A função retorna o número de elementos que ficaram 
//na primeira parte do array (i.e., que são menores ou iguais a x)

int partition(int v[], int N, int x) {  // Tem alguns bugs mas o essencial funciona
    int i = 0, j = N;  

    while (i < j) { 
        if (v[i] <= x) {    // Vemos se os elementos do ínicio são menores ou iguais a x se forem avançamos o i
            i++;

        } else {            //C.C. trocamos o elemento em i com o elemento em j e depois recuamos o j

            int temp = v[i];
            v[i] = v[j-1];
            v[j-1] = temp;
            j--;
        }                   // Assim só vamos trocar até conseguir dividir os conjuntos separado por maior que x e menor que x
    }
  
    for (int j = N; j > i; j--) {   // por fim escrevemos os valores todos que faltam e inserimos o x
        v[j] = v[j-1];
    }
    v[i] = x;
    return i;  
}


void main() {
    //Test
}
