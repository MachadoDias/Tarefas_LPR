#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q; cin >> n >> q;
    vector<int> lista(n), potenciais;
    for(int &x : lista) cin >> x;
    for(int pergunta = 0; pergunta < q; pergunta++){
        int potencial = 0;
        int l, r; cin >> l >> r;
        vector<vector<int>> respostas(n+1, vector<int>(n+1));
        if(l == r){
            potenciais.push_back(0);
            continue;
        }
        for(int i = l; i<=r; i++){
            for(int j = i; j<=r; j++){
                if(respostas[i][j] || i == j) continue;
                respostas[i][j] = lista[i-1]*10 + lista[j-1];
                respostas[j][i] = lista[j-1]*10 + lista[i-1];
                potencial += (respostas[i][j] + respostas[j][i]);
            }
        }
        potenciais.push_back(potencial);
    }
    for(int potencial : potenciais){
        cout << potencial << endl;
    }
}