#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* operacional(char* s){
    const char* RULEX="YF-FXY+XFY-+FX";
    const char* RULEY="F+XY+FYX+FX-YF";
    const int RULE_SIZE=14;
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

    FILE* f = fopen("bruna.txt", "w");

    char axiom[2]="Y";
    int angle=60;
    char rulex[15]="YF-FXY+XFY-+FX";
    char ruley[15]="F+XY+FYX+FX-YF";

    fprintf(f, "Axioma: %s\nAngulo: %d\nRegra X: %s\nRegra Y: %s\n", axiom, angle, rulex, ruley);
    fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    for (int i = 1; i <= 4; i++)
    {
        fprintf(f, "Estágio %d: %s\n", i, controle("Y", i+1));
        fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    }
    
}