#include <stdio.h>
#include <stdlib.h>

//Considere o seguinte tipo para representar listas ligadas de inteiros

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

// 1. Apresente uma definição não recursiva da função que calcula o comprimento de uma lista ligada.

int length (LInt l){

    int sum = 0;
    while(l != NULL) {
        sum++;
        l = l->prox;    // Aqui apesar de ser uma struct, como l é um pointer somos obrigados a usar -> em vez de .
    }
    return sum;
}

// 2. Apresente uma definição não recursiva da função que liberta o espaço ocupado por uma lista.

void freeL (LInt l){

    while(l != NULL){   // Percorremos a lista até ao fim
        LInt temp = l;  // Guardamos o nó atual
        l = l -> prox;  // Avançamos para o próximo
        free(temp);     // Libertamos o atual
    }
}

// 3. Apresente uma definição não recursiva da função que imprime no ecran os elementos de uma lista (um por linha).

void imprimeL (LInt l){

    while(l != NULL){               // Basta percorrer a lista e imprimir o valor
        printf("%d\n", l->valor);
        l = l -> prox;
    }
}

// 4. Apresente uma definição não recursiva da função que inverte uma lista (sem criar uma nova lista).

LInt reverseL(LInt l) {
    LInt prev = NULL;
    LInt curr = l;

    while (curr != NULL) {
        LInt next = curr->prox;     // O nosso proximo vai ser o que ve a seguir ao atual
        curr->prox = prev;          // O nosso atual vai apontar agora para o anterior
        prev = curr;                // O anterior passa a ser o atual
        curr = next;                // O atual passa a ser o próximo
    }
    return prev;
}

// 5. Apresente uma definição não recursiva da função que insere ordenadamente um elemento numa lista ordenada.

void insertOrd (LInt *l, int x){        // Usamos *l quando se pode alterar o nodo que vai ser considerado a cabeça da lista
                                        //neste caso há chance de inserirmos um elemento à cabeça por isso é que temos de ter esse cuidado
    LInt new = malloc(sizeof(LInt));
    new->valor = x;
    new->prox = NULL;

    while((*l) && (*l)->valor < x){        // Avançamos até encontrar o espaço onde pertence o x
        l = &((*l)->prox);
    }

    new -> prox = (*l);         // O novo nodo que criamos no inicio vai ligar ao l
    (*l) = new;                 // O l vai passar a ser o new (é um bocado confuso, mas o l vai passar a ser o new e todos os nodos que seguem)
}

// 6. Apresente uma definição não recursiva da função que remove um elemento de uma lista ordenada. 
//Retorna 1 caso o elemento a remover não exista, 0 no outro caso.

int removeOneOrd (LInt *l, int x){

    while((*l) && x >= (*l)->valor){                    // Percorremos a lista
        if(x == (*l)->valor) {      // Se encontrarmos o valor que procuramos...
            LInt temp = (*l);       // Criamos uma lista temporária
            (*l) = (*l)-> prox;     // Substituímos o Nodo atual pelo proximo
            free(temp);             // Apagamos a Informação do que era o "Nodo atual"
            return 1;
        }
        l = &((*l)->prox);
    }
    return 0;
}

// 7. Defina uma função que junta duas listas ordenadas (a e b) numa única lista ordenada (*r).

void merge (LInt *r, LInt a, LInt b){

    while(a && b) {

        if(a->valor < b->valor){    // Ligamos r sempre ao menor valor
            *r = a;
            a = a-> prox;
        } else {
            *r = b;
            b = b-> prox;
        }      
        r = &((*r)->prox);          // Avançamos r para ir construíndo a lista
    }
    *r = (a == NULL) ? b : a;       // No fim completamos com a lista que sobrou (x ? y : z é o mesmo que if(x){y}else{z})
}

// 8. Defina uma função que, dada uma lista ligada l e um inteiro x, parte a lista em duas 
//(retornando os endereços dos primeiros elementos da lista em *mx e *Mx): uma com os elementos de l menores do que x
// e a outra com os restantes. Note que esta função não deverá criar cópias dos elementos da lista.

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){   // Parecido ao anterior

    while(l){   

        if(l->valor < x){       // Adicionamos a uma lista ou a outra consoante
            *mx = l;
            mx = &((*mx)->prox);
        } else {
            *Mx = l;
            Mx = &((*Mx)->prox);
        }

        l = l->prox;
    }
    (*mx) = NULL;
    (*Mx) = NULL;
}

// 9. Defina uma função que, parte uma lista não vazia *l a meio.
//Se x contiver os elementos 1,2,3,4,5, após a invocação y=parteAmeio(&x) a lista y deverá
//conter os elementos 1,2 e a lista x os restantes 3,4,5.

LInt parteAmeio (LInt *l){

    int half = length(*l)/2;        // Aproveitamos a função que definimos no inicio

    LInt y = (*l);                  
    LInt curr = NULL;

    for(int i = 0; i < half; i++){
        curr = (*l);                // Vamos igualando o curr ao nodo atual
        (*l) = (*l)->prox;          // E vamos avançando o nodo de l
    }   // No fim do ciclo o l será o nodo imediatamente após a metade e tudo o que se segue
    curr -> prox = NULL;            // Terminamos o curr para fechar a sequência de y, lembrando que y ficou a apontar para o ínicio de l
    return y;                   
}

// 10. Apresente uma definição não recursiva da função que remove todas as ocorrências de um dado inteiro de uma lista, 
//retornando o número de células removidas.

int removeAll (LInt *l, int x){

    int remCounter = 0;

    while(*l){
        if((*l)->valor == x){
            LInt temp = (*l);
            (*l) = (*l)->prox;
            free(temp);
            remCounter++;
        } else {
            l = &((*l)->prox);
        }
    }
    return remCounter;
}

// 11. Apresente uma definição da função que remove os valores repetidos de uma lista (deixando apenas a primeira ocorrência).

// Auxiliar para verificar se aquela variável já se encontra "registada"
int isIn(int x, int a[], int N){
    for(int i = 0; i < N; i++){
        if(x == a[i]) return 1;
    }
    return 0;
}

int removeDups (LInt *l){

    int remCounter = 0;         // Conta os duplicados 
    int size = length(*l);      // Tamanho da LInt
    int checkList[size];        // Lista dos elementos já vistos na lista
    int i = 0;                  // Índice dos elementos escritos na lista

    while(*l){

        if(isIn((*l)->valor, checkList, i)){    // Se o valor atual já estiver na checkList
            LInt temp = (*l);                   // Apagamos o Nodo atual e fazemos que o anterior aponte para o próximo
            (*l) = (*l) -> prox;
            free(temp);
            remCounter++;                       // Incrementamos nos removidos
        } else {
            checkList[i++] = (*l)->valor;       // Acrescentamos á checkList
            l = &((*l)->prox);                  // Avançamos a lista
        }
    }   //NOTA*: Neste caso percorremos a lista de forma diferente dependendo do ramo do if
            // (*l) = (*l) -> prox; : Neste caso estamos a avançar o conteúdo da lista, ou seja o nó (*l) vai ser substituído pelo próximo
            // l = &((*l)->prox); : Neste caso apenas estamos a alterar o nodo que estamos a ter em consideração, em vez de estarmos a "olhar" para o nodo l, vamos "olhar" para o proximo
    return remCounter;
}

// 12. Apresente uma definição da função que remove (a primeira ocorrência) o maior elemento de uma lista não vazia,
//retornando o valor desse elemento.

// Auxiliar para obter o maior elemento de uma LLigada
int getGreaterL(LInt *l){
    int max = (*l)->valor;
    while(*l){
        if((*l)->valor > max) max = (*l)->valor;
        l = &((*l)->prox);
    }
    return max;
}

int removeMaiorL (LInt *l){

    int greatest = getGreaterL(l);      // Percorremos a lista uma vez com a auxiliar para obter o maior
    while(*l){
        if((*l)->valor == greatest){    // Depois fazemos como o removeAll mas no fim de remover o primeiro retornamos logo
            LInt temp = (*l);
            (*l) = (*l)->prox;
            free(temp);
            return greatest;
        } else {
            l = &((*l)->prox);
        }
    }
    return greatest;
}

// 13. Apresente uma definição não recursiva da função que remove o último elemento de uma lista não vazia 
//(libertando o correspondente espaço).

void init (LInt *l){

    while((*l)->prox != NULL){  // A unica diferença é que percorremos até ao proximo ser NULL em vez de o atual ser NULL
        l = &((*l)->prox);      
    }

    LInt temp = (*l);           // Assim vamos terminar de percorrer no ultimo elemento e basta apagar esse como é habitual
    (*l) = NULL;
    free(temp);
}

// 14. Apresente uma definição não recursiva da função que acrescenta um elemento no fim da lista.

void appendL (LInt *l, int x){

    while(*l){                  // Percorremos a lista até ao fim
        l = &((*l)->prox);
    }

        // NOTA*: o malloc consiste numa função que reserva um espaço na memória para o tipo que nós queremos, garantindo que aquele espaço é apenas daquele nodo
    LInt new = malloc(sizeof(LInt));   // Criamos um novo nodo e colocamos no final da lista
    new->valor = x;
    new->prox = NULL;
    (*l) = new;
}

// 15. Apresente uma definição da função que acrescenta a lista b à lista *a.

void concatL (LInt *a, LInt b){

    while(*a){                  // Percorremos a lista até ao fim
        a = &((*a)->prox);
    }

    (*a) = b;       // Análogo ao anterior mas apontamos para toda a lista
}

// 16. Apresente uma definição da função que cria uma nova lista ligada com
//os elementos pela ordem em que aparecem na lista argumento.

LInt cloneL (LInt l){

    LInt temp = malloc(sizeof(LInt));
    LInt clone = temp;

    while(l -> prox){                           // Percorremos a lista até ao ultimo elemento (para depois a terminar corretamente)
        temp-> prox = malloc(sizeof(LInt));     // Percorremos l e temp copiando l para temp, onde temp é uma nova LInt
        temp-> valor = l->valor;
        temp = temp -> prox;
        l = l -> prox;
    }

    temp -> valor = l -> valor;            // Para não estar a criar um nodo em vão que podia fazer como que o ultimo elemento ficasse com lixo da memória
    temp -> prox = NULL;                   //criamos o ultimo nodo fora do ciclo
    return clone;           // No fim retornamos clone em vez de temp porque clone está a apontar para o ínicio da LInt criada com temp, retornando assim a lista completa em vez do ultimo elemento
}

// 17. Apresente uma definição não recursiva da função que cria uma nova lista ligada com os elementos por ordem inversa.
//Por exemplo, se a lista l tiver 5 elementos com os valores [1,2,3,4,5] por esta ordem, a
//invocação cloneRev(l) deve corresponder a uma nova lista com os elementos [5,4,3,2,1] por esta ordem.

LInt cloneRev (LInt l){

    LInt clone = NULL;          // Desta vez criamos o NULL primeiro que será o nodo final de terminação

    while(l){

        LInt newNode = malloc(sizeof(LInt));        // Todas as iterações criamos um novo nodo
        newNode -> valor = l -> valor;              // Esse nodo vai ser cópia do nodo atual de l
        newNode -> prox = clone;                    // Aponta para o nosso clone
        clone = newNode;                            // O nosso clone vai avançar para este novo Nodo
        l = l->prox;                                // Avançamos l
    }
    return clone;
}

// 18. Defina uma função que calcula qual o maior valor armazenado numa lista não vazia.

int maximo (LInt l){

    int max = l -> valor;
    l = l->prox;

    while(l){       // algoritmo normal para percorrer uma lista só que em listas ligadas;
        if(l-> valor > max) max = l -> valor;
        l = l->prox;
    }
    return max;
}

// 19. Apresente uma definição iterativa da função que, dado um inteiro n e uma lista ligada de inteiros l,
//apaga de l todos os nodos para além do n-ésimo (libertando o respectivo espaço). 
//Se a lista tiver n ou menos nodos, a função não altera a lista.
//A função deve retornar o comprimento final da lista.

int take (int n, LInt *l){
    
    int nodes = 0; 
    while(nodes < n && (*l)){       // Percorremos até acabar a lista ou até chegar a n
        l = &((*l)->prox);          // Neste caso não mudamos o conteúdo apenas alteramos o nodo que estamos a "ver"
        nodes++;                    // Contamos os nodos que estamos a escrever
    }

    while((*l)){                    // Caso cheguemos a n, resta apagar o resto da lista
        LInt temp = (*l);
        (*l) = (*l) -> prox;        // Aqui já substituímos o conteúdo de (*l)
        free(temp);                 // lembrando de libertar o espaço na memória
    }
    return nodes;
}

// 20. Apresente uma definição iterativa da função  que, dado um inteiro n e uma lista ligada de inteiros l,
//apaga de l os n primeiros elementos da lista (libertando o respectivo espaço). Se a lista tiver n ou menos nodos,
//a função liberta a totalidade da lista. A função deve retornar o número de elementos removidos.

int drop (int n, LInt *l){

    int nodes = 0;              // Raciocinio parecido ao anterior mas agora podemos simplesmente ir sustituindo o nodo inicial
    while((*l) && nodes < n){
        LInt temp = (*l);
        (*l) = (*l) -> prox;        
        free(temp); 
        nodes ++;
    }
    return nodes;
}

// 21. O tipo LInt pode ser usado ainda para implementar listas circulares. Defina uma função que, 
//dada uma lista circular dá como resultado o endereço do elemento da lista que está N posições à frente.

// Lista circular:       1 -> 2
//                       ^    |
//                       |    v
//                       3 <- 4

LInt Nforward (LInt l, int N){

    for(int i = 0; i < N; i++){     // Simplesmente percorremos e devolvemos a posição em que ficamos 
        l = l -> prox;
    }
    return l;
}

// 22. Defina uma função que, dada uma lista l, preenche o array v com os elementos da lista. A função deverá preencher
// no máximo N elementos e retornar o número de elementos preenchidos.

int listToArray (LInt l, int v[], int N){ 

    int i = 0;
    while(i < N && l){      // Percorremos a lista enquanto houver lista, ou até chegarmos a N
        v[i] = l -> valor;  // Copiamos para o array;
        i++;                // Avançamos o array e  a Lint
        l = l->prox;
    }
    return i;
}

// 23. Defina uma função que constrói uma lista com os elementos de um array, pela mesma ordem em que aparecem no array.

LInt arrayToList (int v[], int N) {

    LInt temp  = malloc(sizeof(LInt));
    LInt new = temp;

    for(int i = 0; i < N - 1; i++, temp = temp -> prox){
       temp -> prox = malloc(sizeof(LInt));
       temp -> valor = v[i];
    }
    temp -> valor = v[N - 1];
    temp -> prox = NULL;
    return new;
}

// 24. Defina uma função  que, dada uma lista de inteiros, constrói uma nova lista de inteiros contendo as somas acumuladas
//da lista original (que deverá permanecer inalterada). Por exemplo, se a lista l tiver os valores [1,2,3,4] 
//a lista contruı́da pela invocação de somasAcL (l) deverá conter os valores [1,3,6,10].

LInt somasAcL (LInt l){

    LInt temp = malloc(sizeof(LInt));       // Criamos uma cabeça para a LInt
    LInt new = temp;                        // Mantemos guardada a posição da cabeça
    int prev = 0;                           // Valor no nodo anterior
    
    while(l -> prox){                       // Percorremos a Lista ligada (prox por causa da situação de terminação)
        temp -> valor = prev + l -> valor;      // Substituimos o valor do atual, pelo anterior mais o atual da original
        temp -> prox = malloc(sizeof(LInt));    // Guardamos espaço na memória para o proximo nodo
        prev = temp -> valor;                   // Atualizamos o prev
        temp = temp -> prox;
        l = l -> prox;
    }

    temp -> valor = prev + l -> valor;
    temp -> prox = NULL;
    return new; 
}

// 25. Defina uma função que, dada uma lista ordenada de inteiros, elimina dessa lista todos os valores repetidos 
//assegurando que o espaço de memória correspondente aos nós removidos é correctamente libertado.

void remreps (LInt l){

    int size = length(l);
    int temp[500];          // Valor seguro para preencher a lista
    int i = 0;

    LInt prev = NULL;           // Nodo auxiliar que vai guardar as posições para facilitar a religação dos nodos

    while(l){                               // Percorremos a LL
        if(!isIn(l -> valor, temp, size)){      // Caso o valor que estamos a ver não estivesse já no vetor, acrescentamos
            temp[i] = l -> valor;
            prev = l;               // Vamos guardar o ultimo nodo colocado como sendo anterior
            i++;    
            l = l -> prox;
        } else {                // Caso já tenha sido registado retiramos o nodo com esse valor
            LInt aux = l;
            l = l -> prox;
            free(aux);          
            prev -> prox = l;       // o previous vai ligar ao l atual;
        }
    }
}

// 26. Defina uma função  que coloca o primeiro elemento de uma lista no fim. Se a lista for vazia
//ou tiver apenas um elemento, a função não tem qualquer efeito prático (i.e., devolve a mesma lista que recebe
// como argumento). Note que a sua função não deve alocar nem libertar memória. Apenas re-organizar as células
//da lista.

LInt rotateL (LInt l){

    LInt aux = l;
    LInt sec = l -> prox;  // Guarda a posição do segundo elemento

    while(l -> prox){       // Avançamos até antes de NULL;
        l = l -> prox;
    }

    aux -> prox = NULL;    // Marcamos que a LInt terminou
    l -> prox = aux;       // Pomos a ultima posição a apontar para a que era a primeira 
    return sec;         // Retornamos a posição do segundo nodo
}

// 27. Defina uma função que parte uma lista l em duas: na lista l ficam apenas os elementos das posições ı́mpares;
//na lista resultante ficam os restantes elementos. Assim, se a lista x tiver os elementos [10,20,30,40,50,60] 
//a chamada y = parte (x), coloca na lista y os elementos [20,40,60] ficando em x apenas os elementos [10,30,50]

LInt parte (LInt l){        
    LInt evenL = l -> prox;     // O evenL será o segundo Nodo
    LInt temp = evenL;          // O temp é para não perdermos a posição do primeiro Nodo de indice par
    LInt oddL = l;              // O oddL é a lista dos índices pares

    while(temp && temp -> prox){    // Temos de verificar para temp e para temp -> prox por estarmos a considerar 2 nodos de cada vez
        oddL -> prox = temp -> prox;    // Avançamos os ímpares
        oddL = oddL -> prox;

        temp -> prox = oddL -> prox;    // Avançamos os pares
        temp = temp -> prox;
    }
    oddL -> prox = NULL;                // Fechamos a lista dos oddL
    return evenL;
}

// Considere o seguinte tipo para representar árvores binárias de inteiros

typedef struct nodo {
int valor; 
struct nodo *esq, *dir;
} *ABin;

// 28. Apresente uma definição da função que calcula a altura de uma árvore binária.

int altura (ABin t){    // Os raciocínios dos exercícios de árvores são parecidos aos das listas mas com recursividade
    if (t == NULL) return 0;
    int valorEsq = altura(t->esq);
    int valorDir = altura(t->dir);
    return (valorEsq > valorDir ? valorEsq : valorDir) + 1; // Somamos 1 ao comprimento do maior ramo
}

// 29. Defina uma função que cria uma cópia de uma árvore.

ABin cloneAB (ABin t){
    if(t == NULL) return NULL;                  // Quando chegarmos ao fim colocamos NULL   
    ABin clone = malloc(sizeof(ABin));          // Copiamos o Nodo atual e apontamos para os respetivos tamos esquerdo
    clone -> valor = t -> valor;                //e direito de t
    clone -> esq = cloneAB(t -> esq);
    clone -> dir = cloneAB(t -> dir);
    return clone;
}

// 30. Defina uma função que inverte uma árvore (sem criar uma nova árvore).

void mirror (ABin *t){      
    if(!*t) return;       
    ABin temp = (*t) -> esq;        // Trocamos a árvore da esquerda com a árvore da direita
    (*t) -> esq = (*t) -> dir;
    (*t) -> dir = temp;
    mirror(&((*t)->esq));           // Aplicamos a função ao lado esquerdo da árvore
    mirror(&((*t)->dir));           // Aplicamos a função ao lado direito da árvore
}

// 31. Defina a função que cria uma lista ligada de inteiros a partir de uma travessia inorder de uma árvore binária.
// NOTA*: Travessia inOrder vamos ao ramo mais à esquerda possível primeiro, depois colocamos a sua raís e aplicamos inOrder ao ramo direito
void inorder (ABin t, LInt *l){

    if(!t) return;                  // Quando chegamos ao fim de um ramo damos return para termianr a recursividade

    inorder(t -> esq, l);           // Percorremos a árvore até ao seu nodo mais à esquerda
    while (*l) l = &((*l)->prox);   // A lista recebida está no início, por isso temos de percorrer tudo até á ultima posição
    (*l) = malloc(sizeof(LInt));    // Criamos um novo Nodo e copiamos o conteúdo da árvore
    (*l) -> valor = t -> valor;
    (*l) -> prox = NULL;            // Colocamos prox = NULL caso seja o ultimo
    inorder(t -> dir, l);           // Agora vamos o máximo possível à esquerda em todos os ramos
}

// 32. Defina a função que cria uma lista ligada de inteiros a partir de uma travessia preorder de uma árvore binária.
// NOTA*: Travessia preOrder, visitamos sempre a raíz primeiro e depois aplicamos preOrder ao ramo esquerda e por fim aplicamos ao direito
void preorder (ABin t, LInt *l){

    if(!t) return;

    while(*l) l = &((*l)->prox);        // A diferença deste para o anterior é quando é que aplicamos a função aos seus ramos
    (*l) = malloc(sizeof(LInt));        // Neste caso priorizamos o Nodo da raíz antes do Nodo da esquerda e só depois o da direita
    (*l) -> valor = t -> valor;
    (*l) -> prox = NULL;
    preorder(t -> esq, l);
    preorder(t -> dir, l);
}

// 33. Defina a função que cria uma lista ligada de inteiros a partir de uma travessia posorder de uma árvore binária.
// NOTA*: Travessia posOrder, visitamos os ramos filhos antes de visitar a raíz

void posorder (ABin t, LInt *l){

    if(!t) return;

    posorder(t -> esq, l);          // Mais uma vez, desta vez priorizamos os ramos esquerdo e direito e só depois
    posorder(t -> dir, l);          //colocamos a raíz

    while(*l) l = &((*l)->prox);
    (*l) = malloc(sizeof(LInt));
    (*l) -> valor = t -> valor;
    (*l) -> prox == NULL;
}

// 34. Apresente uma definição da função que calcula o nı́vel (menor) a que um elemento está numa árvore binária (-1 caso não exista).

int depth (ABin t, int x){

    if(!t) return -1;               // Caso cheguemos ao fim da árvore quer dizer que não encontrámos o elemento
    if(t -> valor == x) return 1;   // Caso tenhamos encontrado retornamos 1 para que a função conte a profundida recursivamente

    int d1 = depth(t -> esq, x);    // Vamos buscar os valores de profundidade do tal elemento nos ramos esquerdo e direito
    int d2 = depth(t -> dir, x);

    if(d1 == d2 && d1 == -1) return -1; // Verificamos se ele não existia em nenhum dos ramos, se for o caso retornamos -1
    return d1 < d2  ? d2 + 1 : d1 + 1;  // Caso se tenha encontrado o valor somamos um ao ramo em que o elemento apresentou maior profundidade
}

// 35. Defina uma função  que liberta o espaço ocupado por uma árvore binária, retornando o número de nodos libertados.

int freeAB (ABin t){

    if(!t) return 0;

    int nodes = freeAB(t -> esq) + freeAB(t -> dir);    // Contamos e libertamos todos os nós à esquerda e à direita

    free(t);                // Libertamos a raíz atual
    return nodes + 1;       // Somamos 1 aos Nodos libertados
}

// 36. Defina uma função que remove (libertando o espaço respectivo) todos os elementos da árvore *a que estão a uma profundidade superior a l, retornando
//o número de elementos removidos. Assuma que a profundidade da raı́z da árvore é 1, e por isso a invocação pruneAB(&a,0)
//corresponde a remover todos os elementos da árvore a.

int pruneAB(ABin *t, int l){

    if (!(*t)) return 0;

    int nodes = pruneAB(&((*t) -> esq), l - 1) + pruneAB(&((*t) -> dir), l - 1);

    if (l <= 0) {
        int nodes = pruneAB(&(*t)->esq, l - 1) + pruneAB(&(*t)->dir, l - 1);    // Contamos os nodos já removidos e fazemos a chamada recursiva
        free(*t);       // Libertamos o espaço deste Nodo
        *t = NULL;      // Colocamos este Nodo como NULL para que a raíz que antes apontava para ele agora aponte para NULL
        return 1 + nodes;   // Acrescentamos 1 aos nodos 
    }
    return nodes;
}

// 37. Defina uma função que testa se duas árvores são iguais (têm os mesmos elementos e a mesma forma).

int iguaisAB (ABin a, ABin b){
    if(!a && !b)                    // Caso as duas árvores terminem ao mesmo tempo quer dizer que este ramo é igual
        return 1;                   
    else if(a -> valor != b -> valor)   // CC e caso os valores atuais sejam diferentes retornamos falso
        return 0;
    else {
        int valEsq = iguaisAB(a -> esq, b -> esq);      // CC Verificamos o valor dos ramos á esquerda e á direita
        int valDir = iguaisAB(a -> dir, b -> dir);
        return valEsq < valDir ? valEsq : valDir;       // retornamos o menor dos valores, que será sempre 0 a não ser que 
    }                                               //ambos os ramos sejam iguais
}

// 38. Defina uma função que, dada uma árvore binária, constrói uma lista com os valores dos elementos 
//que estão armazenados na árvore ao nı́vel n (assuma que a raiz da árvore está ao nı́vel 1).

LInt nivelL (ABin t, int n){

    if (!t) return NULL;    // Caso um ramo tenha menos que n de profundidade retornará NULL

    LInt new = NULL;        // Criamos um novo Nodo para guardar as alterações que fizermos 
        
    if (n == 1) {                       // Caso estejamos no nível que queremos transformar em lista:
        new = malloc(sizeof(LInt));
        new -> valor = t -> valor;
        new -> prox = NULL;             // Copiamos o nodo atual e retornamos
        return new;
    }

    LInt left = nivelL(t -> esq, n - 1);    // left será a LInt à esquerda do nodo atual
    LInt rigth = nivelL(t -> dir, n - 1);   // rigth será a LInt à direita do nodo atual
    if(!left && !rigth) return NULL;        // Caso nenhuma destas exista retornamos NULL
    else if(!left) new = rigth;             // Caso não exista á esquerda vamos só considerar á direita
    else {                                  // CC ligamos o ultimo elemento da LInt da esquerda ao primeiro elemento da lista da lista da direita 
        new = left;
        while(left -> prox) left = left -> prox;
        left -> prox = rigth;
    }

    return new;
}

// 39. Defina uma função que preenche o vector v com os elementos de a que se encontram no nı́vel n.
//Considere que a raı́z da árvore se encontra no nı́vel 1.

int nivelV (ABin a, int n, int v[]){
    
}

ABin newNodeT(int valor) {
    ABin node = malloc(sizeof(struct nodo));
    node->valor = valor;
    node->esq = node->dir = NULL;
    return node;
}

ABin criaArvore() {
    ABin a = newNodeT(5);
    a->esq = newNodeT(3);
    a->dir = newNodeT(8);

    a->esq->esq = newNodeT(1);
    a->esq->dir = newNodeT(4);

    a->dir->dir = newNodeT(10);

    return a;
}

ABin criaArvore2() {
    ABin a = newNodeT(5);
    a->esq = newNodeT(3);
    a->dir = newNodeT(8);

    a->esq->esq = newNodeT(1);
    a->esq->dir = newNodeT(3);

    a->dir->dir = newNodeT(10);

    return a;
}

LInt newNode(int val) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = val;
    new->prox = NULL;
    return new;
}

LInt fromArray(int arr[], int size) {
    if (size == 0) return NULL;
    LInt head = newNode(arr[0]), tail = head;
    for (int i = 1; i < size; i++) {
        tail->prox = newNode(arr[i]);
        tail = tail->prox;
    }
    return head;
}

LInt fromArrayCircular(int arr[], int size) {
    if (size == 0) return NULL;

    LInt head = newNode(arr[0]), tail = head;
    for (int i = 1; i < size; i++) {
        tail->prox = newNode(arr[i]);
        tail = tail->prox;
    }

    tail->prox = head; // Torna a lista circular

    return head;
}

void imprimeLCircle (LInt l, int n){

    int i = 0;
    while(i < n){               // Basta percorrer a lista e imprimir o valor
        printf("%d\n", l->valor);
        l = l -> prox;
        i++;
    }
}

void printABin(ABin a) {
    if (a == NULL) {
        printf(",");
        return;
    }

    printf("(%d ", a->valor);

    // Esquerda
    printABin(a->esq);
    printf(" ");

    // Direita
    printABin(a->dir);
    printf(")");
}


// Main para testar
int main() {
    ABin tree = criaArvore();
    ABin tree2 = criaArvore2();
    //ABin tree2 = cloneAB(tree);
    // LInt Ltree = NULL;
    // posorder(tree, &Ltree);

    LInt list = nivelL(tree, 3);
    printABin(tree);
    printf("\n");
    // printf("Iguais?: %d\n", iguaisAB(tree, tree2));
    // printABin(tree);
    imprimeL(list);
    printf("\n");
    //printABin(tree2);
    // imprimeL(Ltree);




    //printf("Size: %d\n", altura(tree));
}

