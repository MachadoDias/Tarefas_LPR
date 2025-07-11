#include <bits/stdc++.h>
using namespace std;
int main(){
    list<int> numeros(100);
    for(int &x : numeros) x = rand();
    numeros.sort();
    for(int x : numeros) cout << x << " ";
    cout << endl;
    auto it = numeros.begin();
    while(it != numeros.end()){
        if(!(*it&1)) it = numeros.erase(it);
        else it++;
    }
    for(int x : numeros) cout << x << " ";
    cout << endl;
    unordered_set<int> vistos;
    for(int x : numeros){
        if(vistos.count(x)) cout << x << " ";
        vistos.insert(x);
    }
}