#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* operational(char* s){
    const char* RULEX="-YF+XFX+FY-";
    const char* RULEY="+XF-YFY-FX+";
    const int RULE_SIZE=11;
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


char* control(char* s, int n){
    if(n==1){
        substituir(s);
        return s;
    }
    return control(operational(s), n-1);
};

int main(){

    FILE* f = fopen("hilbert.txt", "w");

    char axiom[2];
    int angle;
    char rulex[12];
    char ruley[12];

    printf("Digite o axiom de espaço de Hilbert: ");
    scanf("%s", axiom);

    printf("Digite o angle de espaço de Hilbert: ");
    scanf("%d", &angle);

    printf("Digite a rule X de espaço de Hilbert: ");
    scanf("%s", rulex);

    printf("Digite a rule Y de espaço de Hilbert: ");
    scanf("%s", ruley);

    fprintf(f, "axiom: %s\nangle: %d\nrule X: %s\nrule Y: %s\n", axiom, angle, rulex, ruley);
    fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    for (int i = 1; i <= 4; i++)
    {
        fprintf(f, "Estágio %d: %s\n", i, control("X", i+1));
        fprintf(f, "---------------------------------------------------------------------------------------------------------\n");

    }
    
}