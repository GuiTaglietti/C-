/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1665
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, double> id;
typedef vector<id> vid;

int V, E;
vector<vid> LG;
vector<bool> visited;

[[nodiscard]] int prim(int s){
    double cost = 1.0; 
    visited.assign(V + 1, false);
    priority_queue<id, vector<id>, greater<id>> Q;
    Q.push(id(1, 0));
    while(!Q.empty()){
        int u = Q.top().second, peso = Q.top().first;
        Q.pop();
        if(!visited[u]){
            visited[u] = true;
            cost *= u;
            for(const auto &v : LG[u])
                Q.push(id(v.first, v.second));
        }
    }
    return cost * 100.0;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(cin >> V && V){
        int src, dest; 
        double w;
        cin >> E;
        LG.assign(V + 1, vid());
        for(int i = 0; i < E; i++){
            cin >> src >> dest >> w;
            LG[src].push_back(id(dest, w / 100.0));
            LG[dest].push_back(id(src, w / 100.0));
        }
        cout << fixed << setprecision(6) << prim(1) << " percent" << endl;
    }
    return 0;
}