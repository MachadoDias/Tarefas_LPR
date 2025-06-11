#include <bits/stdc++.h>
using namespace std;
int main(){
    int rows, cols; cin >> rows >> cols;
    vector<vector<int>> estoque(rows, vector<int>(cols));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin >> estoque[i][j];
        }
    }
    int nPedidos; cin >> nPedidos;
    int efetivados = 0;
    for(int i = 0; i<nPedidos; i++){
        int row, col; cin >> row >> col;
        if(estoque[row-1][col-1] > 0){
            efetivados++;
            estoque[row-1][col-1]--;
        }
    }
    cout << efetivados << endl;
}