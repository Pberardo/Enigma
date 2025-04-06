#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  // Para getch()
#include <ctype.h>  // necessário para toupper()

#define MENSAGEM_LENGTH 20

/*
void criar_rotor(char inicio, char rotor[26]) {
    int offset = inicio - 'A';  // posição da letra inicial
    for (int i = 0; i < 26; i++) {
        rotor[i] = 'A' + (offset + i) % 26;  // rotação com wrap-around
    }
}*/

void criar_rotor1(char inicio, char rotor1[26]) {
    // Lista embaralhada fixa
    char base_rotor1[26] = {
        'M', 'W', 'Z', 'L', 'B', 'U', 'K',
        'E', 'T', 'S', 'C', 'O', 'Y', 'A',
        'R', 'N', 'H', 'D', 'V', 'P', 'X',
        'Q', 'F', 'I', 'J', 'G'
    };

    int start_index = -1;

    // Procurar a letra na base
    for (int i = 0; i < 26; i++) {
        if (base_rotor1[i] == inicio) {
            start_index = i;
            break;
        }
    }

    if (start_index == -1) {
        printf("Letra inválida para o rotor 1!\n");
        exit(1);
    }

    // Criar rotor3 com base rotacionada
    for (int i = 0; i < 26; i++) {
        rotor1[i] = base_rotor1[(start_index + i) % 26];
    }
}

void criar_rotor2(char inicio, char rotor2[26]) {
    // Lista embaralhada fixa
    char base_rotor2[26] = {
        'F', 'R', 'O', 'T', 'W', 'B', 'M',
        'Y', 'Q', 'L', 'C', 'X', 'E', 'H',
        'J', 'K', 'N', 'A', 'Z', 'I', 'P',
        'V', 'U', 'G', 'S', 'D'
    };

    int start_index = -1;

    // Procurar a letra na base
    for (int i = 0; i < 26; i++) {
        if (base_rotor2[i] == inicio) {
            start_index = i;
            break;
        }
    }

    if (start_index == -1) {
        printf("Letra inválida para o rotor 2!\n");
        exit(1);
    }

    // Criar rotor3 com base rotacionada
    for (int i = 0; i < 26; i++) {
        rotor2[i] = base_rotor2[(start_index + i) % 26];
    }
}

void criar_rotor3(char inicio, char rotor3[26]) {
    // Lista embaralhada fixa
    char base_rotor3[26] = {
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U',
        'I', 'O', 'P', 'A', 'S', 'D', 'F',
        'G', 'H', 'J', 'K', 'L', 'Z', 'X',
        'C', 'V', 'B', 'N', 'M'
    };

    int start_index = -1;

    // Procurar a letra na base
    for (int i = 0; i < 26; i++) {
        if (base_rotor3[i] == inicio) {
            start_index = i;
            break;
        }
    }

    if (start_index == -1) {
        printf("Letra inválida para o rotor 3!\n");
        exit(1);
    }

    // Criar rotor3 com base rotacionada
    for (int i = 0; i < 26; i++) {
        rotor3[i] = base_rotor3[(start_index + i) % 26];
    }
}




void imprimir_rotor(char rotor[26]) {
    for (int i = 0; i < 26; i++) {
        printf("%c ", rotor[i]);
    }
    printf("\n");
}

char buscar_letra(char entrada, char rotor1[26], char rotor2[26], char rotor3[26]){
    int pos,i;
    char letra2, letra3;
    for(int i=0; i<26; i++){
        if (rotor1[i] == entrada){
            pos = i;
            break;
        }
    }
    
    letra2 = rotor2[pos];
    for(i = 0; i<26; i++){
        if (rotor2[i] == letra2){
            pos = i;
            break;
        }
    }
    letra3=rotor3[pos];
    return letra3;
} 

int main(){
    
    char letra1, letra2, letra3, entrada;
    char rotor1[26] = {
        'M', 'W', 'Z', 'L', 'B', 'U', 'K',
        'E', 'T', 'S', 'C', 'O', 'Y', 'A',
        'R', 'N', 'H', 'D', 'V', 'P', 'X',
        'Q', 'F', 'I', 'J', 'G'
    };

    char rotor2[26] = {
        'F', 'R', 'O', 'T', 'W', 'B', 'M',
        'Y', 'Q', 'L', 'C', 'X', 'E', 'H',
        'J', 'K', 'N', 'A', 'Z', 'I', 'P',
        'V', 'U', 'G', 'S', 'D'
    };

    char rotor3[26] = {
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U',
        'I', 'O', 'P', 'A', 'S', 'D', 'F',
        'G', 'H', 'J', 'K', 'L', 'Z', 'X',
        'C', 'V', 'B', 'N', 'M'
    };    

    printf("Digite a primeira letra da chave (A-Z): ");
    scanf(" %c", &letra1);  // espaço antes do %c ignora espaços em branco

    letra1 = toupper(letra1);
    criar_rotor1(letra1, rotor1);

    printf("Digite a segunda letra da chave (A-Z): ");
    scanf(" %c", &letra2);  // espaço antes do %c ignora espaços em branco

    letra2 = toupper(letra2);
    criar_rotor2(letra2, rotor2);

    printf("Digite a terceira letra da (A-Z): ");
    scanf(" %c", &letra3);  // espaço antes do %c ignora espaços em branco

    letra3 = toupper(letra3);
    criar_rotor3(letra3, rotor3);


    printf("Rotor 1 criado:\n");
    imprimir_rotor(rotor1);

    printf("Rotor 2 criado:\n");
    imprimir_rotor(rotor2);

    printf("Rotor 3 criado:\n");
    imprimir_rotor(rotor3);
    
    printf("Digite uma letra: ");
    scanf(" %c", &entrada);
    entrada = toupper(entrada);

    printf("letra digitada -> %c\nletra cifrada-> %c", entrada, buscar_letra(entrada, rotor1, rotor2, rotor3));


    return 0;
}