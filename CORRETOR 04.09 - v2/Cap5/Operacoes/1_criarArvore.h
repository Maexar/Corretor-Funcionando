#ifndef CRIAR_ARVORE_TRIE_H
#define CRIAR_ARVORE_TRIE_H

//---------------------------------
pNohTRIE criarNohTRIE(int terminal, int ordem){

    pNohTRIE pNovo  = malloc(sizeof(NohTRIE));
    pNovo->filhos   = criarListaComTamanho(ordem);
    pNovo->terminal = terminal;
    return pNovo;
}

/* --------------------------*/
pDTRIE criarArvoreTRIE(char alfabeto[], int ordem){
    pDTRIE trie    = malloc(sizeof(DTRIE));
    trie->raiz     = criarNohTRIE(0, ordem);  // o zero indica que a raiz não é terminal
    trie->ordem    = ordem;
    trie->alfabeto = criarLista();

    // fazer um loop para adicionar cada elemento do alfabeto[] na lista do alfabeto
    // do descritor
    int i;
    for(i=0; i<ordem; i++){
       char* simbolo = malloc(sizeof(char));
       *simbolo = alfabeto[i];
       incluirInfoMeio(trie->alfabeto, simbolo, i+1);
    }

    return trie;
};

#endif
