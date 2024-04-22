/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1790
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define MAX 55

vector<vi> LG;
int vis[MAX], parent[MAX], low[MAX], disc[MAX];
int V, E, ans, temp;

void findbridge(int u){
    vis[u] = true;
    disc[u] = low[u] = temp++;
    for(size_t i = 0; i < LG[u].size(); i++){
        int v = LG[u][i];
        if(!vis[v]){
            parent[v] = u;
            findbridge(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u])
              ans++;
        }
        else if(v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

void bridge(int V) noexcept{
    for(int i = 0; i < V; i++){
        parent[i] = -1;
        vis[i] = false;
    }
    for(int i = 0; i < V; i++)
        if(vis[i] == false)
            findbridge(i);
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, y;
    // LG.assign(V, vi());
    while(cin >> V >> E){
        for(int i = 0; i < V; i++) 
            LG[i].clear();
        ans = 0;
        temp = 0;
        for(int i = 0; i < E; i++){
            cin >> x >> y;
            x--; y--;
            LG[x].push_back(y);
            LG[y].push_back(x);
        }
        bridge(V);
        cout << ans << endl;
    }
    return 0;
}