#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Utils.h"
#include "TRIE.h"


int main()
{
    int respMenu;
    char palavra[46];
    char alfabeto[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    pDTRIE trie = criarArvoreTRIE(alfabeto, 26);
    FILE *file;

    file = fopen("dicionario.txt", "a+");
    char linha[sizeof(palavra)];
    while(fgets(linha,sizeof(linha),file)!=NULL){
        printf("%s",linha);
        incluirInfoTRIE(trie, linha, (strlen(linha)-1), comparaChar, fatiaString);
    }
    fclose(file);

    do
    {
        printf("\n1 - cadastrar palavra no dicionario\n");
        printf("2 - ver dicionario\n");
        printf("3 - escrever\n");
        printf("4 - imprimir arvore\n");
        scanf("%d", &respMenu);
        switch(respMenu)
        {
        case 1:
            file = fopen("dicionario.txt", "a+");
            printf("palavra: ");
            scanf("%s", palavra);
            fprintf(file,"%s\n",palavra);
            incluirInfoTRIE(trie, palavra, strlen(palavra), comparaChar, fatiaString);
            fclose(file);
            break;

        case 2:
            file = fopen("dicionario.txt", "r");
            while(fgets(linha,sizeof(linha),file)!=NULL){
                printf("%s",linha);
            }
            fclose(file);
            break;

        case 3:
            printf("digite uma palavra: ");
            scanf("%s", palavra);
            verifica(trie, palavra, fatiaString, comparaChar);
            break;

        case 4:
            printf("\n\n --- Arvore final --- \n\n");
            desenhaTRIE(trie, imprimeChar);
            break;
        case 5:
            buscarInfoTRIE(trie, "papel", 5, 0, 0, comparaChar, fatiaString);

            break;
        }
    }while(respMenu != 0);
    /*char alfabeto[]={'a', 'b', 'c', 'i'};

    // define a ordem da árvore B
    pDTRIE trie = criarArvoreTRIE(alfabeto, 4);

    char chave1[] = "bacia";
    char chave2[] = "abicia";
    char chave3[] = "ciba";
    char chave4[] = "baba";

    teste de inclusao
    incluirInfoTRIE(trie, chave1, strlen(chave1), comparaChar, fatiaString);
    incluirInfoTRIE(trie, chave2, strlen(chave2), comparaChar, fatiaString);
    incluirInfoTRIE(trie, chave3, strlen(chave3), comparaChar, fatiaString);
    incluirInfoTRIE(trie, chave4, strlen(chave4), comparaChar, fatiaString);

    printf("\n\n --- Arvore final --- \n\n");
    desenhaTRIE(trie, imprimeChar);*/
}
