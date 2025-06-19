//Incompleto
#include <bits/stdc++.h>
using namespace std;
int dist(int x1, int y1, int x2, int y2){
    return (x2-x1)*(x2-x1)+(y2-y1);
}
int main(){
    int n; cin >> n;
    vector<pair<int, int>> tendas(n, pair<int, int>({0, 0}));
    for(int i=0; i<n; i++){
        cin >> tendas[i].first; cin >> tendas[i].second;
    }
    int tendaAtual = 0;
    for(int i = 0; i<n; i++){
        tendaAtual = max(tendaAtual, tendas[i].first + tendas[i].second);
    }
    int contador = 1, ultimaDistancia = tendas[tendaAtual].first + tendas[tendaAtual].second;
    bool acabou = false;
    while(!acabou){
        for(int i = 0; i<n; i++){
            if(tendas[i].first + tendas[i].second >= ultimaDistancia) continue;
            tendaAtual = max(tendaAtual, tendas[i].first + tendas[i].second);
            ultimaDistancia = tendas[i].first + tendas[i].second;
            contador++;
        }
    }
    cout << contador;
}
