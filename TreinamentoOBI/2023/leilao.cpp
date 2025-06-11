#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int maiorLance = -1;
    string ganhador;
    for(int i = 0; i<n; i++){
        string nome; cin >> nome;
        int lance; cin >> lance;
        if(maiorLance < lance){
            maiorLance = lance;
            ganhador = nome;
        }
    }
    cout << ganhador << endl << maiorLance << endl;
}