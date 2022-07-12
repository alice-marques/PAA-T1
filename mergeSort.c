#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <malloc.h>

void merge(int32_t* l, int tamanho){
	int tam_l1 = (tamanho/2), i_l1 = 0;
	int tam_l2 = (tamanho/2), i_l2 = tam_l2+1;
	int* vecAux = (int* )malloc(tamanho * sizeof(int));
	int i_vecAux = 0;
	while(i_l1 <= tam_l1 && i_l2 < tam_l2){
		if(l[i_l1] > l[i_l2]){
			vecAux[i_vecAux] = l[i_l1];
			i_l1++;
			i_vecAux++;
		}else{
			vecAux[i_vecAux] = l[i_l2];
			i_l2++;
			i_vecAux++;
			}
	}
	while(i_l1 < tam_l1){
		vecAux[i_vecAux] = l[i_l1];
		i_l1++;
		i_vecAux++;
		}
	while(i_l2 < tam_l2){
		vecAux[i_vecAux] = l[i_l2];
		i_l2++;
		i_vecAux++;
		}
	for(int i = 0; i < tamanho; i++){
		l[i] = vecAux[i];
	}
	free(vecAux);
}
void mergeSort(int32_t* l, int tamanho){
	int m = tamanho/2;
	mergeSort(l, m + 1);
	mergeSort(l + m, m);
	merge(l, tamanho);
}
int main(void) {
	size_t len = 100000;
	int32_t* point = NULL;
	int i = 0, n = 0, character = 255;
	size_t m;
	char  vetor[12];
	point = (int32_t *)calloc(len, sizeof(int32_t));
	while( character != EOF && character != 10) { 
		character = fgetc(stdin);
		if(character != ' '){
			vetor[i] = character;
			vetor[i+1] = '\0';
			i++;
		}
		if(character == ' ' || character == 10 || character == EOF){
			point[n] = atoi(vetor);
			n++;
			i = 0;
			}
	}
	mergeSort(point, n);
	for(int i = 0; i < n; i++){
		printf("\n\n%d\n\n", point[i]);
	}
	free(point);
	return 0;
}

	if(fim > 1){
		L = merge_sort(L, tam_L);
		R = merge_sort(R, tam_R);
		
		merge(lista_res, L, tam_L, R, tam_R);
	}






	int  index = 0, tam_R = fim/2, tam_L = tam_R;
	int *L = NULL, *R = NULL, *lista_res = NULL;
	if (fim == 1) return lista;
	if(fim % 2 != 0) tam_L++;
	L = (int* ) malloc(tam_L * sizeof(int) + 2);
	R = (int* ) malloc(tam_R * sizeof(int) + 2);
	lista_res = (int*)malloc(sizeof(int) * (tam_L + tam_R));
	if(L == NULL || R == NULL || lista_res == NULL) return NULL;
	for(int i = 0; i < tam_L; i++){
		L[i] = lista[index];
		index++;
	}
	L[tam_L] == INT32_MAX;
	L[tam_L + 1] == INT32_MAX;
	for(int i = 0; i < tam_R; i++){
		R[i] = lista[index];
		index++;
	}
	R[tam_R] == INT32_MAX;
	R[tam_R + 1] == INT32_MAX;
	L = merge_sort(L, tam_L);
	R = merge_sort(R, tam_R);

	free(L);
	free(R);
	return merge(L, tam_L, R, tam_R);




	int i = 0, j = 0, index = 0;
	int *lista = (int*)malloc(sizeof(int) * (tam_L + tam_R));
	for(index = 0; index <= tam_L || index <= tam_R; index++){
		if(i < tam_L && j < tam_R){
			if(L[i] <= R[j] && L[i] != 2147483647){
				lista[index] = L[i];
				i++;
			}else if(R[j] != 2147483647){
				lista[index] = R[j];
				j++;
			}
		}
	}
	while(i < tam_L && j >= tam_R){
		if(L[i] != INT32_MAX){
			lista[index] = L[i];
			i++;
			index++;
		}
	}
	while(j < tam_R && i >= tam_L){
		if(R[j] != INT32_MAX){
			lista[index] = R[j];
			j++;
			index++;
		}
	}
	return lista;