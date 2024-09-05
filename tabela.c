#include <stdio.h>
#include <stdlib.h>
#define TAM 31


void inicializarTabela(int t[]) {
    int i ;

    for (i = 0 ; i < TAM ; i++)
        t[i] = 0;

}

int funcaoHash(int chave) {
    return chave % TAM;
}

void inserir(int t[] ,int valor) {
    int id = funcaoHash(valor);
    while (t[id] != 0) {
        id = funcaoHash(id + 1);

    }
    t[id] = valor;
}

int buscar(int t[], int chave) {
    int id = funcaoHash(chave);
    while (t[id] != 0) {
        if (t[id] == chave)
            return id;
        else
            id = funcaoHash(id + 1);
    }
    return 0;
}

void imprimir(int t[]) {
    int i;
    for (i = 0 ; i < TAM ; i++)
        printf ("%d = %d\n " ,i, t[i]);
}

int main() {

    int opcao ,valor,retorno, tabela [TAM];
    inicializarTabela(tabela);

    do {
        printf("0 - Sair\n 1 - Inserir \n 2 - Buscar\n 3 - Imprimir : ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Qual valor deseja inserir:");
            scanf("%d", &opcao);
            inserir(tabela, opcao);
                break;
           case 2:
               printf("Qual valor deseja buscar:");
               scanf("%d", &opcao);
               retorno = buscar(tabela, opcao);
                if (retorno!= 0 )
                    printf("Valor encontrado: %d \n", retorno);
             else
                 printf("Valor nao encontrado\n");
               break;
            case 3:
                imprimir(tabela);
                break;
            default:
                printf("Opcao invalida\n");

        }
    } while (opcao != 0);


}
