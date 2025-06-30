#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, p, m;
    // Número de pedidos, camisas pequenas e médias
    vector<int> t;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        t.push_back(x);
    }
    // Preenche o vetor de tamanhos
    cin >> p >> m;
    for(int x : t){
        if(x == 1) p--;
        else m--;
    }
    // Itera sobre o vetor atualizando o contador
    if(p<0 || m <0) cout << "N" << endl;
    // Se o número de colaboradores que usam p ou m foi maior do que as camisetas disponíveis
    else cout << "S" << endl;
}