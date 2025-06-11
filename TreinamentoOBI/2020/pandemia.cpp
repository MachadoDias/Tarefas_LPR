// Complexidade de tempo O(P*log(n)) sendo P a quantidade total de participantes
// Pior caso: O(n*m*log(n))
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int infectado, r;
    cin >> infectado >> r;
    vector<vector<int>> amigos;
    for(int i = 0; i<m; i++){
        vector<int> x;
        int y; cin >> y;
        for(int j = 0; j<y; j++){
            int temp; cin >> temp; x.push_back(temp);
        }
        amigos.push_back(x);
    }
    // Armazena os amigos que participaram de cada reunião
    set<int> infectados;
    // Cria um set para armazenar os infectados
    infectados.insert(infectado);
    bool contaminou = false;
    // Variável para armazenar se amigo infectado estava na reunião
    for(int i = r -1; i<m; i++){
        for(int j = 0; j < amigos[i].size(); j++){
            if(infectados.count(amigos[i][j])) contaminou = true;
        }
        if(contaminou){
            for(int j = 0; j < amigos[i].size(); j++){
                infectados.insert(amigos[i][j]);
            }
        }
        // Verifica se um infectado estava na reunião, se sim, infecta todos amigos 
        contaminou = false;
    }
    cout << infectados.size() << endl;
}