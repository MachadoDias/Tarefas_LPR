#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> notas(n);
    for(int &x : notas) cin >> x;
    sort(notas.rbegin(), notas.rend());
    while(notas.size() > k){
        notas.pop_back();
    }
    cout << notas.back() << endl;
}