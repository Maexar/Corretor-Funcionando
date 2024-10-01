#ifndef EXCLUIR_ULTIMO
#define EXCLUIR_ULTIMO

void * excluiUtimmo(pDLista pd){
    pNoh atua, anterior, proximo;
    atua = pd->primeiro;
    proximo = atua->prox;

    while(proximo != NULL){
        anterior = atua;
        atua     = proximo;
        proximo  = proximo->prox;
    }

    anterior->prox = NULL;
    pd->ultimo     = anterior;
    pd->quantidade--;
}

#endif // 3_3_EXCLUIRUTIMO_H_INCLUDED
