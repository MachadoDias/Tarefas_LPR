#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, p, m;
    vector<int> t;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        t.push_back(x);
    }
    cin >> p >> m;
    for(int x : t){
        if(x == 1) p--;
        else m--;
    }
    if(p<0 || m <0) cout << "N" << endl;
    else cout << "S" << endl;
}