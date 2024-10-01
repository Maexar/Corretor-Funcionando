#ifndef INCLUIR_INFO_TRIE_H
#define INCLUIR_INFO_TRIE_H

/* --------------------------*/
pNohTRIE incluirInfoTRIERecursivo(pNohTRIE raiz,
                                   pDLista alfabeto,
                                   void*   chave,
                                   int     k,
                                   int     ordem,
                                   int*    L,
                                   FuncaoComparacao pfc,
                                   FuncaoFatiamento pff)
{

    printf("\n --> Chave=%s -  k=%d - L=%d", chave, k, *L);
    if (*L >= k)
       return raiz;

   // a raiz aponta para o n� que deve receber os pr�ximos k - L s�mbolos da chave
   pNohTRIE novo;
   if (*L == k){
      novo = criarNohTRIE(1, ordem); // novo n� � terminal
   }
   else{
     novo = criarNohTRIE(0, ordem); // novo n� � terminal
   }

   // determina a posi��o j do d�gito da chave (d) dentro do alfabeto
   void* d      = pff(chave, *L);
   int   jEsimo = contemInfo(alfabeto, d, pfc);
   printf("\n    --> Simbolo=%c - jEsimo=%d", *((char*)d), jEsimo);

   // coloca o novo filho no lugar do anterior (que era NULL)
   excluirInfoPos(raiz->filhos, jEsimo);
   incluirInfoMeio(raiz->filhos, novo, jEsimo);

   // prepara chamada recursiva
   (*L)++;
   pNohTRIE novoFilho = incluirInfoTRIERecursivo(novo, alfabeto, chave, k, ordem, L, pfc, pff);
}

/* ----------------------------------------------------------*/
int incluirInfoTRIE (pDTRIE arvore, void* chave, int k, FuncaoComparacaoAlfabeto pfc, FuncaoFatiamento pff){

     int L=0, C=0;

     //printf("\n Incluindo chave %s", chave);
     pNohTRIE noh = buscarInfoTRIE(arvore, chave, k, &L, &C, pfc, pff);

     printf("\n Ap�s a busca da chave %s: L=%d - C=%d", chave, L, C);
     if (C == 1){
        // a chave j� est� na �rvore
        return 0;
     }

     // ap�s a busca, a vari�vel L representa o �ltimo d�gito analisado da chave (prefixo)
     incluirInfoTRIERecursivo(noh, arvore->alfabeto, chave, k, arvore->ordem, &L, pfc, pff);
     return 1;
}

#endif

