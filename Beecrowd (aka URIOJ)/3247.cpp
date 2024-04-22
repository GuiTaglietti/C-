/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/3247
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

typedef pair<int, int> ii;

char LG[MAX][MAX];
bool vis[MAX][MAX];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int V;

inline bool is_valid(int x, int y) noexcept{
    return (x >= 0 && x < V && y >= 0 && y < V && !vis[x][y] && LG[x][y] != '#');
}

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    vis[sx][sy] = true;
    q.push(ii(sx, sy));
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        for(int i = 0; i < 2; i++){
            int nx = currX + dx[i];
            int ny = currY + dy[i];
            if(is_valid(nx, ny)){
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> V;
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            cin >> LG[i][j];
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(!vis[i][j])
                bfs(i, j);
    return 0;
}