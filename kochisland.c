#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* operacional(char* s){
    const char* RULE="F+F-F-FFF+F+F-F";
    const int RULE_SIZE=15;
    char* aux= (char*) malloc(sizeof(char)*0);
    int tam= 0;

    for(char* it=s; *it!='\0'; it++){ 
        if(*it=='F'){
            for(int i = 0; i<RULE_SIZE; i++){
                tam++;
                aux=(char*) realloc(aux, sizeof(char)*tam);
                aux[tam-1]= RULE[i];
            }
        }
        else{
            tam++;
            aux=(char*) realloc(aux, sizeof(char)*tam);
            aux[tam-1]=*it;
        }
    }
    return aux;
};

char* controle(char* s, int n){
    if(n==1)
        return s;
    
    return controle(operacional(s), n-1);
};

int main(){

    FILE* f = fopen("kochisland.txt", "w");

    char axioma[8];
    int angulo;
    char regra[16];

    printf("Digite o axioma da Ilha de Koch: ");
    scanf("%s", axioma);

    printf("Digite o angulo da Ilha de Koch: ");
    scanf("%d", &angulo);

    printf("Digite a regra da Ilha de Koch: ");
    scanf("%s", regra);

    fprintf(f, "Axioma: %s\nAngulo: %d\nRegra: %s\n", axioma, angulo, regra);
    fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    for (int i = 1; i <= 4; i++)
    {
        fprintf(f, "Estágio %d: %s\n", i, controle("F+F+F+F", i+1));
        fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    }
    
}