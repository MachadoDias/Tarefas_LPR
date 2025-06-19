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
        // Se o número for 0, remove o último número que entrou na stack
        else numeros.push(t);
        // Senão, adiciona na stack
    }
    int out = 0;
    while(numeros.size() > 0){
        out+=numeros.top();
        numeros.pop();
    }
    // Calcula a soma dos números da stack
    cout << out << endl;
}