//incompleto
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int infectado, r;
    cin >> infectado >> r;
    vector<vector<int>> amigos;
    vector<int> q;
    for(int i = 0; i<m; i++){
        vector<int> x;
        int y; cin >> y; q.push_back(y);
        for(int j = 0; j<q[i]; j++){
            int temp; cin >> temp; x.push_back(temp);
        }
        amigos.push_back(x);
    }
    set<int> infectados, presentes;
    infectados.insert(infectado);
    for(int i = r -1; i<m; i++){
        for(int j = 0; j < amigos[i].size(); j++){
            presentes.insert(amigos[i][j]);
        }
    }
    for(int i = r -1; i<m; i++){
        for(int j = 0; j < amigos[i].size(); j++){
            set<int> temp = infectados;
            for(auto x : temp){
                 if(presentes.count(x)) infectados.insert(amigos[i][j]);
            }
        }
    }
    cout << infectados.size() << endl;
}