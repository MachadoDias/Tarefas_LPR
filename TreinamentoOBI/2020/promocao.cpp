#include <bits/stdc++.h>

using namespace std;
int resposta;
struct arestas
{
    int vizinho;
    int empresa;
};
// Struct para melhorar legibilidade

pair<int, int> dfs(const vector<vector<arestas>> &adj, vector<bool> &vis, int u){
    vis[u] = true;
    // Marca a cidade como vistada
    int maxRoyal = 0, maxImperial = 0;
    // Variáveis que controlam o maior caminho de cada empresa
    for(const auto &aresta : adj[u]){
        int v = aresta.vizinho;
        int empresaV = aresta.empresa;
        if(!vis[v]){
            pair<int,int> filho = dfs(adj, vis, v);
            // Percorre as cidades ligadas a original
            if(empresaV == 0){
                int caminhoAtual = 1 + filho.second;
                maxRoyal = max(maxRoyal, caminhoAtual);
            }
            // Se a empresa for a royal, atualiza o maior caminho encontrado
            else {
                int caminho_atual = 1 + filho.first;
                maxImperial = max(maxImperial, caminho_atual);
            }
            // Mesmo processo descrito acima, mas com a imperial
        }
    }
    resposta = max(resposta, maxRoyal + maxImperial + 1);
    //atualiza a resposta
    return {maxRoyal, maxImperial};
    // retorna os caminhos máximos de cada chamada
}

int main(){
    int n; cin >> n;
    vector<vector<arestas>> adj(n+1);
    // Estrutura para armazenar as cidades e as cidades que elas estão conectadas 
    for(int i = 1; i<n; i++){
        int a, b, e; cin >> a >> b >> e;
        adj[a].push_back({b, e});
        adj[b].push_back({a, e});
        // Adiciona as cidades de entrada na lista de cidades vizinhas
    }
    resposta = 1;
    vector<bool> vis(n+1);
    // inicializa o vetor que contém as cidades visitadas
    dfs(adj, vis, 1);
    cout << resposta << endl;
}