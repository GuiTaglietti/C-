/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1123
*/
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F

typedef pair<int, int> ii;

map<int, vector<ii>> LG;
map<int, int> dist; 

int c, e, cr, cc; 

void dijkstra(int u){
    for(auto v : LG)
        dist[v.first] = INF;
    dist[u] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({dist[u], u});
    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();
        for(auto viz : LG[v]){
            if(dist[viz.first] > dist[v] + viz.second){
                dist[viz.first] = dist[v] + viz.second;
                pq.push({dist[viz.first], viz.first});
            }
        }
    }
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int u, v, p;
    while(cin >> c >> e >> cr >> cc && c && e && cr && cc){
        int ans = 0;
        for(int i = 0; i < e; i++){
            cin >> u >> v >> p;
            if((u > cr - 1 && v > cr - 1) || (u < cr && v < cr && abs(u - v) == 1)){
                LG[u].push_back({v, p});
                LG[v].push_back({u, p});
            }
            else if(u > cr - 1 && v < cr)
                LG[u].push_back({v, p});
            else if(v > cr - 1 && u < cr)
                LG[v].push_back({u, p});      
        }
        dijkstra(cc);
        ans = dist[cr - 1];
        cout << ans << "\n";
        LG.clear();
    }
    return 0;
}