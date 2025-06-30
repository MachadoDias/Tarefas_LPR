#include <bits/stdc++.h>
using namespace std;
int dfs(int p, vector<int> &alturaSalao, vector<vector<int>> &tuneis, vector<int> &memo){
    if(memo[p] != - 1) return memo[p];
    int melhor = 0;
    for(int i = 0; i<tuneis[p].size(); i++){
        if(alturaSalao[tuneis[p][i]] < alturaSalao[p]){
            melhor = max(melhor, 1 + dfs(tuneis[p][i], alturaSalao, tuneis, memo));
        }
    }
    return memo[p] = melhor;
}
int main(){
    int s, t, p; cin >> s >> t >> p;
    vector<int> alturaSalao (s);
    for(int &x : alturaSalao){
        cin >> x;
    }
    vector<vector<int>> tuneis(s);
    vector<int> memo(s, -1);
    for(int k = 0; k < t; k++){
        int i, j; cin >> i >> j;
        tuneis[i-1].push_back(j-1); tuneis[j-1].push_back(i-1);
    }
    int melhor = dfs(p-1, alturaSalao, tuneis, memo);
    cout << melhor;
}