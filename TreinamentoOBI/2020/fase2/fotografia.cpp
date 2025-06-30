#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, l; cin >> a >> l;
    int area = a * l;
    int n; cin >> n;
    vector<pair<int, int>> molduras;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        molduras.push_back({x,y});
    }
    int melhor = -1;
    int ultimaDiferenca = INT32_MIN;
    for(int i = 0; i<n; i++){
        if((a>molduras[i].first || l>molduras[i].second) && (a>molduras[i].second || l>molduras[i].first)) continue;
        int areaMoldura = molduras[i].first*molduras[i].second;
        if(area - areaMoldura > ultimaDiferenca) {
            melhor = i+1;
            ultimaDiferenca = area - areaMoldura;
        }
    }
    cout << melhor << endl;
}