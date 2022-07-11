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

void merge(int* lista, int* L, int tam_L, int* R, int tam_R){
	int i = 0, j = 0;
	for(int index = 0; index <= tam_L + tam_R; index++){
		if(L[i] <= R[j] && L[i] != 2147483647){
			lista[index] = L[i];
			i++;
		}else if(R[j] != 2147483647){
			lista[index] = R[j];
			j++;
		}
	}

}

void merge_sort(int* lista, int fim){
	int  index = 0, tam_R = fim/2, tam_L = tam_R, *L = NULL, *R = NULL;
	if(fim % 2 != 0) tam_L++;

	L = (int* ) malloc(tam_L * sizeof(int) + 2);
	R = (int* ) malloc(tam_R * sizeof(int) + 2);
	if(L == NULL || R == NULL) return;
	for(int i = 0; i < tam_L; i++){
		L[i] = lista[index];
		index++;
	}
	L[tam_L] == INT32_MAX;
	L[tam_L + 1] == INT32_MAX;
	cout << "Valor L[] = ";
	for(int i = 0; i <= tam_L+2;i++){
		cout << L[i] << ", ";
	}
	cout << "\n" << "Tamanho: " << tam_L << "\n";
	for(int i = 0; i < tam_R; i++){
		R[i] = lista[index];
		index++;
	}
	R[tam_R] == INT32_MAX;
	R[tam_R + 1] == INT32_MAX;
	cout << "Valor R[] = ";
	for(int i = 0; i <= tam_R+2;i++){
		cout << R[i] << ", ";
	}
	cout << "\n" << "Tamanho: " << tam_R << "\n";
	if(fim > 1){
		if(tam_L && tam_R){
			merge_sort(lista, tam_L);
			merge_sort(lista, tam_R);
		}
		
		merge(lista, L, tam_L, R, tam_R);
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
		cout << *(v+i);
	}
	free(v);	
	
	return 0;
}












