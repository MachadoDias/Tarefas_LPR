//incompleto
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500
int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};
void bfs(char mapa[][MAXN], bool vis[][MAXN], int row, int col, int n)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = true;
    while (!q.empty())
    {
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
            if (isValid(vis, adjx, adjy, n))
            {
                q.push({adjx, adjy});
                vis[adjx][adjy] = true;
            }
        }
    }
}
bool isValid(bool vis[][MAXN],int row, int col, int n)
{
    if (row < 0 || col < 0 || row >= n || col >= n) return false;
    if (vis[row][col]) return false;
    return true;
}
int main()
{
    int n, f;
    cin >> n >> f;
    string mapa[n];
    for (int i = 0; i < n; i++)
    {
        cin >> mapa[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}