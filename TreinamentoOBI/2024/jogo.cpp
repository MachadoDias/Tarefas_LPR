//Complexidade de tempo O(Q*n²)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    //entra com o tamanho da matriz e número de passos
    vector<string> matriz;  
    for(int i = 0; i<n; i++){
        string input; cin >> input;
        matriz.push_back(input);
    }
    //preenche a matriz
    vector<string> out = matriz; 
    //cria uma matriz auxiliar
    for(int passos = 0; passos<q; passos++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                //percorre a matriz
                int vVivos = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        //loop para checar todas as casas adjacentes
                        if (dx == 0 && dy == 0) continue;
                        //ignora a casa sendo verificada
                        int ni = i + dx, nj = j + dy;
                        //posicao do vizinho
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && matriz[ni][nj] == '1')
                        vVivos++;
                        //verifica se está em uma casa válida, se estiver e o vizinho estiver vivo atualiza o contador
                    }
                }
                if(matriz[i][j] == '1' && (vVivos == 2 || vVivos == 3)) out[i][j] = '1';
                else if(matriz[i][j] == '1') out[i][j] = '0';
                else if(matriz[i][j] == '0' && vVivos == 3) out[i][j] = '1';
                //condicionais para verificar se a casa fica viva ou morta
            }
        }
        matriz = out;
        //copia a matriz ao fim de cada iteração
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << out[i][j];
        }
        cout << endl;
    }
}