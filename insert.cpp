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
int conta(int vet[], int size){
    int swaps = 0;
    for(int i = 0; i < size - 1;i++){
        for(int j = i + 1; j < size; j++){
            if(vet[i] > vet[j]){ 
                swaps++;
                }
        }
    }
    return swaps;
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
        swap[i] = conta(v, n_elements);
    }
	free(v);
    print_L(swap, n_T);
    free(swap);	
	return 0;
}