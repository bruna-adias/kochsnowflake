#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* operational(char* s){
    const char* RULEX="XY-F+XY+F";
    const char* RULEY="YX+F-YX-F";
    int RULE_SIZE=9;
    char* aux= (char*) malloc(sizeof(char)*0);
    int size= 0;

    for(char* it=s; *it!='\0'; it++){ 
        if(*it=='X'){
            for(int i = 0; i<RULE_SIZE; i++){
                size++;
                aux=(char*) realloc(aux, sizeof(char)*size);
                aux[size-1]= RULEX[i];
            }
        }
        else if(*it=='Y'){
            for(int i = 0; i<RULE_SIZE; i++){
                size++;
                aux=(char*) realloc(aux, sizeof(char)*size);
                aux[size-1]= RULEY[i];
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

void discard(char* s){
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


char* control(char* s, int n){
    if(n==1){
        discard(s);
        return s;
    }
    return control(operational(s), n-1);
};

int main(){

    FILE* f = fopen("bruna.txt", "w");

    char axiom[18]="FX+FY+FX+FY+FX+FY";
    int angle=60;
    char ruley[10]="XY-F+XY+F";
    char rulex[10]="YX+F-YX-F";

    fprintf(f, "Curva de Bruna \nAxioma: %s\nÂngulo: %d\nRegra X: %s\nRegra Y: %s\n", axiom, angle, rulex, ruley);
    fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    for (int i = 1; i <= 4; i++)
    {
        fprintf(f, "Estágio %d: %s\n", i, control("FX+FY+FX+FY+FX+FY\0", i+1));
        fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    }
    
}
