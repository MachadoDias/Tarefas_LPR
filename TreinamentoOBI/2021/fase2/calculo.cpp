#include <bits/stdc++.h>
using namespace std;
int soma(int n){
    int sum = 0;
    while (n!=0)
    {
     sum += n%10;
     n/=10;   
    }
    return sum;
}
int main(){
    int s, a, b; cin >> s >> a >> b;
    int contador = 0;
    for(int i = a; i <= b; i++){
        if(soma(i) == s) contador++;
    }
    cout << contador;
}