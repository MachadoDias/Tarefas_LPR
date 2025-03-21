#include <iostream>
using namespace std;
int main(){
    int A, B;
    cout << "digite o primeiro numero: ";
    cin >> A;
    cout << "digite o segundo numero: ";
    cin >> B;
    if(A%B == 0 || B%A == 0){
        cout <<"Sao Multiplos";
        return 0;
    }
    cout << "Nao sao Multiplos\n";
    return 0;
}