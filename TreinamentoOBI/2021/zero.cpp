#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    stack<int> numeros;
    cin >> n;
    for(int i = 0; i<n; i++){
        int t;
        cin >> t;
        if(t == 0) numeros.pop();
        else numeros.push(t);
    }
    int out = 0;
    while(numeros.size() > 0){
        out+=numeros.top();
        numeros.pop();
    }
    cout << out << endl;
}