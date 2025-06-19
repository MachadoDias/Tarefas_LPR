#include <bits/stdc++.h>
using namespace std;
int search(vector<long long> &lista){
    int i = 0, j = lista.size() - 1, contador = 0;
    while (i<j){
        if(lista[i] > lista[j]){
            lista[j-1] += lista[j];
            contador++; j--;
        }
        else if(lista[j] > lista[i]){
            lista[i+1] += lista[i];
            contador++; i++;
        }
        else{
            i++; j--;
        }
    }
    return contador;
}
int main(){
    int n; cin >> n;
    vector<long long> lista(n);
    for(int i = 0; i < n; i++){
		scanf("%lld", &lista[i]);
	}
    cout << search(lista) << endl;
}