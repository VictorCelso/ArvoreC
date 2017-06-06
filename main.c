#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct pilha
{
    int topo;
    int item[MAX];
} PILHA;


void inicia(PILHA *p)
{
    p->topo = -1;
}


int vazia (PILHA *p)
{
    if (p->topo == -1)
        return 1; // 1: pilha vazia
    else
        return 0; // 0: pilha não vazia
}

int cheia (PILHA *p)
{
    if (p->topo == (MAX - 1))
        return 1; // 1: pilha cheia
    else
        return 0; // 0: pilha não cheia
}

void empilha(int item, PILHA *p)
{
    if (cheia(p))
    {
        printf("PILHA cheia! [%c]\n", item);
        return;
    }

    p->topo++;
    p->item[p->topo] = item;
}


int desempilha(PILHA *p)
{
    if (vazia(p))
    {
        printf("PILHA vazia!\n");
        return 0;
    }

    p->topo--;
    return p->item[p->topo+1];
}


int posfix(char A[50]){

    PILHA *p;
        p = new PILHA;

    inicia(p);

    int i = 0, a, numero = 0;
    int vlr1, vlr2;
    char valor[2];

    char operacoes[4];
    operacoes[0] = '*';
    operacoes[1] = '/';
    operacoes[2] = '+';
    operacoes[3] = '-';
    while(A[i]!='\n'){

        if (A[i] ==' ') { i++;
             }    else    {
        if((A[i]==operacoes[0]) || (A[i]==operacoes[1]) ||
                     (A[i]==operacoes[2]) || (A[i]==operacoes[3])){
            switch(A[i]) {
              case '*':
                  numero = desempilha(p) * desempilha(p);
                  break;
              case'/':
                  vlr2 = desempilha(p);
                  vlr1 = desempilha(p);
                  numero = vlr1 / vlr2;
                  break;
              case '+':
                  numero = desempilha(p) + desempilha(p);
                  break;
              case '-':
                  vlr2 = desempilha(p);
                  vlr1 = desempilha(p);
                  numero = vlr1 - vlr2;
                  break;
              default:
                  printf("Digite uma notacao polonesa valida !");
                  exit(1);
                  break;
             }

                         empilha(numero, p);
             i++;
        } else {
            if(A[i+1]==' '){
                valor[0] = A[i];
                valor[1] = '\n';
                empilha(atoi(valor), p);
                i=i+2;
            }else{
                char b[10];
                int c = 0;
                a = i;
                while(A[a]!=' '){
                    b[c] = A[a];
                    c++;
                    a++;
                }
                b[c] = '\0';
                empilha(atoi(b),p);
                i = ++a;
            }
                 }
        }
    }
    return(numero);

}

int main(){

    char expressao[50];
    int A;

    printf("Digite a expressao pos-fix: ");
    fgets(expressao,49,stdin);


    A = posfix(expressao);
    printf("Operacao = %d \n", A);
    system("pause");


}
