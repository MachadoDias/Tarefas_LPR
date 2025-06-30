#include <bits/stdc++.h>
using namespace std;
int main(){
    int d;
    cin >> d;
    d -= 5;
    //desconsidera a distância entre o emissor e o acelerador (3) e entre o acelerador e sensores (2)
    cout << d%8 << endl;
    //considerando que o círculo tem 8km de circunferência essa operação retorna qual sensor foi atingido
}