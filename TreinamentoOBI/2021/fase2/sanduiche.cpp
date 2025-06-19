#include <bits/stdc++.h>
using namespace std;
int ans = 0;
vector<set<int>> invalido;
void search(int y,int n, const vector<int> &sAtual){
    if(y == n){
        ans++;
        return;
    }
    bool podeAdicionar = true;
    for(int ingrediente : sAtual){
        if(invalido[y].count(ingrediente)) {
            podeAdicionar = false;
            break;
        }
    }
    search(y+1, n, sAtual);
    if(podeAdicionar){
        vector<int> sNovo = sAtual;
        sNovo.push_back(y);
        search(y+1, n, sNovo);
    }
}
int main(){
    int n, m; cin >> n >> m;
    invalido.resize(n+1);
    for(int i=1; i<=m; i++){
        pair<int, int> par; cin >> par.first >> par.second;
        par.first--; par.second--;
        invalido[par.first].insert(par.second);
        invalido[par.second].insert(par.first);
    }
    vector<int> sanduiche;
    search(0, n, sanduiche);
    cout << ans-1 << endl;
}