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

int insertion_sort(int *lista, int tamanho){
    int i = 0, j = 0, elemen = INT32_MIN, swap = 0;
    for(i; i < tamanho; i++){
        elemen = lista[i];
        j = i - 1;
        while(j >= 0 && lista[j] > elemen){
            lista[j + 1] = lista[j];
            j = j-1;
            swap++;
        }
        lista[j + 1] = elemen;

    }
    return swap;
}
void print_L(int *l, int tam){
    for(int i = 0; i < tam; i++){
		cout << l[i] << " ";
	}
    cout << endl;
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
        swap[i] = insertion_sort(v, n_elements);
    }
    print_L(swap, n_T);
	free(v);
    free(swap);	
	
	return 0;
}
