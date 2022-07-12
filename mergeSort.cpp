#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;
int parse(string entrada, int** vetor){
	stringstream stream(entrada);
	int i = 0;
	int n;
	while(stream >> n) {
		*(*(vetor) + i) = n;
		i++;
		if(i > 8 || i > 98 || i > 998 || i > 9998 || i > 99998){
			*vetor = (int* )realloc(*vetor, (i * 10) * (sizeof(int) * i));
		}
		
	}
	return i;
}


void merge_sort(int* lista, int fim){
	int *L = NULL, *R = NULL, i = 0, j = 0, index = 0, tam_R = fim/2, tam_L = tam_R;
	if(fim % 2 != 0) tam_L++;
	L = (int* ) malloc(tam_L * sizeof(int) + 2);
	R = (int* ) malloc(tam_R * sizeof(int) + 2);
	if(fim > 1){
			for(int i = 0; i < tam_L; i++){
			L[i] = lista[index];
			index++;
		}
		for(int i = 0; i < tam_R; i++){
			R[i] = lista[index];
			index++;
		}
		merge_sort(L, tam_L);
		merge_sort(R, tam_R);
		index = 0;
		while(i < tam_L && j < tam_R){
			if(L[i] <= R[j]){
				lista[index] = L[i];
				i++;
			}else{
				lista[index] = R[j];
				j++;
			}
			index++;
		}
		while(i < tam_L){
			lista[index] = L[i];
			i++;
			index++;
		}
		while(j < tam_R){
			lista[index] = R[j];
			j++;
			index++;
		}
	}
	free(L);
	free(R);
}


int main(){
	int *v = NULL;
	int tam = 0;
	string s;
	v = (int* )malloc(10*sizeof(int));
	if(v == NULL) return -1;
	getline(std::cin, s);
	tam = parse(s, &v);
	
	merge_sort(v, tam);
	for(int i = 0; i < tam; i++){
		cout << *(v+i) << " ";
	}
	free(v);	
	
	return 0;
}












