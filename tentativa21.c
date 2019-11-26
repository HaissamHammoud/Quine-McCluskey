#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define TAM 36

struct nomestr{
    char nome[TAM];
};
typedef struct nomestr nomes;

int func(int qmin, int t);
void print_m(int *bin, int t,int s, nomes nome[]);
void swap(int *bin, int pos1,int pos2,int t, int s,nomes nome[]);
void ordem_um(int *matriz,int tami, int tamj, nomes nome[]);
int dif_vetores(int *matriz,int pos1,int pos2, int tami,int tamj);
int tam_prox(int *matriz , int tami, int tamj);
void escreve_vetor(int *matriz, int *matriz2,int loc1,int loc2,int cont,int tamj);
int quant_primo(int *matriz, int tamanhoi, int tamanhoj);
int isUsed(int *matriz, int posi, int tamj);
void equal(int *matriz, int tami,int tamjs);
int dif_vetores2(int *matriz,int pos1,int pos2, int tami,int tamj);

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
	nomes nome1[qmin];
	int mint[qmin][t+2],j,valor,quantum = 0;//o utimo valor do numero binario � a quatidade de numeros 1 que ele possui
 	int i;
	//recolhendo os valores da matriz	matriz sera organizada da segunte maneira	/ |quant1|ultilização | numero em binario| 			/////
	 for(i = 0 ; i<qmin; i++){
	 	quantum = 0;
	 	printf("\n %d :", i+1);
	 	scanf("%d", &valor);
	 	sprintf(nome1[i].nome ,"%d",valor);
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

	 print_m(*mint, qmin,t+2, nome1);
	 ordem_um(*mint,qmin, t+2,nome1);
	 dif_vetores(*mint,0,4, qmin,t+2);
	 // aqui começo a segunda tabela

	 int tam2=0;

	tam2 = tam_prox(*mint,qmin,t+2);
	printf("\n%d", tam2);
	//criando a proxima tabela de acordo com o numero de termos que a nova tabela tera
	//depois posso pensar em transformar todo esse padr�o em uma fun��o que se repete 4 vezes nesta funcao
	int matriz2[tam2][t+2],pos2= 0;
	nomes nome2[tam2];
	char string1[TAM], string2[TAM];
	for(i = 0 ; i<qmin; i++){
		for(j = i+1 ; j<qmin; j++){
			if(dif_vetores(*mint,i,j, qmin,t+2)==1){
				printf("a");
				escreve_vetor(*mint,*matriz2,i,j,pos2,t+2);
				strcpy(string1, nome1[i].nome);
				strcpy(string2, nome1[j].nome);
				strcpy(nome2[pos2].nome, string1);
				strcat(nome2[pos2].nome, "-");
				strcat(nome2[pos2].nome, string2);
				pos2++;
			}
		}
	}

        int tam3 = tam_prox(*matriz2,tam2,t+2);
        int matriz3[tam3][t+2],pos3= 0;

        nomes nome3[tam3];
        for(i = 0 ; i<tam2; i++){
		for(j = i+1 ; j<tam2; j++){
			if(dif_vetores(*matriz2,i,j, tam2,t+2)==1){
				printf("a");
				escreve_vetor(*matriz2,*matriz3,i,j,pos3,t+2);
				strcpy(string1, nome2[i].nome);
				strcpy(string2, nome2[j].nome);
				strcpy(nome3[pos3].nome, string1);
				strcat(nome3[pos3].nome, "-");
				strcat(nome3[pos3].nome, string2);
				pos3++;
			}
		}
	}

        int tam4 = tam_prox(*matriz3,tam3,t+2);
		nomes nome4[tam4];
            int matriz4[tam4][t+2],pos4= 0;
            if(tam4> 0){
            for(i = 0 ; i<tam3; i++){
            for(j = i+1 ; j<tam3; j++){
                if(dif_vetores(*matriz3,i,j, tam3,t+2)==1){
                    printf("a");
                    escreve_vetor(*matriz3,*matriz4,i,j,pos4,t+2);
                    strcpy(string1, nome3[i].nome);
					strcpy(string2, nome3[j].nome);
					strcpy(nome4[pos4].nome, string1);
					strcat(nome4[pos4].nome, "-");
					strcat(nome4[pos4].nome, string2);
                    pos4++;
                }
            }
        }
    }

        int tam5 = tam_prox(*matriz4,tam4,t+2);
		nomes nome5[tam5];
            int matriz5[tam5][t+2],pos5= 0;
            if(tam5> 0){
            for(i = 0 ; i<tam4; i++){
            for(j = i+1 ; j<tam4; j++){
                if(dif_vetores(*matriz4,i,j, tam4,t+2)==1){
                    printf("a");
                    escreve_vetor(*matriz4,*matriz5,i,j,pos4,t+2);
                    strcpy(string1, nome4[i].nome);
					strcpy(string2, nome4[j].nome);
					strcpy(nome5[pos5].nome, string1);
					strcat(nome5[pos5].nome, "-");
					strcat(nome5[pos5].nome, string2);
                    pos5++;
                }
            }
        }
    }
	// s� pra garantir
	//calculando o tamanho da primeira simplificação
    int tamp;
    tamp = quant_primo(*mint,qmin,t+2);
    tamp = tamp + quant_primo(*matriz2 , tam2,t+2);
    tamp = tamp + quant_primo(*matriz3 , tam3,t+2);
    tamp = tamp + quant_primo(*matriz4 , tam4,t+2);

    printf("\n%d", tamp);
    //verifica e marca como usado os valores repetidos na tabela
    equal(*matriz5,tam5,t+2);


    equal(*matriz4,tam4,t+2);


    equal(*matriz3,tam3,t+2);

    tamp = quant_primo(*mint,qmin,t+2);
    tamp = tamp + quant_primo(*matriz2 , tam2,t+2);
    tamp = tamp + quant_primo(*matriz3 , tam3,t+2);
    tamp = tamp + quant_primo(*matriz4 , tam4,t+2);

    printf("\n%d", tamp);

    //tamp é otamanho da primeira tabela de simplificacao
    tamp = tamp + quant_primo(*matriz5 , tam5,t+2);
    //printa as matrizer, apenas um teste
    print_m(*mint, qmin,t+2,nome1);
    print_m(*matriz2, tam2,t+2,nome2);
	print_m(*matriz3, tam3,t+2,nome3);
	print_m(*matriz4, tam4,t+2,nome4);
	print_m(*matriz5, tam5,t+2,nome5);
    //define a estrutura da ultima simplificacao
    struct simplificado{
        char nome[TAM];
        int bin[t];
        int tabela[t*t];// aqui sera marcado de 1 caso o mintermo seja usado e 0  caso nao seja usado
    };
    typedef struct simplificado simp;
    int conts = 0 ;

    simp tab1[tamp];
    for(i = 0 ; i< qmin; i++){
        if(mint[i][1]==0){
            strcpy(tab1[conts].nome,nome1[i].nome);
            for(j = 2 ; j < t+2; j++){
                tab1[conts].bin[j-2] = mint[i][j];
            }
            conts++;
        }
    }
    for(i = 0 ; i< tam2; i++){
        if(matriz2[i][1]==0){
            strcpy(tab1[conts].nome,nome2[i].nome);
            for(j = 2 ; j < t+2; j++){
                tab1[conts].bin[j-2] = matriz2[i][j];
            }
            conts++;
        }
    }
        for(i = 0 ; i< tam3; i++){
        if(matriz3[i][1]==0){
            strcpy(tab1[conts].nome,nome3[i].nome);
            for(j = 2 ; j < t+2; j++){
                tab1[conts].bin[j-2] = matriz3[i][j];
            }
            conts++;
        }
    }
    for(i = 0 ; i< tam4; i++){
        if(matriz4[i][1]==0){
            strcpy(tab1[conts].nome,nome4[i].nome);
            for(j = 2 ; j < t+2; j++){
                tab1[conts].bin[j-2] = matriz4[i][j];
            }
            conts++;
        }
    }

    //apresentando a primeira tabela de simlificaão
    printf("\n ------------------ Tabela ----------------\n");
    for(i = 0 ; i< conts ; i++){
        printf("%20s", tab1[i].nome);
        for(j = 0 ; j < t ; j++){
            printf(" %2d ",  tab1[i].bin[j]);
        }
        printf("\n");
    }



	return 0;
}

//void printRes(*matriz)
void escreve_vetor(int *matriz, int *matriz2,int loc1,int loc2,int cont,int tamj){
		//copia o conteudo de uma matriz para o outro

	int i , j ;
	for(j = 0 ; j<tamj; j++){

		if(j ==0){
			*(matriz2+(cont*tamj+j)) = *(matriz+(loc1*tamj+0));
		}
		else if(j == 1){
			*(matriz2+(cont*tamj+j)) = 0;
			*(matriz+(loc1*tamj+j)) = -1;
			*(matriz+(loc2*tamj+j)) = -1;
		}
		else if(*(matriz+(loc2*tamj+j)) == *(matriz+(loc1*tamj+j))){
			*(matriz2+(cont*tamj+j)) = *(matriz+(loc1*tamj+j));
		}
		else if(*(matriz+(loc2*tamj+j)) != *(matriz+(loc1*tamj+j))){
			if(*(matriz+(loc1*tamj+j))==0){
				*(matriz2+(cont*tamj+j)) = -1;
			}
			else{
			*(matriz2+(cont*tamj+j)) = *(matriz+(loc1*tamj+j));
			}
		}
	}
}

int tam_prox(int *matriz , int tami, int tamj){
	int i = 0 ,  j =0, cont = 0;
	for(i = 0 ; i<tami; i++){
		for(j = i+1 ; j<tami; j++){
			if(dif_vetores(matriz,i,j, tami,tamj)==1){
					cont++;
			}
		}
	}
	return cont;
}
void print_m(int *bin, int t,int s,nomes nome[]){
	//funcao para printar a matriz
	 int i, j,matriza;
  	printf("\n");
  	for(i = 0; i<t;i++){
            printf("%20s  ", nome[i].nome);
    	for(j = 0; j<s; j++ ){
      		printf(" %2d ", *(bin+(i*s+j))); //consegui =D
    		}
    	printf("\n");
  		}
	}
//fun��o feita para ordenar a matriz conforme a quantidade de 1
void ordem_um(int *matriz,int tami, int tamj, nomes nome[]){
		int i, j = 0,log = 1;
		while(log){
		log = 0;
			for(i = 0; i<tami-1 ;i++){
				if(*(matriz+(i*tamj+j)) > *(matriz+((i+1)*tamj+j)) ){
					swap(matriz,i,i+1,tami,tamj,nome);
					printf("\n %d", i);
					print_m(matriz, tami,tamj,nome);
					//sleep(1);
					log = 1;
			}
		}
	}
}
//inverte uma linha e uma coluna modo de usar()swap(matriz, i1, i2, tamanhoi , tamanho j)
void swap(int *bin, int pos1,int pos2,int t, int s,nomes nome[]){
	//funcao para printar a matriz
	 int i, j,a;
	 char p;
    	for(j = 0; j<s; j++ ){
      		a =  *(bin+(pos1*s+j));
      		*(bin+(pos1*s+j)) = *(bin+(pos2*s+j));
      		*(bin+(pos2*s+j)) = a;
    	}
    	for(j = 0 ; j < TAM ; j++){
            p  = nome[pos1].nome[j];
            nome[pos1].nome[j] = nome[pos2].nome[j];
            nome[pos2].nome[j] = p;
    	}

}
	//fun�ao que ira definir a diferen�a de um entre dois numeros binarios , no caso dois vetores da matriz
	//fucao devera retornar  quantos 1 a de diferença entre um binairo e outro
int dif_vetores(int *matriz,int pos1,int pos2, int tami,int tamj){
	//para comecar receberemos a matriz e separaremos duas matrizes
	int i ,i2, j, cont = 0; //sendo i2 e j2 valores referentes as matrizes
	//aqui compararo atravez de j numero por numero e atribuiremos a quantidade de um diferente entre dois vetores
	for(j = 2 ; j <tamj ; j++){
		if( ( ((*(matriz+(pos1*tamj+j)))) != (*(matriz+(pos2*tamj+j))) ) && ( (((*(matriz+(pos1*tamj+j)))) ==0 || (((*(matriz+(pos1*tamj+j)))) ==-1))) &&  ( ((*(matriz+(pos1*tamj+0)))) == (*(matriz+(pos2*tamj+0)))-1 ) ){

			cont ++;
		}
	}
	return cont;
}
int dif_vetores2(int *matriz,int pos1,int pos2, int tami,int tamj){
	//para comecar receberemos a matriz e separaremos duas matrizes
	int i ,i2, j, cont = 0; //sendo i2 e j2 valores referentes as matrizes
	//aqui compararo atravez de j numero por numero e atribuiremos a quantidade de um diferente entre dois vetores
	for(j = 2 ; j <tamj ; j++){
		if ( ((*(matriz+(pos1*tamj+j)))) != (*(matriz+(pos2*tamj+j))) ) {
			cont ++;

		}
	}
	return cont;
}
//essa funcao servira para retornar quantos primos restantes existem
int quant_primo(int *matriz, int tami, int tamj){
    int i, j, cont = 0;
    for(i = 0 ; i < tami; i++ ){

            if(*(matriz+(i*tamj+1))==0){
                cont ++;

        }
    }
    return cont;
}
//verifica se um mintermo ja foi ou nao usado
int isUsed(int *matriz, int posi, int tamj){
    if(*(matriz+(posi*tamj+1))== 0){
        return 0;
    }
    else{
        return 1;
    }
}
//tami aqui recebe tamanho do numero binarop
void equal(int *matriz, int tami,int tamj){
    int i = 0, j = 0,cont = 0;
    for(i = 0 ; i< tami ; i++){
        for(j = i+1 ; j< tami; j++){
            if(dif_vetores2(matriz,i,j,tami,tamj) == 0){
                printf("aa");
                *(matriz+(j*tamj+1)) = -1;
            }
        }
    }
}

