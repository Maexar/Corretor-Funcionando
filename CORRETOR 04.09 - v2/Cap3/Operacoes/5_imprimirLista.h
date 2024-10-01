#ifndef IMPRIMIR_LISTA_H
#define IMPRIMIR_LISTA_H

void imprimirLista(pDLista pd, FuncaoImpressao pfi)
{
    pNoh aux;
    aux = pd->primeiro;
    int i=0;
    while(aux != NULL)
    {
        // printf("%d", *(((int *)aux->info)));;
        if(aux->info != NULL){
            pfi(aux->info);
        }
        i++;
        aux = aux->prox;
    }
}

#endif
