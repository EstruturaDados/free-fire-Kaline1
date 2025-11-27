#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char nome[30], tipo[20];
    int quantidade;
} Item;

void inserir(Item v[], int *t){
    if (*t == MAX){ printf("A mochila esta cheia\n"); return; }

    printf("Nome do item: "); fgets(v[*t].nome,30,stdin);
    v[*t].nome[strcspn(v[*t].nome,"\n")] = 0;

    printf("Tipo do item: "); fgets(v[*t].tipo,20,stdin);
    v[*t].tipo[strcspn(v[*t].tipo,"\n")] = 0;

    printf("Quantidade do item: "); scanf("%d",&v[*t].quantidade);
    getchar();

    (*t)++;
}

void listar(Item v[], int t){
    if (!t){ printf("A mochila esta vazia.\n"); return;  }
    for (int i=0;i<t;i++)
        printf("[%d] %s | %s | %d\n", i+1, v[i].nome, v[i].tipo, v[i].quantidade);
}

void remover(Item v[], int *t){
    if (!*t){ printf("Nada para remover.\n"); return; }

    char nome[30];
    printf("Nome para remover: ");
    fgets(nome,30,stdin);
    nome[strcspn(nome,"\n")] = 0;

    for (int i=0;i<*t;i++){
        if (!strcmp(v[i].nome,nome)){
            for (int j=i;j<*t-1;j++) v[j]=v[j+1];
            (*t)--; printf("Removido.\n"); return;
        }
    }
    printf("Nao encontrado.\n");
}

void buscar(Item v[], int t){
    char nome[30];
    printf("Nome para buscar: ");
    fgets(nome,30,stdin);
    nome[strcspn(nome,"\n")] = 0;

    for (int i=0;i<t;i++)
        if (!strcmp(v[i].nome,nome)){
            printf("Encontrado: %s | %s | %d\n",
                   v[i].nome, v[i].tipo, v[i].quantidade);
            return;
        }
    printf("Nao encontrado.\n");
}

int main(){
    Item moch[MAX];
    int total = 0, op;

    do {
        printf("\n1-Inserir\n2-Remover\n3-Buscar\n4-Listar\n0-Sair\nOpcao: ");
        scanf("%d",&op); getchar();

        if(op==1) inserir(moch,&total);
        else if(op==2) remover(moch,&total);
        else if(op==3) buscar(moch,total);
        else if(op==4) listar(moch,total);

    } while(op != 0);

    return 0;
}
