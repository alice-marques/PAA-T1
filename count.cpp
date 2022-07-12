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


int merge_sort(int* lista, int fim){
	int *L = NULL, *R = NULL, i = 0, j = 0, index = 0, tam_R = fim/2, tam_L = tam_R;
	int invCount = 0;
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
		invCount += merge_sort(L, tam_L);
		invCount += merge_sort(R, tam_R);
		index = 0;
		while(i < tam_L && j < tam_R){
			if(L[i] <= R[j]){
				lista[index] = L[i];
				i++;
			}else{
				lista[index] = R[j];
				invCount += (tam_L - i);
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
	return invCount;
}

void print_L(int *l, int tam){
    for(int i = 0; i < tam; i++){
		cout << l[i] << endl;
	}
}

int main(){
	int *v = NULL, n_T = 0, n_elements = 0, *swap = NULL;
	int tam = 0;
	string s;
	v = (int* )malloc(10*sizeof(int));
	if(v == NULL) return -1;
    scanf("%d", &n_T);
    swap = (int*)malloc(sizeof(int) * n_T);
    for(int i = 0; i < n_T; i++){
        scanf("%d", &n_elements);
        cin.ignore();
        getline(cin, s);
        if(n_elements != parse(s, &v)) return -3;
        swap[i] = merge_sort(v, n_elements);
    }
    print_L(swap, n_T);
	free(v);
    	free(swap);	
	return 0;
}











