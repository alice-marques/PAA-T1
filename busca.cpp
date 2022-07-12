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

int busca(int* lista, int inicio, int fim, int Query){
	int meio = 0;
	int *l1 = NULL, *l2 = NULL;
	if(lista[inicio] > lista[fim]) return -1;
	meio = (fim + inicio)/2;
	cout << "sdjasdasjdasjdj" << endl;
	if(Query == lista[meio]){
		printf("entrou igual ao meio");
	       	return meio;
	}else if(Query > lista[meio]){
	       	printf("entrou maior q meio");
		return busca(lista, meio+1, fim, Query);
	}else if(Query < lista[meio]) {
		printf("entrou menor q meio");
		return busca(lista, 0, meio, Query);
	}else {
		return -1;
	}	
}



int main(){
	int *v = NULL, num_Q = 0, n_elements = 0, *N_Q = NULL, num_N = 0;
	int tam = 0, Query = 0, *res = NULL;
	string s;
	N_Q = (int*)malloc(2*sizeof(int));
	getline(cin, s);
	cin.ignore();
	parse(s, &N_Q);
	num_N = N_Q[0];
	num_Q = N_Q[1];
	free(N_Q);
	res = (int*)malloc(num_Q * sizeof(int));
	v = (int* )malloc(num_N * sizeof(int));
	getline(cin, s);
	cin.clear();
	if(parse(s, &v) != num_N-1) return -5;
	for(int i = 0; i < num_Q - 1; i++){
		scanf("%d", &Query);
		res[i] = busca(v, 0, num_N-1, Query);
	}
	for(int i =0; i < num_Q; i++){
		cout << res[i] << endl;
	}
	return 0;
}




