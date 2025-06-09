#include <stdio.h>
#include <string.h>

// 1. Defina um programa que lê uma sequência de números inteiros terminada com o número 0 
//e imprime no ecran o maior elemento da sequência.

int q1(){  // Estou a assumir que os valores são todos positivos

    int a = -1; 
    int max = -1;

    while(a!=0){                        // Percorremos o ciclo até o a ser 0
        printf("Introduza um valor: ");
        scanf("%d", &a);                // Lemos o valor do utilizador

        if (max < a) max = a;           // Se o nosso a for maior que o max, então o max passa a ser igual ao a atual
    }

    return max;
}

// 2. Defina um programa que lê uma sequência de números inteiros terminada com o número 0 
//e imprime no ecran a média da sequência.

float q2(){  // Estou a assumir que os valores são todos positivos

    int a = -1; 
    float sum = 0;
    int numCounter = -1; //Aqui inicializei a -1 para ignorar quando o utilizador colocar o 0 final

    while(a!=0){             
        printf("Introduza um valor: ");
        scanf("%d", &a);                // Lemos o valor do utilizador

        sum += a;                       // Fazemos o somatório de todos os a's
        numCounter++;                   // Contamos os valores para depois dividir
    }

    return sum/numCounter;
}

// 3. Defina um programa que lê uma sequência de números inteiros terminada com o número 0
//e imprime no ecran o segundo maior elemento.

int q3(){  

    int a = -1; 
    int fst = -1;
    int snd = -1;

    while(a!=0){                        // Percorremos o ciclo até o a ser 0
        printf("Introduza um valor: ");
        scanf("%d", &a);                // Lemos o valor do utilizador

        if (fst < a) {                  // Verificamos se a nossa maior é menor que a, nesse caso passamos fst para snd e atualizamos fst
            snd = fst;
            fst = a;
        } else if (snd < a) {           // CC. Verificamos apenas se a segunda maior é menor que a, nesse caso atualizamos snd
            snd = a;
        }
    }

    return snd;
}

// 4. Defina uma função que calcula o número de bits iguais a 1 usados na representação binária de um dado número n.

int bitsUm (unsigned int n) {
    int counter = 0;

    while(n>0){

        if(n%2!=0) counter++;   // Algoritmo parecido ao da Ficha 1, em vez de escrever, desta vez contamos os 1's
        n /=2;
    }
    return counter;
}

// 5. Defina uma função que calcula o número de bits a 0 no final da representação binária de um número 

int trailingZ (unsigned int n){  // NOTA*: o algoritmo do exercício anterior calcula o valor binário do número 
                                        //de trás para a frente, a estratégia será contar os até que o resultado seja 1
    int counter = 0;

    while(n>0){

        if(n%2==0) counter++;  
        else return counter; 
        n /=2;

    }
    return counter;
}

// 6. Defina uma função que calcula o número de dı́gitos necessários para escrever o inteiro n em base decimal. 
//Por exemplo, qDig (440) deve retornar 3.

int qDig (unsigned int n){

    int counter = 0; 

    while(n!=0){        // Se formos efetuando devisões inteiras por 10 vamos estar a retirar um dígito de n
        n/=10;          //logo basta contar o número de iterações que fizemos ao ciclo
        counter++;
    }
    return counter;
}

// É importante prestar atenção quando o enunciado diz que as funções são pré definidas, significa que as podemos usar no teste...
// 7. Apresente uma definição da função pré-definida em C char *strcat (char s1[], chars2[]) 
//que concatena a string s2 a s1 (retornando o endereço da primeira).

char *q7(char str1[], char str2[]){    //Assumindo que a str1 tem espaço suficiente para guardar a str2

    int i = 0;
    int j = 0;

    while(str1[i] != '\0'){             // Avançamos a str1 completamente
        i++;
    }

    while(str2[j] != '\0'){             // Na posição onde termina str1, começamos a escrever a str2 e ambas vão avançando
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';                     // Marcamos que a string terminou

    return str1;           
}

// 8. Apresente uma definição da função pré-definida em C char *strcpy (char *dest, char source[]) 
//que copia a string source para dest retornando o valor desta última.

char *q8(char *dest, char source[]){

    int i = 0; 

    while(source[i] != '\0'){      // Parecido ao anterior mas desta vez escrevemos nas mesmas posições em dest
        dest[i] = source[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}

// 9. Apresente uma definição da função pré-definida em C int strcmp (char s1[], char s2[])
//que compara (lexicograficamente) duas strings. O resultado deverá ser:
//
//          • 0 se as strings forem iguais
//          • <0 se s1 < s2
//          • >0 se s1 > s2

int q9 (char str1[], char str2[]){

    int i = 0; 

    while(str1[i] != '\0' && str2[i]!= '\0'){

        if(str1[i] > str2[i]) return 1;             // Vamos comparando letra a letra e retornamos caso sejam diferentes
        else if(str1[i] < str2[i]) return -1;

        i++;
    }

    if(str1[i] == '\0' && str2[i] == '\0') return 0;    // Caso ambas as strs tenham chegado ao fim ao mesmo tempo então são iguais
    else if(str1[i] == '\0') return -1;                 // Caso tenha sido a str1 a primeira, então é menor
    else return 1;                                      // CC a str2 é a menor 
}

// 10. Apresente uma definição da função pré-definida em C char *strstr (char s1[], chars2[]) 
//que determina a posição onde a string s2 ocorre em s1. A função deverá retornar NULL caso s2 não ocorra em s1.

char *q10 (char str1[], char str2[]){

    int i = 0;
    int j = 0;
    int checkpoint = 0;

    while (str1[i] != '\0') {       // Avançamos completamente a primeira string

        if(str1[i] == str2[j]) {    // Caso a letra seja igual...
            checkpoint = i;         // Marcamos onde começou caso tenhamos de voltar atrás
            while (str1[i] == str2[j] && str2[j] != '\0'){  // Enquanto forem iguais e a str2 não tiver terminado
                i++;            // Avançamos
                j++;
            }
            if (str2[j] == '\0') return &str1[checkpoint];   // Ao sair do while, caso str2[j] == '\0' quer dizer que toda a string
            else{                                           //estava contida na primeira, logo podemos retornar o ENDEREÇO da str1 na posição onde marcamos o checkpoint
                i = checkpoint + 1;     // Caso tenhamos iterado por 2 letras que não fossem iguais, o i avança para a posição a seguir ao checkpoint                                 
                j = 0;                  // Reiniciamos o j para depois começar a comparar com o inicio da palavra outra vez
            } 
        }
        i++;
    }

    return NULL;
}

// 11. Defina uma função que inverte uma string.

void strrev(char str[]){

    int i = 0;

    while(str[i] != '\0'){  // Percorremos a string até ao fim para saber o tamanho
        i++;
    }

    i--;                    // Aqui temos de decrementar uma unidade para sair do '\0'
    int size = i;           // Guardamos o tamanho

    while(i > size / 2){           // Trocamos um elemento do início com um elemento do fim
        char temp = str[i]; 
        str[i] = str[size - i];
        str[size - i] = temp;
        i--;
    }
}

// 12. Defina uma função  que retira todas as vogais de uma string.

int isVowel(char s) {

    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'         
        || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
        return 1;
    else return 0;
}

void strnoV (char str[]){

    int read = 0;
    int write = 0;

    while(str[read] != '\0'){

        if(!isVowel(str[read])) {       // Apenas escrevemos uma letra e consequentemente avançamos o índice
            str[write] = str[read];     //de escrita se não for uma vogal
            write++;
            }
        
        read++;
    }

    str[write] = '\0';          
}

// 13. Defina uma função que dado um texto t com várias palavras (as palavras estão separadas em  t por um ou mais espaços)
// e um inteiro n, trunca todas as palavras de forma a terem no máximo n caracteres.

void truncW (char t[], int n){

    int read = 0;
    int write = 0;
    int truncCounter = 0;

    while(t[read] != '\0'){     // Vamos percorrer a string inicial toda

        truncCounter = 0;       // reiniciamos o contador do número de letras que já escrevemos desta palavra
        while(truncCounter < n && t[read] != ' '){      // Iteramo enquanto o número de letras escritas for menor que n e enquanto não chegarmos a um espaço

            t[write] = t[read]; 
            truncCounter ++;
            write ++;
            read ++;
        }

        if (truncCounter == n){             // Caso tenhamos atingido o número de letras maximo, temos de percorrer o resto da palavra para depois "truncar" uma nova
            while(t[read] != ' ' && t[read] != '\0') read++;
        }

        t[write++] = t[read++]; // escrevemos o ' ' ou o '\0'

    }
}

// 14. Defina uma função  que determina qual o caracter mais frequente numa string. A função deverá retornar 0 no caso de s ser a string vazia.

char charMaisfreq (char t[]){

    if (t[0] == '\0') return 0;

    int read = 1;           // Indica onde estamos a ler
    int write = 1;          // Indica onde estamos a escrever
    int charIndex = 0;      // Indica qual o char que estamos a comparar
    char resp = t[0];       // resposta final
    int max = 0;            // valor máximo de aparições de algum char
    int sum = 1;            // soma das aparições do char atual
    char s[100];            // string cópia para não alterar a original

    strcpy(s, t);           // Apenas alteramos a string s

    while(s[charIndex] != '\0'){    // Iteramos até percorrermos todos os diferentes caracteres

        read = charIndex + 1;       // Vamos começar a ler e a escrever na posição depois do char que estamos a ver no momento
        write = read;
        sum = 1;                    // Reiniciamos a soma (a 1 porque temos de contar com o caracter que está a ser usado como comparação)
        while(s[read] != '\0') {    // Vamos ler todos os chars com o novo char que estamos a contar
            if(s[charIndex] != s[read]){    // Se for diferente escrevemos e avançamos
                s[write++] = s[read++];
            } else {                        // CC. Apenas avançamos
                read++;
                sum++;
            }
        }
        
        s[write] = s[read];                 // Escrevemos '\0'
        if (sum > max) {                    // Se este char tiver ultrapassado a conta do maximo registado, trocamos a resposta e atualizamos o maximo
            resp = s[charIndex];
            max = sum;
        }
        charIndex++;                        // Avançamos para o próximo char
    }

    return resp;
}

// 15. Defina uma função que, dada uma string s calcula o comprimento da maior sub-string com caracteres iguais. 

int iguaisConsecutivos (char s[]){

    int read = 0;
    int sum;
    int max = 0;

    while(s[read + 1] != '\0'){     // Neste caso temos de verificar para a posição "read + 1" para não tentar comparar o char com '\0'

        sum = 1;                    // Soma inicializada em 1 porque o número de comparações vai ser sempre menor uma unidade que o número de letras iguais (b=b=b)
        while(s[read] == s[read + 1]) {     // Enquanto estivermos a percorrer uma sequência de letras iguais...
            read++;
            sum++;
        }

        if (sum > max) max = sum;
        read++;
    }
    return max;
}

// 16. Defina uma função que, dada uma string s calcula o comprimento da maior sub-string com caracteres diferentes.

int difConsecutivos (char s[]){

    int read = 0; 
    int writeTemp = 1;          // Escreve apenas na string temporária
    int checkpoint = 0;         // Caso tenhamos que voltar atrás marca onde recomeçamos
    int sum = 1;              
    int max = 0;

    while(s[read + 1] != '\0'){

        char temp[100];             // Como criamos esta string dentro do while, ela só existe dentro desta iteração ou seja, na proxima iteração a lista é apagada e começa de novo
        temp[0] = s[read];          // Colocamos na primeira posição a letra que estamos a ler no momento
        writeTemp = 1;              // Vamos escrever depois da letra que adicionamos agora
        checkpoint = read;          // Vamos marcar o sitio de onde começamos a ler nesta iteração
        sum = 1;

        while(!strchr(temp, s[read + 1])){     // A função strchr devolve NULL caso o char não esteja contido na string temp, ou seja vamos iterar enquanto não encontrarmos uma letra que não esteja já presente em temp
            temp[writeTemp] = s[read + 1];     // Se não estava em temp vamos adicionar
            writeTemp++;                       
            sum ++;
            read++;
        }

        if(sum > max) max = sum;
        if(s[read] == '\0') return max;         // Condição apenas para se numa iteração chegarmos ao fim da string não vale a pena verificar as substrings seguintes que não serão maiores que o max já obtido (poupa algum trabalho ao pc)
        read = checkpoint + 1;
    }
    return max;
}

// 17. Defina uma função que calcula o comprimento do maior prefixo comum entre as duas strings.

int maiorPrefixo (char s1 [], char s2 []){

    int read1 = 0;
    int read2 = 0; 
    int sum = 0;

    //NOTA*: apenas temos que verificar se uma das strings acabou porque também estamos a verificar se são iguais
    while(s1[read1] != '\0' && s1[read1] == s2[read2]) {    // Enquanto nenhuma das palavras acabar e forem iguas somamos
        sum++;
        read1++;
        read2++;
    }

    return sum;
}

// 18. Defina uma função que calcula o comprimento do maior sufixo comum entre as duas strings.

int maiorSufixo (char s1 [], char s2 []){

    int read1 = 0;
    int read2 = 0;
    int sum = 0;

    while(s1[read1] != '\0' && s2[read2] != '\0'){      // Desta vez vamos percorrer as 2 strings até ao fim para comparar o sufixo de trás para a frente
        read1++;
        read2++;
    }

        // Aqui verificamos como é que as strings acabaram para alinhas ambas no primeiro char '\0'
    if (s1[read1] == '\0' && s2[read2] != '\0')    // A s1 acabou primero     
        while(s2[read2] != '\0') read2++;
    else if (s1[read1] != '\0')                    // A s2 acabou primeiro
        while(s1[read1] != '\0') read1++;

    read1--;
    read2--;    // Colocamos ambos na ultima letra

    while(read1 >= 0 && read2 >= 0 && s1[read1] == s2[read2]) {
        sum++;
        read1--;
        read2--;
    }

    return sum;
}

// 19. Defina a função que calcula o tamanho do maior sufixo de s1 que é um prefixo de s2. Por exemplo sufPref("batota","totalidade") deve
// como resultado 4, uma vez que a string "tota" é um sufixo de "batota" e um prefixo de "totalidade".

int sufPref (char s1[], char s2[]){

    int read1 = 0;
    int read2 = 0;
    int sum = 0;
    int checkpoint = 0;

    while(s2[read2] != '\0'){   

        read1 = 0;
        checkpoint = read2;

        while(s1[read1] == s2[read2] && s2[read2] != '\0'){ // Vamos verificando a maior sequência de letras iguais nas 2 strings
            read1++;
            read2++;
        }

        if(s2[read2] == '\0') return read1; // Se a sequência de iguais resultar no final da s2 então é o maior sufixo
            // A resposta será até onde chegamos no prefixo

        read2 = checkpoint + 1;
    }
    return sum;
}

// 20. Defina uma função que conta as palavras de uma string.

int contaPal (char s[]){

    int read = 0;
    int sumWords = 0;

    while(s[read] != '\0'){

        while(s[read] != ' ' && s[read] != '\0'){       // Percorremos as letras todas
            read++;
        }

        if(s[read] != '\0') while(s[read] == ' ') read++;   // Percorremos os espaços todos caso haja mais que 1

        sumWords ++;                                // No fim de percorrer cada palavra e os espaços que sucederem incrementamos
    }

    return sumWords;
}

// 21. Defina uma função que retorna o número de vogais da strings. Não se esqueça de considerar tanto maiúsculas como minúsculas.

int contaVogais (char s[]){

    int sum = 0;

    for(int i = 0; s[i] != '\0'; i++){
        if (isVowel(s[i])) sum++;
    }

    return sum;
}

// 22. Defina uma função que testa se todos os caracteres da primeira string também aparecem na segunda.

int contida (char a[], char b[]){

    for(int i = 0; a[i] != '\0'; i++){
        if(!strchr(b, a[i])) return 0;
    }
    return 1;
}

// 23. Defina uma função que testa se uma palavra é palı́ndrome, i.e., lê-se de igual forma nos dois sentidos.

int palindrome (char s[]){

    int i = 0;

    while(s[i] != '\0') i++;    // Percorremos para o fim para saber o tamanho da lista

    int size = --i;             // Efetuar uma operação com --VAR faz com que esta seja decrementada antes de a usarmos (size = i - 1 e i = i - 1)
    
    for(i = 0; i <= size/2; i++) if(s[i] != s[size - i]) return 0;  // Basta verificar até metade senão íamos estar a "reverificar"

    return 1;
}

// 24. Defina uma função que elimina de uma string todos os caracteres que se repetem sucessivamente deixando lá apenas uma cópia. 
//A função deverá retornar o comprimento da string resultante.

int remRep (char x[]){

    int read = 0; 
    int write = 0;

    while(x[read] != '\0'){ 

        while(x[read] == x[read + 1]) read++;   // Enquanto tivermos 2 letras consecutivas iguais vamos avançar

        if(x[read] != '\0'){         // as duas letras consecutivas já não são iguais então vamos escrever na string a "ultima" letra desta sequência
            x[write] = x[read];
            read++;
            write++;
        }

    }

    x[write] = '\0';
    return write;
}

// 25. Defina uma função que elimina repetições sucessivas de espaços por um único espaço. A função deve retornar o comprimento da string resultante.

int limpaEspacos (char t[]){

    int read = 0; 
    int write = 0;

    while(t[read] != '\0'){ 

        while(t[read] == t[read + 1] && t[read] == ' ') read++;  // Literalmente a função anterior mas acrescentamos a condição que os chars iguais têm de ser espaços 

        if(t[read] != '\0'){         
            t[write] = t[read];
            read++;
            write++;
        }

    }

    t[write] = '\0';
    return write;

}

// 26. Defina uma função que insere um elemento (x) num vector ordenado. Assuma que as N primeiras posições do vector estão ordenadas e que por
//isso, após a inserção o vector terá as primeiras N+1 posições ordenadas.

void insere (int v[], int N, int x){

    int temp;

    for(int i = 0; i < N; i++){ 
        if(v[i] > x) {  // Vamos sempre passando o elemento que queremos inserir um espaço para a frente
            temp = v[i];
            v[i] = x;
            x = temp;
        }
    }

    v[N] = x;
}

// 27. Defina uma função que, dados vectores ordenados a (com na elementos) e b (com nb elementos), preenche o vector r 
//(com na+nb elementos) com os elementos de a e b ordenados.

void merge (int r[], int a[], int b[], int na, int nb){


    int ia = 0;
    int ib = 0;

    while(ia < na && ib < nb){      // Avançamos ambos os arrays e comparamos os valores, escrevendo o menor

        if(a[ia] < b[ib]) {
            r[ia + ib] = a[ia];
            ia++;
        } else {
            r[ia + ib] = b[ib];
            ib++;
        }
    }

    if(ia < na) while (ia < na) {   // No fim escrevemos os valores que faltam do array que não terminou
        r[ia + ib] = a[ia];
        ia++;
    } else while (ib < nb) {
        r[ia + ib] = b[ib];
        ib++;
    }   
}

// 28. Defina uma função que testa se os elementos do vector a, entre as posições i e j (inclusivé) estão ordenados por ordem crescente. A função
//deve retornar 1 ou 0 consoante o vector esteja ou não ordenado.

int crescente (int a[], int i, int j){

    int index = 0;

    for (index = i; index < j && a[index] < a[index + 1]; index++){ // Percorremos o array tendo em conta as duas condições
    }

    if (index == j) return 1;   // Se saimos do for e o index não é igual a j quer dizer que encontramos 2 valores seguidos nesse intervalo que não eram crescentes
    else return 0; 
}

// 29. Defina uma função  que retira os números negativos de um vector com N inteiros. A função deve retornar o número de elementos
// que não foram retirados.

int retiraNeg (int v[], int N){

    int read = 0; 
    int write = 0;
    int negCounter = 0;

    while (read < N) {

        if(v[read] < 0){
            read++;
            negCounter++;
        } else {
            v[write] = v[read];
            write++;
            read++;
        }
    }

    while(write < N) v[write++] = 0;    // Não sei bem se era o objetivo mas preenchi o espaço restante com 0's
    return N - negCounter;
}

// 30. Defina uma função que recebe um vector v com N elementos ordenado por ordem crescente e retorna o menos frequente dos elementos do vector. 
//Se houver mais do que um elemento nessas condições deve retornar o que começa por aparecer no ı́ndice mais baixo.

int menosFreq (int v[], int N){

    int min = N + 1;
    int sum = 1;
    int resp = v[0];

    for(int i = 1; i < N; i++){    

        if (v[i] == v[i-1]){        // Enquanto estivermos numa sequência de iguais vamos somando
            sum++;
        } else {
            if(sum < min) {
                min = sum;
                resp = v[i-1];
                sum = 1;            // Caso tenhamos atualizado a resposta temos de fazer reset á soma
            }
        }

    }

    if(v[N - 1] == v[N - 2]){              // Caso para verificar o ultimo elemento
        sum++;
    } else {
        sum = 1;
    }

    if(sum < min) {
        min = sum;
        resp = v[N-1];
    }

    return resp;
}

// 31. Defina uma função que recebe um vector v com N elementos ordenado por ordem crescente e retorna o mais frequente dos elementos do vector.
//Se houver mais do que um elemento nessas condições deve retornar o que começa por aparecer no ı́ndice mais baixo.

int maisFreq (int v[], int N){  // Exatamente igual ao anterior apenas mudamos o critério de comparação

    int max = 0;
    int sum = 1;
    int resp = v[0];

    for(int i = 1; i < N; i++){    

        if (v[i] == v[i-1]){        // Enquanto estivermos numa sequência de iguais vamos somando
            sum++;
        } else {
            if(sum > max) {
                max = sum;
                resp = v[i-1];
                sum = 1;            // Caso tenhamos atualizado a resposta temos de fazer reset á soma
            }
        }

    }

    if(v[N - 1] == v[N - 2]){             // Caso para verificar o ultimo elemento
        sum++;
    } else {
        sum = 1;
    }

    if(sum > max) {
        max = sum;
        resp = v[N-1];
    }

    return resp;

}

// 32. Defina uma função que calcula o comprimento da maior sequência crescente de elementos consecutivos num vector v com N elementos.

int maxCresc (int v[], int N){

    int sum = 1;
    int max = 0; 

    for(int i = 0; i < N-1; i++){

        sum = 1; 

        while(v[i] < v[i + 1]){     // percorremos o máximo até deixarmos de ter 2 consecutivos crescentes
            sum++;
            i++;
        }

        if(max < sum){
            max = sum;
        }
    }
    return max; 
}

// 33. Defina uma função que recebe um vector v com N inteiros e elimina as repetições. A função deverá retornar o número de elementos do vector resultante.

//Auxiliar que verifica se um elemento pertence a um Array;
int inArr(int x, int N, int v[]){
    for(int i = 0; i < N; i++){
        if(x == v[i]) return 1;
    }
    return 0; 
}

int elimRep (int v[], int N){

    int read = 1;
    int write = 1;
    int remCounter = 0;

    int temp[N];
    temp[0] = v[0];

    while(read < N){

        if(inArr(v[read], write, temp)){
            read++;
        } else {
            temp[write] = v[read];
            read++;
            write++;
        }
    }

    for(int i = 0; i < write; i++){ // Copiamos os valores para o array original
        v[i] = temp[i];
    }
    return N - write;   // Subtraímos os elementos escritos ao total
}

// 34. Defina uma função que recebe um vector v com n inteiros ordenado por ordem crescente e elimina as repetições. 
//A função deverá retornar o. número de elementos do vector resultante.

int elimRepOrd (int v[], int N){    // Penso que se utilizasse a função anterior funcionaria igual

    int read = 1;
    int write = 1;
    int focus = 0;

    while(read < N){           

        while(v[read] == v[read - 1]){  // Acançamos enquanto for igual
            read ++;
        }

        focus++;
        v[focus] = v[read];         // Quando deixar de ser igual escrevemos o novo elemento e passamos a "prestar atenção" a esse
        read++;

    }
    return N - (focus + 1); // + 1 porque o índice 4 corresponde a 5 elementos escritos por exemplo
}

// 35. Defina uma função que calcula quantos elementos os vectores a (com na elementos) e b (com nb elementos) têm em comum. 
//Assuma que os vectores a e b estão ordenados por ordem crescente.

int comunsOrd (int a[], int na, int b[], int nb){

    int ia = 0;
    int ib = 0;
    int comCounter = 0;

    while(a[ia] < na && b[ib] < nb){        // Enquanto nenhum dos 2 acabar

        if(a[ia] == b[ib]) {                // Caso sejam iguais contamos e avançamos ambos
            comCounter++;
            ia++;
            ib++;
        } else if (a[ia] > b[ib]) ib++;     // Caso são sejam iguais avançamos o menor
        else ia++;
    }
    return comCounter;
}

// 36. Defina uma função que calcula quantos elementos os vectores a (com na elementos) e b (com nb elementos) têm em comum. Assuma
//que os vectores a e b não estão ordenados e defina a função sem alterar os vectores.

int comuns (int a[], int na, int b[], int nb){

    int comCounter = 0;

    for(int ia = 0; ia < na; ia++)              // Para cada valor de ia vamos ter de percorrer todo o array b e verficar todas as combinações possíveis
        for(int ib = 0; ib < nb; ib++){
            if(a[ia] == b[ib]) comCounter++;
        }
    return comCounter;
}

// 37. Defina uma função  que, dado um vector v com n inteiros, retorna o ı́ndice do menor elemento do vector.

int minInd (int v[], int n){

    int min = v[0]; 
    int index = 0;

    for(int i = 0; i < n; i++){         // Percorremos o array e vamos verificando, caso encontremos um menor que o mínimo atualizamos o mínimo e o índice
        if (v[i] < min) {
            index = i;
            min = v[i];
        }
    }
    return index;
}

// 38. Defina uma função que preenche o vector Ac com as somas acumuladas do vector v. Por exemplo, na posição Ac[3] deve ser calculado
//como v[0]+v[1]+v[2]+v[3].

void somasAc (int v[], int Ac [], int N){

    Ac[0] = v[0];

    for(int i = 1; i < N; i++){        
        Ac[i] = Ac[i-1] + v[i];
    }
}

// 39. Defina uma função  que testa se uma matriz quadrada é triangular superior, i.e., que todos os elementos abaixo da diagonal são zeros.

int triSup (int N, float m[N][N]){

    for(int lins = 0; lins < N; lins++)                       //  Para reduzir o número de iterações (menos pesado para o pc) basta percorrer cada linha até metade
        for (int cols = 0; cols < lins; cols++)               //uma vez que os números para cima da diagonal não interferem na noção de triangular superior
            if(lins > cols && m[lins][cols] != 0) return 0;     //  Tendo em conta que as linhas da matriz aumentam para baixo e as colunas para a esquerda
    return 1;                                                   //basta verificar se os elementos onde a linha é maior que a coluna são iguais a 0
}

// 40. Defina uma função que transforma uma matriz na sua transposta.
// NOTA*: uma matriz transposta é a matriz que obtemos ao espelhar na diagonal

void transposta (int N, float m [N][N]){    // NOTA*: Esta resolução só funciona para matrizes quadradas, se o enunciado não garantisse isso teria de pensar noutra solução
    for(int lins = 0; lins < N; lins++)
        for(int cols = 0; cols < lins; cols++){  // Ao contrário do ex anterior, neste só podemos mesmo percorrer até i, senão íamos estar a trocar 2 vezes
            int temp = m[lins][cols];
            m[lins][cols] = m[cols][lins];
            m[cols][lins] = temp; 
        }
}

// 41. Defina uma função que adiciona a segunda matriz à primeira.

void addTo (int N, int M, int a [N][M], int b[N][M]){

    for(int l = 0; l < N; l++)
        for(int c = 0; c < M; c++)
            a[l][c] += b[l][c];         // Basta percorrer a matriz e somar á primeira o valor da segunda na mesma posição
}

// 42. Uma forma de representar conjuntos de ı́ndices consiste em usar um array de inteiros contendo 1 ou 0 consoante esse ı́ndice 
//pertença ou não ao conjunto. Assim o conjunto {1, 4, 7} seria representado por um array em que as primeiras 8 posições conteriam {0,1,0,0,1,0,0,1}.
//Apresente uma definição da função que coloca no array r o resultado da união dos conjuntos v1 e v2.

int unionSet (int N, int v1[N], int v2[N], int r[N]){

    for(int i = 0; i < N; i++) 
        if(v1[i] == 1 || v2[i] == 1)        // Basta preencher consoante o resultado da condição
            r[i] = 1;
        else    
            r[i] = 0;
}

// 43. Uma forma de representar conjuntos de ı́ndices consiste em usar um array de inteiros contendo1 ou 0 consoante esse ı́ndice
//pertença ou não ao conjunto. Assim o conjunto {1, 4, 7} seria representado por um array em que as primeiras 8 posições conteriam {0,1,0,0,1,0,0,1}.
//Apresente uma definição da função que coloca no array r o resultado da intersecção dos conjuntos v1 e v2.

int intersectSet (int N, int v1[N], int v2[N],int r[N]){
    for(int i = 0; i < N; i++) 
        if(v1[i] == 1 && v2[i] == 1)        // Basta preencher consoante o resultado da condição
            r[i] = 1;
        else    
            r[i] = 0;
}

// 44. Uma forma de representar multi-conjuntos de ı́ndices consiste em usar um array de inteiros contendo em cada posição o 
//número de ocorrências desse ı́ndice. Assim o multi-conjunto {1, 1, 4, 7, 7, 7} seria representado por um array em que
// as primeiras 8 posições conteriam {0,2,0,0,1,0,0,3}.
//Apresente uma definição da função que coloca no array r o resultado da intersecção dos multi-conjuntos v1 e v2.

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    for(int i = 0; i < N; i++) 
        if(v1[i] < v2[i])        // Análogo ao anterior mas acrescentamos sempre o menor
            r[i] = v1[i];
        else    
            r[i] = v2[i];
}

// 45. No mesmo formato que o anterior. Apresente uma definição da função que coloca no array r o resultado da união dos multi-conjuntos v1 e v2.

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    for(int i = 0; i < N; i++) 
        if(v1[i] > v2[i])        // Análogo ao anterior unionSet mas acrescentamos sempre o maior
            r[i] = v1[i];
        else    
            r[i] = v2[i];
}

// 46. No mesmo formato que o anterior. Apresente uma definição da função que calcula o número de elementos do multi-conjunto v.

int cardinalMSet (int N, int v[N]){
    int sum = 0;
    for(int i = 0; i < N; i++) 
        sum += v[i];            // basta somar todos os elementos
    return sum;
}

// Considere as seguintes definições para representar as posições e movimentos de um robot.

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
int x, y;
} Posicao;

// 47. Defina a função que, dada uma posição inicial e um array com N movimentos, calcula a posição final do robot depois de efectuar
// essa sequência de movimentos.

Posicao posFinal (Posicao inicial, Movimento mov[], int N){ //Estou a assumir que as coordenadas estão no formato normal x: direita, y:cima

    Posicao final;
    final = inicial;

    for(int i = 0; i < N; i++){
        switch (mov[i]){
            case Norte:
                final.y++;
                break;
            case Sul:
                final.y--;
                break;
            case Este:
                final.x++;
                break;
            case Oeste:
                final.x--;
                break;
        }
    }
    return final;
}

// 48. Defina a função que, dadas as posições inicial e final do robot, preenche o array com os movimentos suficientes para que o robot
// passe de uma posição para a outra. A função deverá preencher no máximo N elementos do array e retornar o número de elementos preenchidos. 
//Se não for possı́vel atingir a posição final com N movimentos, a função deverá retornar um número negativo.

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){

    int moves = 0;

    while(inicial.x < final.x && moves < N){        // Percorremos em cada uma das 4 direções possíveis
        mov[moves] = Este;
        inicial.x++;
        moves++;
    }

    while(inicial.x > final.x && moves < N){
        mov[moves] = Oeste;
        inicial.x--;
        moves++;
    }

    while(inicial.y < final.y && moves < N){
        mov[moves] = Norte;
        inicial.y++;
        moves++;
    }

    while(inicial.y > final.y && moves < N){
        mov[moves] = Sul;
        inicial.y--;
        moves++;
    }

    // Se tivermos esgotado os movimentos e se as coordenadas iniciais e finais forem diferentes então não conseguimos traçar o caminho
    if (moves == N && (inicial.x != final.x || inicial.y != final.y)) return -1;    
    return moves;
}

// 49. Defina a função que, dado um array com N posições, determina o ı́ndice da posição que está mais perto da origem 
//(note que as coordenadas de cada ponto são números inteiros).

int maisCentral (Posicao pos[], int N){

            // na formula da distância normalmente faríamos sqrt disto, mas como estamos a trabalhar com inteiros
            //simplifiquei para o valor antes de sqrt
    int min = (pos[0].x * pos[0].x + pos[0].y * pos[0].y);  
    int index = 0;

    for(int i = 1; i < N; i++){
        int dist_ = (pos[i].x * pos[i].x + pos[i].y * pos[i].y);
        if(dist_ < min) {
            min = dist_;    // Este _ é panca minha porque não representa mesmo a distância ao centro 
            index = i;
        }
    }
    return index;
}

// 50. Defina a função que, dada uma posição e um array com N posições, 
//calcula quantas dessas posições são adjacentes à posição dada.

int vizinhos (Posicao p, Posicao pos[], int N){

    int sum = 0;
    for(int i = 0; i < N; i++){
        if((pos[i].x == p.x && (pos[i].y == p.y + 1 || pos[i].y == p.y - 1)) || // Caso mesmo x e acima ou abaixo
           (pos[i].y == p.y && (pos[i].x == p.x + 1 || pos[i].x == p.x - 1))) sum++;    // Caso mesmo y e direita ou esquerda
    }
    return sum;
}

void main(){
    //Test
}