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
  
  // esse for usei pra limpar o vetor, pq tava vindo com sujeira, usei esse metodo pra zerar todo o vetor
  
  for(i=0;i<50;i++){
    strcpy(servidor[i],"0"); 
  }
  
  int opt;
  printf("quantas vagas estao disponiveis= \n");
  scanf("%d",&vagas);
  
  // a definiçao de vagas do estacionamento, é feita nesse scanf, a lista de vagas livres vai ficar por conta do valor que eu colocar aqui, sendo decrementado toda vez que um carro for colocado
  
  do{
    printf("1- inserir servidor:\n");
    printf("2- inserir carro:\n");
    printf("3- listar servidores:\n");
    printf("4- listar vagas livres:\n");
    printf("0- sair do programa:\n");
    printf("digite sua opcao: \n");
    scanf("%d", &opt);
    
    //menu inicial que vai ficar no loop, utilizei a variavel opt pra ser os valores para as opçoes e enquanto o valor nao for zero, ele vai ficar rodando, quando for zero ele deve sair do loop e encerrar o programa
    
    switch(opt){
        
        // case 1 vai pedir pra digitar uma matricula, e usei o strcat pra fazer a concatenaçao
        // usei tambem o strcopy para copiar o conteudo escrito pra dentro do vetor.
       
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
            // aqui a variavel vagas, vai decrementar de acordo com o tantos de carros registrados no estacionamento, dai quando eu for listar as vagas livres, vou apenas dar um print na variavel vagas
          }
          i++;
        }
        break;
      case 3:
        //aqui vai mostrar todas as matriculas sendo as preenchidas ou vagas contendo um 0 para as vazias
        i = 0;
        while(i<50){
          printf("matricula: %s \n",servidor[i]);
          i++; 
        }
        break;
      case 4:
      printf("%d \n", vagas);
        break;
    } if(opt<0 || opt>4){
      printf("comando nao aceito, escolha uma opçao valida! \n");}
    
    // tratamento de erro caso seja escolhida uma opcao fora do range que eu coloquei no menu
  } while(opt != 0);
  return 0;
}
