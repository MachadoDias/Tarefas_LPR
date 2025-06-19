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
    // Preenche a variável que armazena os registros
    map<int,int> pendente, total;
    // Um mapa que armazena o amigo que está esperando uma resposta e outro que armazena quando os amigos receberam a resposta
    // no formato {amigo, tempo}
    int tempoAtual = 0;
    // Variável para simular o tempo passado
    set<int> erro;
    // Set com os amigos que não receberam resposta 
    bool ok = 0;
    // Variável para atualizar o tempo entre um registro e outro
    for(pair<char, int> registro : registros){
        if(registro.first == 'T'){
            tempoAtual += registro.second;
            ok = 0;
        }
        // Se for um registro do tipo T atualiza o tempo atual
        else if(registro.first == 'R'){
            tempoAtual += ok; ok = 1;
            pendente[registro.second] = tempoAtual;
            erro.insert(registro.second);
            total[registro.second];
        }
        // Se for do tipo R, atualiza o tempo atual, indica que 1 segundo deve se passar até o próximo registro
        // adiciona o amigo na lista de amigos pendentes e na de erro, instancia o amigo no mapa total
        else{
            tempoAtual += ok; ok = 1;
            erro.erase(registro.second);
            total[registro.second] += tempoAtual - pendente[registro.second];
            // Se for do tipo E, atualiza o tempo atual, retira o amigo da lista de erro, marca o tempo de resposta desse amigo
        }
    }
    for(auto x : total){
        if(erro.count(x.first)){
            cout << x.first << " " << -1 << endl;
        }
        // Se o amigo estiver na lista de erro, printa -1 para o tempo de resposta
        else{
            cout << x.first << " " << x.second << endl;
        }
        // Senão, printa o tempo de resposta armazenado
    }
}