#include <bits/stdc++.h>
using namespace std;
int main(){
    int i1, i2, i3;
    scanf("%d %d %d", &i1, &i2, &i3);
    // Declara e recebe as idades
    if(i1 >= min(i2, i3) && i1 <= max(i2, i3)) cout << i1 <<endl;
    // i1 é a idade do meio
    else if(i2 >= min(i1, i3) && i2 <= max(i1, i3)) cout << i2 <<endl;
    // i2 é a idade do meio
    else cout << i3;
    // i3 é a idade do meio
}