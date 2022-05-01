#include <stdio.h> 
#include <string.h>

int topo = 0;

int main(void) {
  char mat[50];
  int i=0;
  int j=0;
  int vagas = 0;
  char placa [8];
  char matricula [50];
  char servidor [50] [50];
  for(i=0;i<50;i++){
    strcpy(servidor[i],"0");
  }
  
  int opt;
  printf("quantas vagas estao disponiveis= \n");
  scanf("%d",&vagas);
  
  do{
    printf("1- inserir servidor:\n");
    printf("2- inserir carro:\n");
    printf("3- listar servidores:\n");
    printf("4- listar vagas livres:\n");
    printf("0- sair do programa:\n");
    printf("digite sua opcao: \n");
    scanf("%d", &opt);
    switch(opt){
      case 1: 
        printf("digite a matricula do servidor: \n");
        scanf("%s", &matricula);
        strcpy(servidor[topo],matricula);
        strcat(servidor[topo],"$");
        topo ++;
        break;
      case 2:
        printf("digite a matricula do servidor: \n");
        scanf("%s", &matricula);
        i=0;
        while(i<50){
          strcpy(mat,strtok(servidor[i],"$"));
          //printf("%s %s \n",mat,matricula);
          if(strcmp (matricula,mat)==0){
            printf("digite a placa do carro: \n");
            scanf("%s", &placa);
            strcat(servidor[i],"$");
            strcat(servidor[i],placa);
            vagas --;
          }
          i++;
        }
        break;
      case 3:
        i = 0;
        while(i<50){
          printf("matricula: %s \n",servidor[i]);
          /*while(token!=NULL){
            token=strtok(NULL,"$");
            printf("carro: %s \n",token);
          }*/
          
          i++; 
        }
        break;
      case 4:
      printf("%d \n", vagas);
        break;
    }
  } while(opt != 0);
  return 0;
}