#ifndef VERIFICAR_H
#define VERIFICAR_H
/*------------------------------------------------------------------------*/
//fução para se caso queira imprimir a lista com as palavras
void imprimirCandidatos(pDLista lista){
    printf("******");
    pNoh o = lista->primeiro;
    pDLista j = o->info;
    for(int i=0; i<lista->quantidade; i++){
        imprimirLista(j,imprimeChar);
        printf("||");
        if(o->prox != NULL){
            o = o->prox;
            j = o->info;
        }

    }
}
/*------------------------------------------------------------------------*/
int copia(pDLista lista2, pNoh info){
    int possi = contemInfo(lista2, info, comparaChar);
    printf("{%d}",possi);
    if(possi == NULL)
        return 0;
    pNoh aux = lista2->primeiro;

    for(int i=0; i<lista2->quantidade; i++){
            imprimeChar(aux->info);
        if(i+2 == possi){
            if(i+1 == 1){
                lista2->primeiro = NULL;
                lista2->ultimo = NULL;
                lista2->quantidade = 0;
                return 1;
            }else{
                aux->prox = NULL;
                lista2->ultimo = aux;
                int j=0;
                pNoh cont = lista2->primeiro;
                while(cont != NULL){
                    j++;
                    cont = cont->prox;
                }
                lista2->quantidade = j;
                printf("{");
                imprimirLista(lista2, imprimeChar);
                printf("}");
                return 1;
            }

        }
    aux = aux->prox;
    }

}
/*------------------------------------------------------------------------*/
int semIdeia(pDLista lista, void* num){
    int i=1;
    pNoh aux = lista->primeiro;
    for(i; i<lista->quantidade; i++){
        if(comparaInt(aux->info, num)==0){
            return i;
        }
        aux = aux->prox;
    }
    return 0;
}
/*------------------------------------------------------------------------*/
pDLista cabesalho(pNohTRIE raiz, pDLista alfabeto, FuncaoComparacaoAlfabeto pff, pDLista lista){
    pNoh aux = raiz->filhos->primeiro;
    int i=0;
    for(i=0; i<alfabeto->quantidade; i++){
        if(aux->info != NULL){
            pNoh filho = buscarInfoPos(alfabeto, i+1);
            pDLista listav2 = criarLista();
            incluirInfo(lista, listav2);
            incluirInfo(listav2, filho);
            palavra(aux->info, alfabeto, pff, listav2, lista);
        }
        aux = aux->prox;
    }
    //excluirInfoPos(lista, i);
    imprimirCandidatos(lista);

    return lista;
}
/*------------------------------------------------------------------------*/
void palavra(pNohTRIE raiz, pDLista alfabeto, FuncaoComparacaoAlfabeto pff, pDLista list2, pDLista lista){
    if (raiz->terminal) {
        // Palavra completa encontrada, portanto, finalize a lista.
        return;
    }

    pNoh aux = raiz->filhos->primeiro;
    int i;
    int contIrmao = 0;
    pNoh infoAnterior;

    for(i=0; i<alfabeto->quantidade; i++){
        if(aux->info != NULL){
            contIrmao++;
            if(contIrmao > 1){
                pDLista temporaria = criarLista();
                temporaria = duplicarLista(list2, alocaInfoChar);
                copia(temporaria, infoAnterior);
                incluirInfo(lista, temporaria);
                pNoh filho = buscarInfoPos(alfabeto, i+1);
                incluirInfo(temporaria, filho);
                palavra(aux->info, alfabeto, pff, temporaria, lista);
                return;
            }
            pNoh filho = buscarInfoPos(alfabeto, i+1);
            infoAnterior = filho;
            incluirInfo(list2, filho);
            palavra(aux->info, alfabeto, pff, list2, lista);
        }
        aux = aux->prox;
    }
}
/*------------------------------------------------------------------------*/
int Mega(pDLista pd){
    pNoh aux = pd->primeiro;
    int maior = aux->info;
    while(aux != NULL){
        if(comparaInt(maior, aux->info)>0){
            maior = aux->info;
        }
        aux = aux->prox;
    }
    return maior;
}
/*------------------------------------------------------------------------*/
void possiMaior(pDLista numeros, pDLista maiores, int valor){
    pNoh aux = numeros->primeiro;
    for(int i=0; i<numeros->quantidade; i++){
        if(aux->info == valor){
            incluirInfo(maiores, i+1);
        }
        aux = aux->prox;
    }
}
/*------------------------------------------------------------------------*/
void printParecido(pDLista palavras, pDLista possisoes){
    pNoh aux = possisoes->primeiro;
    pNoh o = palavras->primeiro;
    pDLista palavra = o->info;
    int quantidade;

    for(int i=1; i<=palavras->quantidade; i++){
        if(i == aux->info){
            printf("\nvc quis dizer: ");
            imprimirLista(palavra, imprimeChar);
            printf("||");

            quantidade = possisoes->quantidade;
            quantidade--;
            possisoes->quantidade = quantidade;

            if(possisoes->quantidade != 0){
                printf(" ou ");
            }
            if(possisoes->quantidade == 0)
                return;
            aux = aux->prox;
        }
        o       = o->prox;
        palavra = o->info;
    }
    printf("sau");
}
/*------------------------------------------------------------------------*/
void * comparativo(pDLista palavras, void* chave, pDLista alfabeto, FuncaoFatiamento pff)
{
    pNoh o = palavras->primeiro;
    pNoh lata;
    pDLista preCanditato     = criarLista();
    pDLista numChave         = criarLista();
    pDLista acertoCandidatos = criarLista();
    preCanditato = o->info;
    int contMaior=0;


    //int quantidadeLetrasChave = strlen(chave);

    //transformara a chave em uma lista com os numeros no alfabeto
    for(int i=0; i<strlen(chave); i++){
        void *d = pff(chave, i);
        int jEsimo = contemInfo(alfabeto, d, comparaChar);
        incluirInfo(numChave, jEsimo);
    }

    //compara e contabiliza os candidatos
    while(o != NULL){
        preCanditato = o->info;
        pDLista numeros = criarLista();
        lata = preCanditato->primeiro;
        for(int j=0; j<preCanditato->quantidade; j++){
            int num = contemInfo(alfabeto, lata->info, comparaChar);
            incluirInfo(numeros, num);
            lata = lata->prox;
        }

        //fazer pontuação
        pNoh aux = numChave->primeiro;
        for(int j=0; j<strlen(chave); j++){
            int p = semIdeia(numeros, aux->info);
            if(p!=0){
                contMaior++;
                excluirInfo(numeros, aux->info, comparaInt);
            }
            aux = aux->prox;
        }
        incluirInfo(acertoCandidatos, contMaior+1);

        //preparando para o proximo ciclo
        destruirLista(numeros);
        contMaior=0;
        o = o->prox;;
    }
    imprimirLista(acertoCandidatos,imprimeInt);

    //achar a palavra com maior quantidade de acertos
    int maior = Mega(acertoCandidatos);
    if(maior == NULL){
        printf("nada");
        return;
    }

    //achar possisao do maior e adicionar a uma lista, caso aja mais de 1 com o mesmo valor
    pDLista possi = criarLista();
    possiMaior(acertoCandidatos, possi, maior);

    //fazer uma lista com as palavras da preCanditato que estao nas possisoes encontradas
    printParecido(palavras, possi);

    return;
}
/*------------------------------------------------------------------------*/
int verifica(pDTRIE arvore, void*chave, FuncaoFatiamento pff, FuncaoComparacao pfc)
{
    pDLista lista = criarLista();
    lista = cabesalho(arvore->raiz, arvore->alfabeto, pff, lista);
    comparativo(lista, chave, arvore->alfabeto, pff);
    return;
    //pDLista palavras = listarTodasPalavras(arvore->raiz, pff, pfc);
    //imprimirLista(palavras, imprimeChar);
}

#endif // VERIFICAR_H
