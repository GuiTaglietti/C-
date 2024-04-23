/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1076
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int V, E;
vector<vi> LG;
vector<bool> vis;

[[nodiscard]] int DFS(const int u, int ans){
    vis[u] = true;
    for(const int &v : LG[u])
        if(!vis[v])
            ans = DFS(v, ans + 1);
    return ans;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, u, v; cin >> n >> V >> E;
        LG.assign(V, vi()); vis.assign(V, false);
        for(int i = 0; i < E; i++){
            cin >> u >> v;
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        cout << DFS(n, 0) * 2 << "\n";
    }
    return 0;
}