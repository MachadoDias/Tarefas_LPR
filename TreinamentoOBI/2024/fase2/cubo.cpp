#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int um, dois, total; total = n*n*n;
    total-=8;
    dois = um = 12*(n-2); total -= 24*(n-2);
    cout << total << endl << um << endl << dois << endl << 8 << endl;
}