// Funcional mas ineficiente, 30/100 por timeout
#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<long long, int> memo;
int64_t dist(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
int dfs(int tendaAtual, int64_t ultimaDistancia, vector<pair<int, int>> &tendas)
{
    long long chave = (1LL * tendaAtual << 32) | ultimaDistancia;
    if (memo.count(chave))
        return memo[chave];
    int melhor = 1;
    for (int i = 0; i < n; i++)
    {
        if (tendaAtual == i)
            continue;
        int64_t distancia = dist(tendas[tendaAtual].first, tendas[tendaAtual].second, tendas[i].first, tendas[i].second);
        if (distancia < ultimaDistancia)
        {
            melhor = max(melhor, 1 + dfs(i, distancia, tendas));
        }
    }
    return memo[chave] = melhor;
}
int main()
{
    cin >> n;
    vector<pair<int, int>> tendas(n, pair<int, int>({0, 0}));
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &tendas[i].first, &tendas[i].second);
    }
    set<int64_t> todas_distancias;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                todas_distancias.insert(dist(tendas[i].first, tendas[i].second, tendas[j].first, tendas[j].second));
            }
        }
    }
    int tendaAtual = 0;
    int melhor = 0;
    for (int i = 0; i < n; i++)
    {
        int64_t ultimaDistancia = dist(0, 0, tendas[i].first, tendas[i].second);
        int contadorAtual = dfs(i, ultimaDistancia, tendas);
        melhor = max(melhor, contadorAtual);
    }
    cout << melhor;
}
