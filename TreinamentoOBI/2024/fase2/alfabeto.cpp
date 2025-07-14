#include <bits/stdc++.h>
using namespace std;
int main(){
    int k, n; cin >> k >> n;
    set<char> alfabeto, mensagem;
    for(int i = 0; i < k; i++){
        char a; cin >> a; alfabeto.insert(a); 
    }
    for(int i = 0; i < n; i++){
        char a; cin >> a; mensagem.insert(a); 
    }
    for(char x : mensagem){
        if(!alfabeto.count(x)){
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
}