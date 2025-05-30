#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> input, numerosPares, numerosImpares;
    cout << "Digite os 10 números inteiros:\n";
    for(int i = 0; i < 10; i++){
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    for(int j = 0; j < input.size(); j++){
        if(input[j]%2 == 0) numerosPares.push_back(input[j]);
        else numerosImpares.push_back(input[j]);
    }
    cout << "PAR: ";
    for(int num : numerosPares) cout << num << " ";
    cout << "\nIMPAR: ";
    for(int num : numerosImpares) cout << num << " ";
}