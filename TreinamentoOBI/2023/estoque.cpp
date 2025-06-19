#include <bits/stdc++.h>
using namespace std;
int main(){
    int rows, cols; cin >> rows >> cols;
    // Leitura das dimensões
    vector<vector<int>> estoque(rows, vector<int>(cols));
    // Matriz para o estoque inicial
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
            efetivados++; // Confirma o pedido
            estoque[row-1][col-1]--; // Atualiza o estoque
        }
        // Verifica se há estoque para o produto solicitado
    }
    cout << efetivados << endl;
}