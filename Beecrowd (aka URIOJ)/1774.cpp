/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1774
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int V, E;
vector<vii> LG;
vector<bool> visited;

[[nodiscard]] int prim(int s){
    int ans = 0; 
    visited.assign(V, false);
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push(ii(0, s));
    while(!Q.empty()){
        int u = Q.top().second, peso = Q.top().first;
        Q.pop();
        if(!visited[u]){
            visited[u] = true;
            ans += peso;
            for(const auto &v : LG[u])
                Q.push(ii(v.second, v.first));
        }
    }
    return ans;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    int u, v, w;
    LG.assign(V, vii());
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        u--, v--;
        LG[u].push_back(ii(v, w));
        LG[v].push_back(ii(u, w));
    }
    cout << prim(0) << "\n";
    return 0;
}