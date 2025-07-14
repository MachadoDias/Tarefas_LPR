#include <bits/stdc++.h>
using namespace std;
vector<int> rlinhas, rcolunas;
vector<unordered_set<string>> linhas, colunas;
map<string, int> resposta;
map<pair<string, int>, int> frequencias;
int l, c; 

void RemoverVariavel(string variavel){
    for(int i = 0; i<l; i++){
        linhas[i].erase(variavel);
        rlinhas[i] -= resposta[variavel] * frequencias[{variavel, i}];
    }
    for(int j = 0; j<c; j++){
        colunas[j].erase(variavel);
        rcolunas[j] -= resposta[variavel] * frequencias[{variavel, l +j}];
    }
}
int main(){
    cin >> l >> c;
    linhas.resize(l); colunas.resize(c);
    unordered_set<string> variaveis;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            string temp; cin >> temp;
            linhas[i].insert(temp);
            colunas[j].insert(temp);
            variaveis.insert(temp);
            frequencias[{temp, i}]++;
            frequencias[{temp, l+j}]++;
        }
        int temp; cin >> temp;
        rlinhas.push_back(temp);
    }
    for(int i = 0; i<c; i++){
        int temp; cin >> temp;
        rcolunas.push_back(temp);
    }
    while(resposta.size() != variaveis.size()){
        string variavelDescartada;
        for(int i = 0; i<l; i++){
            for(auto x : linhas[i]){
                if(linhas[i].size() == 1){
                    resposta[x] = rlinhas[i]/frequencias[{x, i}];
                    variavelDescartada = x;
                } 
                else continue;
            }
        }
        for(int j = 0; j<c; j++){
            for(auto x : colunas[j]){
                if(colunas[j].size() == 1){
                    resposta[x] = rcolunas[j]/frequencias[{x, l+j}];
                    variavelDescartada = x;
                }
                else continue;
            }
        }
        RemoverVariavel(variavelDescartada);
    }
    for(pair<string, int> v : resposta) cout << v.first << " " << v.second << endl;
}