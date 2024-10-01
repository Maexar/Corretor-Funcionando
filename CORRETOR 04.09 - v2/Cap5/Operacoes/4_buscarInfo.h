#ifndef BUSCAR_INFO_TRIE_H
#define BUSCAR_INFO_TRIE_H

/* ----------------------------------------------------------*/
pNohTRIE buscarInfoTRIERecursivo (pNohTRIE raiz, pDLista alfabeto, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    printf("\n -------> Buscando chave=%s -  k=%d - L=%d", chave, k, *L);
    if (*L < k){
       // determina a posição j do dígito da chave (d) dentro do alfabeto
       void *d = pff(chave, *L);
       int jEsimo = contemInfo(alfabeto, d, pfc);
       printf (" =====> Simbolo:%c - jEsimo:%d", *((char*)d), jEsimo);

       pNohTRIE filho = buscarInfoPos(raiz->filhos, jEsimo);
       if(filho != NULL){
          (*L)++;
          return buscarInfoTRIERecursivo(filho, alfabeto, chave, k, L, C, pfc, pff);
       }
       return raiz;
    }
    else{
        if (raiz->terminal == 1){
            *C = 1;       // indica que a chave foi localizada na árvore
            return raiz;
        }
    }
}

/* ----------------------------------------------------------*/
pNohTRIE buscarInfoTRIE (pDTRIE arvore, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    *L = 0;
    *C = 0;
    return buscarInfoTRIERecursivo(arvore->raiz, arvore->alfabeto, chave, k, L, C, pfc, pff);
}

#endif

