/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1252
*/
#include <bits/stdc++.h>
using namespace std;

#define INF ((int)1e9)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int N, M, Q;
vector<vii> LG;
vi dist;

void dijkstra(){
    dist.assign(N, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int s;
    for(int i = 0; i < Q; i++){
        cin >> s;
        s--;
        dist[s] = 0;
        pq.push(ii(0, s));
    }
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        for(auto e : LG[u]){
            int v = e.first, w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
            }
        }
    }

}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin >> N >> M >> Q){
        LG.assign(N, vii());
        int u, v, w;
        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;
            u--, v--;
            LG[u].push_back(ii(v, w));
            LG[v].push_back(ii(u, w));
        }
        dijkstra();
        int ans = 0;
        for(int i = 0; i < N; i++)
            ans = max(ans, dist[i]);
        cout << ans << "\n";
    }
    return 0;
}