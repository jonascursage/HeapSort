#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "HeapSort.h"




struct item{
	char prefixo [8]; //chave 
	int value;	//combustivel
};



struct heap{
	int size, capacity, troca, compara;
	Item v;
	
};

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/* Cria uma nova arvore*/
Heap h_new(char* prefixo, int item){
	Heap heap = (Heap)malloc(sizeof(struct heap));
	heap->capacity=1;
	heap->v = (Item)calloc(heap->capacity,sizeof(struct item));
	strcpy(heap->v[0].prefixo,prefixo);
	heap->v[0].value = item;
	heap->size = 1;
	return heap;

}

/*Libera o vetor, e o heap*/
void h_free(Heap heap){
	if(heap == NULL)
		return;
	free(heap->v);
	free(heap);
}

/*Almenta o tamanho do vetor*/
void resize(Heap heap, int capacity){
	Item vetor = (Item)calloc(capacity,sizeof(struct item));
	int i;
	for(i = 0; i<heap->size; i++){
		strcpy(vetor[i].prefixo,heap->v[i].prefixo);
		vetor[i].value = heap->v[i].value;
	}
	free(heap->v);
	heap->v = vetor;
	heap->capacity = capacity;
}


int h_isEmpty(Heap heap){
	return heap->size == 0;
}


Heap h_insert(Heap heap, char* prefixo, int item){
	
	int cont = 0; // Numero de trocas
	int cont2 = 0;// Numero de comparaçoes
	
	if(heap == NULL) 
		return h_new(prefixo, item);

	/*Vetor diferente de zero, e estiver cheio*/

	if(heap->size == heap->capacity)
		resize(heap, 2*heap->capacity);
	
	/*inserer na ultima posiçao do vetor*/
	heap->v[heap->size].value = item;
	strcpy(heap->v[heap->size].prefixo,prefixo);
	
	/*coloca no corrente em k e incrementa size*/

	int k = heap->size++;
	/*Enquanto elemento for menor que os pais*/

	while((k>0) && strcmp(heap->v[k].prefixo,heap->v[k - 1].prefixo)<0){
		
		/*troca posiçao*/

		char aux_prefixo[8];		
		strcpy(aux_prefixo,heap->v[k].prefixo);
		int aux_item = heap->v[k].value;
		strcpy(heap->v[k].prefixo,heap->v[k - 1].prefixo);
		heap->v[k].value = heap->v[k - 1].value;
		strcpy(heap->v[k - 1].prefixo,aux_prefixo);
		heap->v[k - 1].value = aux_item;
		
		/*Atualiza posiçao do no*/
		cont ++;
		k = k - 1;
		

	}
	cont2 = cont + 1;
	heap->troca = cont;
	heap->compara = cont2;
	return heap;
}








void h_print(Heap heap){
	int i;
	//printf("\n Exibe heap\n\n");
	for(i = 0; i < heap->size; ++ i){
		printf("%s %03d\n",heap->v[i].prefixo,heap->v[i].value);
	}	
	printf("\n Numero de trocas: %d\n Numero de comparaçoes: %d\n", heap->troca, heap->compara);
}

/*Le o arquivo voos.txt*/
Heap ler_arquivo_1(Heap heap){

	int item;
	char prefixo[8]; //prefixo[7] = '\0';
	//char tempo[4]; //tempo[3] = '\0';
	
	FILE *fptr; /*Ponteiro para arquivo*/
	/*abre arquivo para ler em modo texto*/
	fptr = fopen("voos.txt","r");
	char ch;
	if(fptr == NULL){
		printf("\nErro, nao foi possivel abrir o arquivo\n");
		return heap;
	}

	int cont = 0;
	/*Enquanto o arquivo nao chegar ao final*/
	while( fscanf(fptr,"%s %d\n",prefixo,&item) != EOF){
	

			heap = h_insert(heap, prefixo, item);
			printf("insert %s %03d\n",prefixo, item);
			cont++;
			
		
	}
	printf("\nLeitura realizada com sucesso.\n");

	fclose(fptr);
	return heap;
}


/*Ler arquivo soov.txt*/
Heap ler_arquivo_2(Heap heap){

	int item;
	char prefixo[8]; //prefixo[7] = '\0';
	//char tempo[4]; //tempo[3] = '\0';
	
	FILE *fptr; /*Ponteiro para arquivo*/
	/*abre arquivo para ler em modo texto*/
	fptr = fopen("soov.txt","r");
	char ch;
	if(fptr == NULL){
		printf("\nErro, nao foi possivel abrir o arquivo\n");
		return heap;
	}

	int cont = 0;
	/*Enquanto o arquivo nao chegar ao final*/
	while( fscanf(fptr,"%s %d\n",prefixo,&item) != EOF){
	

			heap = h_insert(heap, prefixo, item);
			printf("insert %s %03d\n",prefixo, item);
			cont++;
			
		
	}
	printf("\nLeitura realizada com sucesso.\n");

	fclose(fptr);
	return heap;
}


/*Ler arquivo voos-ord.txt*/
Heap ler_arquivo_3(Heap heap){

	int item;
	char prefixo[8]; //prefixo[7] = '\0';
	//char tempo[4]; //tempo[3] = '\0';
	
	FILE *fptr; /*Ponteiro para arquivo*/
	/*abre arquivo para ler em modo texto*/
	fptr = fopen("voos-ord.txt","r");
	char ch;
	if(fptr == NULL){
		printf("\nErro, nao foi possivel abrir o arquivo\n");
		return heap;
	}

	int cont = 0;
	/*Enquanto o arquivo nao chegar ao final*/
	while( fscanf(fptr,"%s %d\n",prefixo,&item) != EOF){
	

			heap = h_insert(heap, prefixo, item);
			printf("insert %s %03d\n",prefixo, item);
			cont++;
			
		
	}
	printf("\nLeitura realizada com sucesso.\n");

	fclose(fptr);
	return heap;
}


int h_exit(Heap heap){
	h_free(heap);
	exit(1);
}



void h_show(Heap heap){
	h_print(heap);
	//h_free(heap);
}


/*Menu de opçoes do programa*/
int menu(Heap heap){

	int opcao = 0;
	do{
		printf("1 - Ler arquivo \"voos.txt\" \n2 - Ler o arquivo \"soov.txt\"\n3 - Ler o arquivo \"voos-ord\"\n4 - Exibe avios em ordem crescente, com numero de trocas e comparaçoes efetuadas para a ordenaçao\n5 - Exit");
			
			
			
			
			
		printf("\nsua opcao:");
		scanf("%d",&opcao);
		if(opcao<1 || opcao>6){
			printf("\nOpcao invalida, tenete novamente");
			getchar();
			//system("pause");
			system("cls");
			continue;
		}
		switch(opcao){
			case 1: heap = ler_arquivo_1(heap);

			//system("pause");//para Windows
			getchar(); // Para Linux
			break;

			case 2: heap = ler_arquivo_2(heap);
			//system("pause");
			getchar();
			break;

			case 3: heap = ler_arquivo_3(heap);
			//system("pause");
			getchar();
			break;

			case 4: h_show(heap);


			//system("pause");
			getchar();
			break;

			case 5: h_exit(heap); 
			//system("pause");
			getchar();
			break;

			
		}
	}
	while(opcao !=5);
	return 0;

}

