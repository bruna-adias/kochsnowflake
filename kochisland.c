#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* operational(char* s){
    const char* RULE="F+F-F-FFF+F+F-F";
    const int RULE_SIZE=15;
    char* aux= (char*) malloc(sizeof(char)*0);
    int size= 0;

    for(char* it=s; *it!='\0'; it++){ 
        if(*it=='F'){
            for(int i = 0; i<RULE_SIZE; i++){
                size++;
                aux=(char*) realloc(aux, sizeof(char)*size);
                aux[size-1]= RULE[i];
            }
        }
        else{
            size++;
            aux=(char*) realloc(aux, sizeof(char)*size);
            aux[size-1]=*it;
        }
    }
    aux[size] = '\0';
    return aux;
};

char* control(char* s, int n){
    if(n==1)
        return s;
    
    return control(operational(s), n-1);
};

int main(){

    FILE* f = fopen("kochisland.txt", "w");

    char axiom[8];
    int angle;
    char rule[16];

    printf("Digite o axioma da Ilha de Koch: ");
    scanf("%s", axiom);

    printf("Digite o angulo da Ilha de Koch: ");
    scanf("%d", &angle);

    printf("Digite a regra da Ilha de Koch: ");
    scanf("%s", rule);

    fprintf(f, "Ilha de Koch \nAxioma: %s\nÂngulo: %d\nRegra: %s\n", axiom, angle, rule);
    fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    for (int i = 1; i <= 4; i++)
    {
        fprintf(f, "Estágio %d: %s\n", i, control("F+F+F+F", i+1));
        fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    }
    
}