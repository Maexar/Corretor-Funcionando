#ifndef TRIE_TAD_H
#define TRIE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/

/* estrutura do noh da arvore B */
typedef struct nohTRIE NohTRIE;
typedef NohTRIE*       pNohTRIE;

/* descritor da arvore B */
typedef struct dTRIE  DTRIE;
typedef DTRIE*        pDTRIE;

/* tipos referentes aos ponteiros para funcao */
typedef int   (*FuncaoComparacaoAlfabeto)(void*, void*);
typedef void  (*FuncaoImpressao) (void*);
typedef void* (*FuncaoFatiamento) (void*, int);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDTRIE   criarArvoreTRIE(char [], int);   // alfabeto e seu tamanho

int      incluirInfoTRIE (pDTRIE, void*, int, FuncaoComparacao, FuncaoFatiamento);
int      excluirInfoTRIE (pDTRIE, void*, FuncaoComparacao);
pNohTRIE buscarInfoTRIE  (pDTRIE, void*, int, int*, int*, FuncaoComparacao, FuncaoFatiamento);

void     desenhaTRIE (pDTRIE, FuncaoImpressao);

#endif

