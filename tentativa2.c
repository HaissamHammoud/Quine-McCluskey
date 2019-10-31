#include<stdio.h>
#include<stdlib.h>


int func(int qmin, int t);
void print_m(int *bin, int t,int s);
void swap(int *bin, int pos1,int pos2,int t, int s);
void ordem_um(int *matriz,int tami, int tamj);


int main(){
	
	int t, i = 0,qmin=0;
	
	printf("\nNumero de variaveis:");
	scanf("%d", &t);
	
	printf("znEntre com a quantidade de mintermo");
	scanf("%d", &qmin);
	//recolhe os valores mintermo 
	func(qmin, t);
	
	
	
	return 0;
}

int func(int qmin, int t){
	//sendo qmin a quantidade de mintermo e t o tamanho do valor binario
	printf("\nEntre com os valores do mintermo");
	//t = t+3;
	int mint[qmin][t+2],j,valor,quantum = 0;//o utimo valor do numero binario é a quatidade de numeros 1 que ele possui
 	int i;
	printf("\nEntre com os valores do mintermo");
	//////////////////////////////////////////////////////
	//recolhendo os valores da matriz				/////
	//matriz sera organizada da segunte maneira		////
	// |ultilizacao|quant de um | numero em binario|////
	///////////////////////////////////////////////////
	 for(i = 0 ; i<qmin; i++){
	 	quantum = 0;
	 	printf("\n %d :", i);
	 	scanf("%d", &valor);
	 	for(j = t+1; j>=0;j--){
	 		if(j == 0){
	 			//printf("v : %d",quantum);
	 			mint[i][j] = quantum ;// terminar
			 }
			 else if(j == 1){
	 			//printf("v: %d",quantum);
	 			mint[i][j] = 0 ;// terminar
			 }
			 else{
			 
	 		mint[i][j] = valor%2;
	 		valor = (float)valor/ 2;
	 	}
	 		if(mint[i][j] == 1){
	 			quantum ++;
			 }
	
		 } 
	 }	

	 //quant_um(*mint,t,qmin);
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 // a ideia a partir daqui é criar varias matrizes separando os numeros binarios pelas quanidades de numero 1//
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	 //sera uma boa ideia também implementar mais um espaço na matriz para definir se o mintermo foi ou não usado//--- por hora definirei -1 caso tenha sido usado
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 print_m(*mint, qmin,t+2);//////////////////////////////////////
	 ordem_um(*mint,qmin, t+2); //// isto é um teste de verficação//
	 ///////////////////////////////////////////////////////////////
	 
	 
   
	 
	 
	 
	return 0;	
}
//Funcao que ira retornar quantos um cada  vetor possui

void print_m(int *bin, int t,int s){
	//funcao para printar a matriz
	 int i, j,matriza;
  	
  	printf("\n");
  	for(i = 0; i<t;i++){
    	for(j = 0; j<s; j++ ){
      		printf(" %2d ", *(bin+(i*s+j))); //consegui =D
    		}
    	printf("\n");
  		}
	}

//função feita para ordenar a matriz conforme a quantidade de 1 
void ordem_um(int *matriz,int tami, int tamj){
		int i, j = 0,log = 1;
		//sera passado o tamanho do i e do j da funcao//
		///////////////////////////////////////////////	
		while(log){
		log = 0;
			for(i = 0; i<tami-1 ;i++){
				if(*(matriz+(i*tamj+j)) > *(matriz+((i+1)*tamj+j)) ){
					swap(matriz,i,i+1,tami,tamj);
					printf("\n %d", i);
					print_m(matriz, tami,tamj);
					//sleep(1);
					log = 1;
					
					
					
				}
			}
			
		}
	    
	
}
//inverte uma linha e uma coluna modo de usar()swap(matriz, i1, i2, tamanhoi , tamanho j)
void swap(int *bin, int pos1,int pos2,int t, int s){
	//funcao para printar a matriz
	 int i, j,a;
  	
  	
  	
    	for(j = 0; j<s; j++ ){
      		a =  *(bin+(pos1*s+j)); 
      		*(bin+(pos1*s+j)) = *(bin+(pos2*s+j));
      		*(bin+(pos2*s+j)) = a;
    		}
    	
  		}
	
	//funçao que ira definir a diferença de um entre dois numeros binarios , no caso dois vetores da matriz 
int dif_vetores(int *matriz,int pos1,int pos2, int tami,int tamj){
	
}
