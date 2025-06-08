#include <bits/stdc++.h>
using namespace std;
int main(){
    int nRegistros;
    vector<pair<char, int>> registros;
    cin >> nRegistros;
    for(int i = 0; i < nRegistros; i++){
        pair<char, int> buffer;
        cin >> buffer.first >> buffer.second;
        registros.push_back(buffer);
    }
    map<int,int> pendente, total;
    int tempoAtual = 0;
    set<int> erro;
    bool ok = 0;
    for(pair<char, int> registro : registros){
        if(registro.first == 'T'){
            tempoAtual += registro.second;
            ok = 0;
        }
        else if(registro.first == 'R'){
            tempoAtual += ok; ok = 1;
            pendente[registro.second] = tempoAtual;
            erro.insert(registro.second);
            total[registro.second];
        }
        else{
            tempoAtual += ok; ok = 1;
            erro.erase(registro.second);
            total[registro.second] += tempoAtual - pendente[registro.second];
        }
    }
    for(auto x : total){
        if(erro.count(x.first)){
            cout << x.first << " " << -1 << endl;
        }
        else{
            cout << x.first << " " << x.second << endl;
        }
    }
}