#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int voltacompleta=0;          // essa variavel global tem como uso, a parte de saber se os peoes ja deram uma volta para entrarem na torre final

typedef struct jogador{      // (criando a struct dos jogadores)
  char nome[40];
  int verificacao;          // a verificacao serve para verificar dentro das funcoes os jogadores que vao jogar em acoes especificas deles
  int P[4];
  int iniciais;
  int finais;
}jogador;

int rodardados(int x);                                                                
void dados_6cima(int peao1, int *dado1, jogador *j, jogador *jcomp);                    //prototipo das funcoes
void dados_6baixo(int peao1, int *dado1, jogador *j, jogador *jcomp);

int main(){                                                                                     //iniciando o menu do jogo

  srand(time(NULL));
  printf("            -------- BEM VINDO AO LUDO!!!! --------\n\n\n\n\n\n");          
  char roladado;
  jogador j1;
  jogador j2;
  int dado=0;
  int peao;
  
  j1.verificacao=1;
  j2.verificacao=2;
  printf("Digite o nome do jogador 1 (vermelho):\n");
  setbuf(stdin, NULL);
  fgets(j1.nome,40,stdin);
  printf("\n\n");
  printf("Digite o nome do jogador 2 (amarelo):\n");
  setbuf(stdin, NULL);
  fgets(j2.nome,40,stdin);
  printf("\n\n");
  
  for(int i=0; i<4; i++){
    j1.P[i]=0;
    j2.P[i]=0;
  }
  j1.iniciais=4;
  j1.finais=0;
  j2.iniciais=4;
  j2.finais=0;
                                          //comecando a sequencia que dara inicio ao jogo
                                                      
  do{
    printf("Vez de: ");
    fputs(j1.nome, stdout);
    printf("\n\n");
    printf("cor vermelha");
    printf("\n\n");
    do{
      printf("aperte espaco e enter para rolar o dado:\n\n");
      setbuf(stdin, NULL);
      scanf("%c",& roladado);
    }while(roladado!=' ');
    if(roladado==' '){
      dado= rodardados(dado);
      printf(" A soma dos dados e : %d\n\n", dado);

      
    if(dado==0)
        printf("Perdeu a vez\n");

      
    }
    if(dado<6){                                //para dados menor que 6
      do{
        printf("Escolha o peao que deseja mover apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      
      dados_6baixo(peao,& dado,& j1,& j2);
      peao=0;
    }

    if(dado>=6 && dado<12){                     //para dois dados 1 dado 6
      do{
        printf("Escolha o peao que deseja mover ou retirar do inicio apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      
      dados_6cima(peao,& dado, &j1,& j2);
      peao=0;
      
      do{
        printf("Escolha o peao que deseja mover apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      
      dados_6baixo(peao,& dado,& j1,& j2);
      peao=0;
    }

    if(dado>=12 && dado<18){
      do{
        printf("Escolha o peao que deseja mover ou retirar do inicio apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      
      dados_6cima(peao,& dado, &j1,& j2);
      peao=0;
      
      do{
        printf("Escolha o peao que deseja mover ou retirar do inicio apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      
      dados_6cima(peao,& dado, &j1,& j2);
      peao=0;

     do{
       printf("Escolha o peao que deseja mover apertando os numeros de um a quatro.\n");
       scanf("%d",& peao);
     } while(peao<1 || peao>4);
      
     dados_6baixo(peao,& dado,& j1,& j2);
     peao=0;
    }   
    for(int i=0; i<4; i++){
      printf("Peao %d na casa %d\n", i+1, j1.P[i]);
    }
    printf("Peoes no inicio: %d\n\n ", j1.iniciais);
    printf("Peoes no final: %d\n\n", j1.finais);                                                                            
                                                                       //vez do jogador dois....      
   
    printf("Vez de: ");
    fputs(j2.nome, stdout);
    printf("\n\n");
    printf("cor amarelo");
    printf("\n\n");
    do{
      printf("aperte espaco e enter para rolar o dado:\n\n");
      setbuf(stdin, NULL);
      scanf("%c",& roladado);
    } while(roladado!=' ');
    if(roladado==' '){
      dado= rodardados(dado);
      printf(" A soma dos dados e : %d\n\n", dado);

      
    if(dado==0)
      printf("Perdeu a vez\n");

      
    }
    if(dado<6){                                //para dados menor que 6
      do{
      printf("Escolha o peao que deseja mover apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      dados_6baixo(peao,& dado,& j2,& j1);
      peao=0;
    }

    if(dado>=6 && dado<12){                     //para dois dados 1 dado 6
      do{
        printf("Escolha o peao que deseja mover ou retirar do inicio apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      dados_6cima(peao,& dado, &j2,& j1);
      peao=0;
      
      do{
        printf("Escolha o peao que deseja mover apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      dados_6baixo(peao,& dado,& j2,& j1);
      peao=0;
    }

    if(dado>=12 && dado<18){
      do{
        printf("Escolha o peao que deseja mover ou retirar do inicio apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);  
      dados_6cima(peao,& dado, &j2,& j1);
      peao=0;
      
      do{
        printf("Escolha o peao que deseja mover ou retirar do inicio apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      dados_6cima(peao,& dado, &j2,& j1);
      peao=0;

      do{
        printf("Escolha o peao que deseja mover apertando os numeros de um a quatro.\n");
        scanf("%d",& peao);
      } while(peao<1 || peao>4);
      dados_6baixo(peao,& dado,& j2,& j1);
      peao=0;
    } 
    for(int i=0; i<4; i++){
      printf("Peao %d na casa %d\n", i+1, j2.P[i]);
    }
    printf("Peoes no inicio: %d\n\n", j2.iniciais);
    printf("Peoes no final: %d\n\n", j2.finais);
    } while(j1.finais !=4 || j2.finais !=4);

  return 0;
}

                                                                      
                                                                              //FUNCOES





int rodardados(int x){       //(fazendo o dado)
  x= (rand() % 6) + 1;
  if(x==6)
    x= x+(rand() % 6) + 1;
    if(x==12)
      x= x+(rand() % 6) + 1;
      if(x==18)
        x=0;
return x;
}


void dados_6cima(int peao1, int *dado1, jogador *j, jogador *jcomp){           // funcao para repetir as jogadas 
  int alterna = 0; 
  int regula=0;
  int i = 0;
  do{
    for(i=0; i<4; i++){
        if(peao1== i+1){
          if(j->P[i]==0){
            if(j->verificacao== 1){
              j->P[i]++;
              *dado1= *dado1-6;
              j->iniciais-= 1;
			        alterna = 1;
			        regula++;
            }
            else if(j->verificacao== 2){
              j->P[i]= 27;
              *dado1= *dado1-6;
              j->iniciais-= 1;
              alterna = 1;
              regula++;
              voltacompleta++;
            }
          } break;
		    } 
	  }    
    if (alterna == 0){
		  if(j->verificacao== 1){
			    if(j->P[i]>=51){
            j->P[i]= 57- j->P[i];
            if(*dado1<= 57- j->P[i]){
				      j->P[i]= j->P[i] + (57-j->P[i]);
              j->finais++;
              regula++;
              j->P[i]= j->P[i]+6;
              *dado1= *dado1-6; 
            }
            else{
				      printf("Escolha outro peao");
              scanf("%d",& peao1);
            }
          }
			    else {
				    if (j->P[i]==0){
				      printf("Escolha outro peao");
              scanf("%d", & peao1);
				    } 
            else {
				      j->P[i]= j->P[i]+6;
				      *dado1 -= 6;
				      regula++;
			      }      
          }
      }    
      else if(j->verificacao== 2){
        if(voltacompleta==1){
          if(j->P[i]>= 25 && j->P[i]<= 31){
            j->P[i]= 25- j->P[i];
            if(*dado1<= 25- j->P[i]){
                j->P[i]= j->P[i] + (25-j->P[i]);
                j->finais++;
                regula++;
                j->P[i]= j->P[i]+6;
                *dado1= *dado1-6; 
            }
            else{
              printf("Escolha outro peao");
              scanf("%d", & peao1);
            }
          } 
        }
          else {
				    if (j->P[i]==0){
				      printf("Escolha outro peao");
              scanf("%d", & peao1);
				    } 
            else {
              if(j->P[i]>= 52){
                j->P[i]= (j->P[i]+ 6)-52;
                *dado1-= 6;
                regula ++;
              }
              else{
				        j->P[i]= j->P[i]+6;
				        *dado1 -= 6;
				        regula++;
              }
			      }
          }
		  }
		}
    for(int k=0; k<4; k++){
      if(voltacompleta==0){
        if(jcomp->P[k] !=0 || jcomp->P[k] != 1 || jcomp->P[k] != 9 || jcomp->P[k] != 14 || jcomp->P[k] != 22 || jcomp->P[k] != 27 || jcomp->P[k] != 35 || jcomp->P[k] != 40 || jcomp->P[k] != 48){
          if(j->P[i]== jcomp->P[k]){
            jcomp->P[k]=0;
            jcomp->iniciais+=1;
          }
        }
      }
    } 
    voltacompleta=0;
  }while(regula==0);
}



void dados_6baixo(int peao1, int *dado1, jogador *j, jogador *jcomp){
  int alterna = 0;           //variavel alterna criada para alternar qual parte da funcao e executada
  int regra=0;
  int regula=0;             //variavel regra criada para ajudar na regra de passar a vez quando escolhe o peao no inicio e tambem quando nao tem nenhum peao no jogo
  int i = 0;
  do{
    for(i=0; i<4; i++){
      if(peao1== i+1){ 
        if(j->iniciais== 4){
          printf("Passa a vez\n\n");
		      alterna = 1;
			    regula++;
		    } break;
		  }	    
    }     
    if (alterna == 0){
	    if(j->P[i]==0){
        printf("Escolha outro peao\n");
        scanf("%d",&peao1);
      }
      else if(j->verificacao== 1){
			  if(j->P[i]>=51){
          j->P[i]= 57- j->P[i];
          if(*dado1<= 57- j->P[i]){
            j->P[i]= j->P[i] + (57-j->P[i]);
            j->finais++;
            regula++;
            j->P[i]= j->P[i]+*dado1;
          }
          else{
            printf("Escolha outro peao");
            scanf("%d",& peao1);
          }
        }
			  else if (j->P[i]==0){
				  printf("Escolha outro peao");
          scanf("%d", & peao1);
				} 
        else {
				  j->P[i]+=*dado1;
				  regula++;
			  }
      }
      else if(j->verificacao== 2){
        if(voltacompleta==1){
          if(j->P[i]>= 25){
					  j->P[i]= 25- j->P[i];
            if(*dado1<= 25- j->P[i]){
              printf ("3\n");
					    j->finais++;
              regula++;
              j->P[i]+=*dado1;
            }    
          }
        }
				  else if (j->P[i]==0){
					  printf("Escolha outro peao");
            scanf("%d", & peao1);
          }
          else {
            if(j->P[i]>= 52){
              j->P[i]= (j->P[i]+*dado1)- 52;
              regula++;
            }
            else{
					    j->P[i]+=*dado1;
				      regula++;
            }  
			    }
      }
    }
    for(int k=0; k<4; k++){
      if(voltacompleta==0){
        if(jcomp->P[k] !=0 || jcomp->P[k] != 1 || jcomp->P[k] != 9 || jcomp->P[k] != 14 || jcomp->P[k] != 22 || jcomp->P[k] != 27 || jcomp->P[k] != 35 || jcomp->P[k] != 40 || jcomp->P[k] != 48){
          if(j->P[i]== jcomp->P[k] && j->P[i] != 0){
            jcomp->P[k]=0;
            jcomp->iniciais+=1;
          }
        }
      }
    }
    voltacompleta=0;
  }while(regula==0);			
}
