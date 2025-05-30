#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> lista;
    vector<uint8_t> posicoes;
    int numeroBuscado;
    cout << "Digite 10 números inteiros:\n";
    for(int i = 0; i < 10; i++){
        int temp;
        cin >> temp;
        lista.push_back(temp);
    }
    cout << "Digite o número que deseja buscar: ";
    cin >> numeroBuscado;
    for(int j = 0; j < 10; j++){
        if(lista[j] == numeroBuscado) posicoes.push_back(j); 
    }
    if(posicoes.size() == 0){
        cout << "O numero nao esta na lista" << endl;
        return 0;
    }
    cout << "Numero de ocorrencias: " << posicoes.size() << "\nPosicoes: ";
    for(int n : posicoes) cout << n << " ";
    return 0;
}