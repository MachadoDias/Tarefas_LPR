#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << "Digite a quantidade de cidades: ";
    int x; cin >> x;
    map<string, int> cidades;
    int media = 0;
    for(int i = 0; i < x; i++){
        string chave; int habitantes;
        cout << "Digite o nome da cidade " << i + 1 << ": ";
        cin >> chave;
        cout << "Digite o número de habitantes de " << chave << ": ";
        cin >> habitantes;
        media += habitantes;
        cidades[chave] = habitantes;
    }
    media /= x;
    pair<string, int> cidadeMaisPopulosa = {"", INT32_MIN}, cidadeMenosPopulosa = {"", INT32_MAX};
    for(pair<string, int> cidade : cidades){
        if(cidade.second > media) 
            cout << cidade.first << " ";
        if(cidadeMenosPopulosa.second > cidade.second) 
            cidadeMenosPopulosa = cidade;
        if(cidadeMaisPopulosa.second < cidade.second) 
            cidadeMaisPopulosa = cidade;
    }
    cout << "Cidade mais populosa: "<< cidadeMaisPopulosa.first << endl << "Cidade menos populosa: " << cidadeMenosPopulosa.first << endl;
    cout << "Digite o número de habitantes para remover cidades com esse valor: ";
    int y; cin >> y;
    auto it = cidades.begin();
    while(it != cidades.end()){
        if(it->second == y) it = cidades.erase(it);
        else it++;
    }
    for(pair<string, int> cidade : cidades){
        cout << cidade.first << " ";
    }
}
