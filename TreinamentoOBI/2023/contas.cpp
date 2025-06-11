#include <bits/stdc++.h>
using namespace std;
int main(){
    int v, a, f, p;
    cin >> v >> a >> f >> p;
    vector<int> contas = {a,f,p};
    sort(contas.begin(), contas.end());
    int soma = 0, contador = 0;
    for(int i = 0; i<3; i++){
        if(soma + contas[i] > v) break;
        soma += contas[i];
        contador++;
    }
    cout << contador;
}