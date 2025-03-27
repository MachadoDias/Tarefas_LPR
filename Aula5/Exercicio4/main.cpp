#include <iostream>
using namespace std;

int SumDigits(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(){
    int number;
    cout << "Digite o número: ";
    cin>>number;
    number *= number;
    cout << SumDigits(number) << endl;
    return 0;
}