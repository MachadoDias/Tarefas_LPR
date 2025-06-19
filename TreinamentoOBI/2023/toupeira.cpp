#include <bits/stdc++.h>
using namespace std;
int main(){
    int s, t; cin >> s >> t;
    vector<set<int>> mapa(s+1);
    for(int i = 0; i<t; i++){
        int x, y; cin >> x >> y;
        mapa[x].insert(y); mapa[y].insert(x);
    }
    int p; cin >> p;
    int possibilidades = 0;
    for(int i=0; i<p; i++){
        int n; cin >> n;
        vector<int> passeio(n);
        for(int j=0; j<n; j++){
            cin >> passeio[j];
        }
        bool possivel = true;
        for(int j=0; j<n - 1; j++){
            if(!mapa[passeio[j]].count(passeio[j+1])) possivel = false;
        }
        if(possivel) possibilidades++;
    }
    cout << possibilidades << endl;
}