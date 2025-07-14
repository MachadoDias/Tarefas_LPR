#include <bits/stdc++.h>
using namespace std;

int EncontrarTamanhoRaizAnagrama(string palavra, int n){
    for(int tamanhoSubstring = 1; tamanhoSubstring <= n/2; tamanhoSubstring++){

        if(n%tamanhoSubstring) continue;

        bool achou = true;
        string s1 = palavra.substr(0, tamanhoSubstring), s2;
        sort(s1.begin(), s1.end());

        for(int j = 1; j < n / tamanhoSubstring; j++){
            s2 = palavra.substr(j*tamanhoSubstring, tamanhoSubstring);
            sort(s2.begin(), s2.end());
            if(s1 != s2){
                achou = false;
                break;
            }
        }
        if(achou) return tamanhoSubstring;
    }
    return -1;
}

int main(){
    int n; cin >> n;
    string p; cin >> p;
    char raiz = p[0];
    int l = EncontrarTamanhoRaizAnagrama(p, n);
    cout << (l != -1 ? p.substr(0, l) : "*") << endl;
}