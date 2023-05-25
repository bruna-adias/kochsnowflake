#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* operacional(char* s){
    const char* RULEX="-YF+XFX+FY-";
    const char* RULEY="+XF-YFY-FX+";
    const int RULE_SIZE=11;
    char* aux= (char*) malloc(sizeof(char)*0);
    int tam= 0;

    for(char* it=s; *it!='\0'; it++){ 
        if(*it=='X'){
            for(int i = 0; i<RULE_SIZE; i++){
                tam++;
                aux=(char*) realloc(aux, sizeof(char)*tam);
                aux[tam-1]= RULEX[i];
            }
        }
        else if(*it=='Y'){
            for(int i = 0; i<RULE_SIZE; i++){
                tam++;
                aux=(char*) realloc(aux, sizeof(char)*tam);
                aux[tam-1]= RULEY[i];
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

void substituir(char* s){
    for(int i=0; s[i]!='\0'; i++){ 
        if(s[i]=='X' || s[i]=='Y'){
            
            int j;
            for (j=i; s[j+1]!='\0'; j++)
            {
                s[j]=s[j+1];
            }
            s[j]='\0';
            i--;
        }


    }
}


char* controle(char* s, int n){
    if(n==1){
        substituir(s);
        return s;
    }
    return controle(operacional(s), n-1);
};

int main(){

    FILE* f = fopen("hilbert.txt", "w");

    char axiom[2];
    int angle;
    char rulex[12];
    char ruley[12];

    printf("Digite o axioma de espaço de Hilbert: ");
    scanf("%s", axiom);

    printf("Digite o angulo de espaço de Hilbert: ");
    scanf("%d", &angle);

    printf("Digite a regra X de espaço de Hilbert: ");
    scanf("%s", rulex);

    printf("Digite a regra Y de espaço de Hilbert: ");
    scanf("%s", ruley);

    fprintf(f, "Axioma: %s\nAngulo: %d\nRegra X: %s\nRegra Y: %s\n", axiom, angle, rulex, ruley);
    fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    for (int i = 1; i <= 4; i++)
    {
        fprintf(f, "Estágio %d: %s\n", i, controle("X", i+1));
        fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    }
    
}