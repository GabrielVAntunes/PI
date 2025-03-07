#include <stdio.h>
#include <string.h>

// 1. Defina um programa que lê uma sequência de números inteiros terminada com o número 0 e imprime no ecran o maior elemento da sequência.

// Assumamos que apenas são introduzidos valores positivos
int q1(){

    int max = 0;
    int num = 1;

    while (num != 0) {

        scanf("%d", &num);

        if (max < num) max = num;

    }

    return max;
}


// 2. Defina um programa que lê uma sequência de números inteiros terminada com o número 0 e imprime no ecran a média da sequência.

float q2(){

    float sum = 0;
    int num = 1;
    int count = 0;

    while (num != 0) {

        scanf("%d", &num);

        sum += num;
        if(num != 0) count ++;
    }
    return sum/count;
}


// 3. Defina um programa que lê uma sequência de números inteiros terminada com o número 0 e imprime no ecran o segundo maior elemento da sequência.

//Assumamos que são introduzidos pelo menos 2 valores e que são todos positivos

int q3(){

    int fst = 0;
    int snd = 0;
    int num = 1;

    while (num != 0) {

        scanf("%d", &num);

        if (fst < num) {
            snd = fst;
            fst = num;
        } else if (snd < num) snd = num;

    }

    return snd;
}

// 4. Defina uma função int bitsUm que calcula o número de bits iguais a 1 usados na representação binária de um dado número n.

int q4(unsigned int n){                                 // Algoritmo similar ao da ficha 1

    int counter = 0;
    int result = n;

    while (result != 0){

        if (result % 2 != 0) counter ++;
        result /= 2;

    }

    return counter;
}


// 5. Defina uma função que calcula o número de bits a 0 no final da representação binária de um número

int q5(unsigned int n){                                 // Apenas adaptei um pouco o exercício anterior                         

    int counter = 0;
    int result = n;

    while (result != 0){

        if (result % 2 == 0) {
            counter ++;
        } else return counter;
        result /= 2;

    }

    return counter;
}


// 6. Defina uma função que calcula o número de dígitos necessários para escrever o inteiro n em base decimal

int q6(unsigned int n){

    int counter = 0;

    while (n != 0){

        n /= 10;
        counter ++;

    }

    return counter;
}


// 7. Apresente uma definição da função pré-definida que concatena a string s2 a s1

char *q7(char s1[], char s2[]){

    int i = 0;
    int j = 0;

    while (s1[i] != '\0') {                  // '\0' é o caracter que indica o fim de uma string
        i++;
    }

    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';

    return s1;
}


// 8. Apresente uma definição da função pré-definida em C char *strcpy (char *dest, char source[]) que copia a string source para dest retornando o valor desta ṹltima.

char *q8(char *dest, char source[]){

    int i = 0;

    while (source[i] != '\0'){
        dest[i] = source[i];
        i++; 
    }

    dest[i] = '\0';

    return dest;
}


// 9. Apresente uma definição da função pré-definida que compara (lexicograficamente) duas strings

int q9(char s1[], char s2[]){

    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0'){

        if(s1[i] > s2[i]) {
            return 1;
        } else if (s1[i] < s2[i]) {
            return -1;
        }

        i++;
    }

    return 0;
}


// 10. Apresente uma definição da função pré-definida em C char *strstr (char s1[], char s2[]) que determina a posição onde a string s2 ocorre em s1. 
//A função deverá retornar NULL caso s2 não ocorra em s1.

char *q10(char s1[], char s2[]){

    int i = 0;
    int j = 0;

    for(int i = 0; s1[i] != '\0'; i++){

        j = 0;

        while (s1[i + j] == s2[j] && s2[j] != '\0'){
            j++;
        }

        if (s2[j] == '\0') return &s1[i];
    }

    return NULL;
}


// 11. Defina uma função void strrev (char s[]) que inverte uma string.

void q11 (char s[]) {

    char temp;
    int size = strlen(s);

    for (int i = 0; i < size / 2; i++){
        temp = s[i];
        s[i] = s[size - i - 1];                     // Este -1 deve se ao terminador da string '\0'
        s[size - i - 1] = temp;
    }

}


// 12. Defina uma função void strnoV (char s[]) que retira todas as vogais de uma string.

void q12 (char s[]){

    int i = 0;
    int j = 0;

    while (s[i] != '\0'){

        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {       // Não considerei maiusculas, bastaria acrescentar esses casos
            j = i;

            while (s[j] != '\0'){
                s[j] = s[j + 1];
                j++;
            }
        }
        i++;
    }
}


// 13. Defina uma função que dado um texto t com várias palavras (as palavras estão separadas em t por um ou mais espaços) e um inteiro n, trunca to-
//das as palavras de forma a terem no máximo n caracteres.

void q13 (char s[], int n){

    int i = 0;
    int ii = 0;
    char temp[strlen(s) + 1];

    while (s[i] != '\0') {

        if(s[i] != ' ') {
            for(int j = 0; j < n; j++){
                if(s[i] == ' ') break;
                temp[ii] = s[i];
                i++;
                ii++;
            }
        } else {
            i++;
            continue;
        }

        while(s[i] != ' ' && s[i] != '\0'){
            i++;
        }

        temp[ii] = ' ';
        ii++;
        i++;
    }

    temp[--ii] = '\0';
    strcpy(s, temp);
}


// 14. Defina uma função que determina qual o caracter mais frequente numa string. A função deverá retornar 0 no caso de s ser a string vazia.

char q14(char s[]){

    char temp[strlen(s)];
    int i = 0;
    int j = 0;

    while(s[i] != '\0'){

        if (!strchr(temp, s[i])){
            temp[j++] = s[i];
        }

        i++;
    }

    temp[j] = '\0';

    char resp;
    int max = 0;
    int sum = 0;

    j = 0;

    while (temp[j] != '\0') {

        sum = 0;
        i = 0;

        while (s[i] != '\0'){
            if (temp[j] == s[i]) {
                sum ++;
            }
            i++;
        }
        
        if (max < sum) {
            max = sum;
            resp = temp[j];
        }

        j++;
    }

    return resp;
    
}


// 15. Defina uma função que, dada uma string s calcula o comprimento da maior sub-string com caracteres iguais

int q15 (char s[]){

    char c = s[0];
    int i = 1;
    int sum = 1;
    int max = 0;

    while (s[i] != '\0'){
        
        if(c == s[i]){
            sum ++;
        } else {
            c = s[i];
            sum = 1;
        }

        if(max < sum) max = sum;
        i++;
    }
    return max;
}


// 16. Defina uma função que, dada uma string s calcula o comprimento da maior sub-string com caracteres diferentes.

int q16 (char s[]){

    char temp[strlen(s)];
    int i = 0;
    int j = 0;
    int sum = 1;
    int max = 0;
    int iTemp;

    while (s[i] != '\0'){
        
        j = i;
        iTemp = 0;
        memset(temp, '\0', sizeof(temp));               // função para apagar o conteúdo da string "temp"
        sum = 0;

        while (s[j] != '\0'){

            if(!strchr(temp, s[j])){
                temp[iTemp] = s[j];
                iTemp++;
                sum++;
            } else {
                break;
            }

            j++;
        }

        if(max < sum) {
            max = sum;
            printf("%s\n", temp);
        }
        i++;
    }
    return max;

}


// 17. Defina uma função que calcula o comprimento do maior prefixo comum entre as duas strings.

int q17 (char s1[], char s2[]) {

    int i = 0; 

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
        i++;
    }

    return i;
}


// 18. Defina uma função que calcula o comprimento do maior sufixo comum entre as duas strings.

int q18 (char s1[], char s2[]){

    int i = 1;
    int size1 = strlen(s1);
    int size2 = strlen(s2);

    int size = size1 < size2 ? size1 : size2;

    while (i < size && size1 - i >= 0 && size2 - i >= 0 && s1[size1 - i] == s2[size2 - i]){
        printf("%c, %c\n",s1[size1 - i], s2[size2 - i] );
        i++;
    }

    return i - 1;            // Este - 1 é para ignorar o '\0' e é também por isso que a variável i é inicializada como 1
}


// 19. Defina a função que calcula o tamanho do maior sufixo de s1 que é um prefixo de s2.

int q19(char s1[], char s2[]){

    int i = 0;
    int ii = 0;
    int j = 0;
    int max = 0;

    while(s1[i] != '\0'){

        ii = i;
        j = 0;

        while(s1[ii] == s2[j] && s1[ii] != '\0' && s2[j] != '\0'){
            ii++;
            j++;
        }

        if (max < j) max = j;
        i++;
    }

    return max;
}


// 20. Defina uma função que conta as palavras de uma string. 

int q20 (char s[]){

    int i = 0;
    int sum = 0;

    while(s[i] != '\0'){

        if (s[i] == ' ') {
            i++;
            continue;
        }

        while(s[i] != ' ' && s[i] != '\0'){
            i++;
        }

        i++;
        sum++;
    }

    return sum;
}


// 21. Defina uma função que retorna o número de vogais da string s. Não se esqueça de considerar tanto maiúsculas como minúsculas.

int q21(char s[]){

    char vowels[10] = "aAeEiIoOuU";
    int i = 0;
    int resp = 0;

    while (s[i] != '\0'){

        if(strchr(vowels, s[i])) resp++;

        i++;

    }
    return resp;
}


// 22. Defina uma função que testa se todos os caracteres da primeira string também aparecem na segunda.

int q22(char s1[], char s2[]){

    int i = 0; 

    while (s1[i] != '\0'){

        if (strchr(s2, s1[i])) i++;
        else return 0;
    }

    return 1;
}


// 23. Defina uma função que testa se uma palavra é palíndrome, lê-se de igual forma nos dois sentidos.

int q23(char s[]){

    int size = strlen(s) - 1;

    for(int i = 0; i < size / 2; i++){

        if(s[i] != s[size - i]) return 0;

    }
    return 1;
}


// 24. Defina uma função que elimina de uma string todos os caracteres que se repetem sucessivamente deixando lá apenas uma cópia. A função deverá retornar o
//comprimento da string resultante.

int q24(char s[]){

    char curr = s[0];
    int i = 1;
    int j = 0;
    char temp[strlen(s)];

    temp[j++] = curr;

    while (s[i] != '\0'){

        if (s[i] != curr){
            curr = s[i];
            temp[j++] = curr; 
        }

        i++;
    }

    strcpy(s, temp);
    return j;
}


// 25. Defina uma funçãao que elimina repetições sucessivas de espaços por um único espaço

int q25(char s[]){

    int i = 0;
    int j = 0;
    char temp[strlen(s)];

    while (s[i] != '\0'){

        if(s[i] != ' '){
            temp[j++] = s[i];
            i++;
        } else {
            while (s[i] == ' ' && s[i] != '\0'){
                i++;
            }

            if (s[i] != '\0') temp[j++] = ' ';
        }

    }

    temp[j] = '\0';
    strcpy(s, temp);
    return j;
}


// 26. Defina uma função  que insere um elemento (x) num vector ordenado.

void q26(int v[], int N, int x){

    int temp;

    for(int i = 0; i < N; i++){

        if (x < v[i]) {
            temp = v[i];
            v[i] = x;
            x = temp;
        }
    }

    v[N] = x;

}

int main(){

    // char s1[20] = "aaba   abbba ccc";
    // char s2[20] = "atotalidade";

    const int N = 5;

    int v[5] = {1,12,27,40,51};
    
    // if(q23("giraffarig")) printf("sucesso!");
    // else printf("insucesso :(");

    q26(v, N, 15);

    for (int i = 0; i < N + 1; i++) printf("%d\n", v[i]);
    //printf("%s\n", s1 );

    //printf("%s", s1);

}