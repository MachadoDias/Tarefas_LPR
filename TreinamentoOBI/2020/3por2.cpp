// Complexidade de tempo: O(n)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> precos;
    for(int i = 0; i<n; i++){
        int t; cin >> t;
        precos.push_back(t);
    }
    // Lê os preços
    sort(rbegin(precos), rend(precos));
    // Organiza em ordem decrescente
    int soma = 0;
    for(int i = 1; i<=n; i++){
        if(i%3 != 0) soma +=precos[i-1];
    }
    //calcula a soma desconsiderando os chocolates que estão em posições múltiplas de 3
    cout << soma << endl;
}