/* #include "heur.h"

int main(int argc, char const *argv[])
{
    printf("Criando o Grafo");
    int servers = 0;
    int connect = 0;
    int id1 = 0, id2 = 0, i = 0;
    int result = 0;
    scanf("%d%d", &servers, &connect);

    graphL_pont grafo = createGraphL(servers);
    //printf("%d:%d\n",servers,connect);
    printf("Conectando o grafo");
    for (i=0;i<connect;i++){
        scanf("%d%d", &id1-1, &id2-1);
        addAresta(grafo,id1-1,id2-1);
    }

    //testRounds = createEmptyRounds(2);
    result = findRounds(grafo, servers);
    printf("%d\n",result);
    return 0;
}
 */
#include "grafo2.h"
#include "heur.h"

void visitingPerson(rodada_pont lista, graphL_pont grafo, int id, int* contador){ // função que percorre o grafo
    printf("%d:",id);
    int auxcont = 0;
    if (lista[id].visitado == 0){
        Visited(lista,id);
        if(lista[id].n_rodada == 0){ // caso a pessoa seja menor de 35 anos, ela recomenda a musica
            lista[id].n_rodada = 1;
        }
        printf("%d\n",lista[id].n_rodada);
        listadj_noh_pont auxnoh = grafo->arrayList[id].header; // aponta para o cabeçaria da lista de relações da pessoa referenciada
        while(auxnoh){
            //printf("%d:",lista[auxnoh->vertice].n_rodada);
            if (lista[auxnoh->vertice].n_rodada == 0){
                lista[auxnoh->vertice].n_rodada = lista[id].n_rodada+1;
                //printf("deu");
            }
            else if(lista[auxnoh->vertice].n_rodada == lista[id].n_rodada){
                if (*contador == lista[auxnoh->vertice].n_rodada){
                    *contador+=1;
                    //printf("igual");
                }
                lista[auxnoh->vertice].n_rodada++;
            }
            //printf(":%d\n",lista[auxnoh->vertice].n_rodada);
        //    visitingPerson(lista,grafo,auxnoh->vertice,contador);
            auxnoh = auxnoh->prox;
        }
        //if();
        //printf("\n%d", *contador);
    }
}

int main (){
    int rounds = 1;
    int i = 0;
    int id1 = 0, id2 = 0;
    int server = 0, connect = 0;
    scanf("%d%d",&server,&connect);

    rodada_pont list = createEmptyRounds(server);
    graphL_pont grafo = createGraphL(server);
    
    for(i = 0; i<server; i++){
        createRound(list, i);
    }

    //printList(list, pessoa);

    for(i = 0; i<connect; i++){
        scanf("%d%d",&id1,&id2);
        addAresta(grafo, id1-1, id2-1);
    }

    //printGraphL(grafo);
    //printRounds(list,server);
    visitingPerson(list,grafo/*, grafo->arrayList[id] */,1,&rounds);

    //printf("%d\n",rounds);
    //printList(list, pessoa);
    
    destroyRounds(list);
    destroyGraphL(grafo);
    return 0;
}