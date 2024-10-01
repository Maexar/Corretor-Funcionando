#ifndef DESENHA_TRIE_H
#define DESENHA_TRIE_H

#define ESPACO 5

void desenhaTRIERecursivo(pNohTRIE raiz, pDLista alfabeto, FuncaoImpressao fi) {

   if (raiz == NULL){
       printf(" * - ");
       return;
   }

   if (raiz->filhos == NULL ||
       raiz->filhos->quantidade == 0){
     printf("[ * ]");
     return;
   }

   int i;
   printf("[ ");
 //  printf("\n ############################# -> %d", raiz->filhos->quantidade);
   for (i=0; i < raiz->filhos->quantidade; i++){
      void* iEsimoFilho = buscarInfoPos(raiz->filhos, i+1);
      if (iEsimoFilho != NULL)
          fi(buscarInfoPos(alfabeto, i+1));

      desenhaTRIERecursivo(iEsimoFilho, alfabeto, fi);
   }

   printf(" ]");
}

void desenhaTRIE(pDTRIE arvore, FuncaoImpressao fi) {

    desenhaTRIERecursivo(arvore->raiz, arvore->alfabeto, fi);

}

#endif
