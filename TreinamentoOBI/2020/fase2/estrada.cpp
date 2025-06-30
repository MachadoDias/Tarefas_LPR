#include <bits/stdc++.h>
using namespace std;
float ValorMedio(float a, float b){
    return (b-a)/2;
}
int main(){
    int t, n; cin >> t >> n;
    vector<int> cidades(n);
    for(int &c : cidades){
        cin >> c;
    }
    sort(cidades.begin(), cidades.end());
    float menorVizinhanca = cidades[0] + ValorMedio(cidades[0], cidades[1]);
    for(int i = 1; i<cidades.size() - 1; i++){
        menorVizinhanca = min(menorVizinhanca, ValorMedio(cidades[i-1], cidades[i]) + ValorMedio(cidades[i], cidades[i+1]));
    }
    menorVizinhanca = min(menorVizinhanca, t - cidades.back() + ValorMedio(cidades[cidades.size() - 2], cidades.back()));
    cout << fixed << setprecision(2) << menorVizinhanca; 
}