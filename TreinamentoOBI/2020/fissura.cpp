// Implementação da bfs disponível em https://www.geeksforgeeks.org/breadth-first-traversal-bfs-on-a-2d-array/
// Complexidade de tempo O(n²)
#include <bits/stdc++.h>
using namespace std;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};
//Movimentação

bool isValid(vector<string> &mapa, vector<vector<bool>> &visitado,int row, int col, int n, int f)
{
    if (row < 0 || col < 0 || row >= n || col >= n) return false;
    if (visitado[row][col]) return false;
    if (mapa[row][col] - '0' > f) return false;
    return true;
}
//Verifica se está fora dos limites, se já foi visitado e se a lava pode invadir

void bfs(vector<string> &mapa, vector<vector<bool>> &visitado, int row, int col, int n, int f){
    if(mapa[row][col] - '0' <= f) mapa[row][col] = '*';
    else return;
    // Se a lava puder invadir a primeira posição altera a matriz e segue para o bfs, se não, return
    queue<pair<int, int>> q;
    q.push({row, col});
    visitado[row][col] = 1;
     while(!q.empty()){
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();
        for(int i = 0; i<4; i++){
            int adjX = x + dRow[i];
            int adjY = y + dCol[i];
            if(isValid(mapa, visitado, adjX, adjY, n, f)){
                q.push({adjX, adjY});
                visitado[adjX][adjY] = 1;
                mapa[adjX][adjY] = '*';
            }
        }
    }
}
//processa a matriz

int main()
{
    int n, f; 
    cin >> n >> f;
    vector<string>mapa(n);
    for (string &x : mapa)
    {
        cin >> x;
    }
    //preenche o mapa
    
    vector<vector<bool>> visitado(n, vector<bool>(n));
    bfs(mapa, visitado, 0, 0, n, f);
    //processa a matriz

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
    //imprime a saída
}