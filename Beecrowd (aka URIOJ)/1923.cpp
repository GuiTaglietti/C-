/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1923
*/
#include <bits/stdc++.h>
using namespace std;

#define INF (static_cast<int>(1e9))

map<string, vector<string>> LG;
map<string, int> dist;

string name = "Rerisson";

void bfs(){
    queue<string> q;
    dist[name] = 0;
    q.push(name);
    while(!q.empty()){
        string u = q.front(); q.pop();
        for(auto e : LG[u]){
            if(dist[e] > dist[u] + 1){
                dist[e] = dist[u] + 1;
                q.push(e);
            }
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, G;
    while(cin >> N >> G){
        string a, b;
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            LG[a].push_back(b), LG[b].push_back(a);
            dist[a] = INF, dist[b] = INF;
        }
        bfs();
        int ans = 0;
        for(const auto &p : dist)
            if(p.first != name && p.second <= G) 
                ans++;
        cout << ans << "\n";
        for(const auto &p : dist)
            if(p.first != name && p.second <= G) 
                cout << p.first << "\n";
        LG.clear(), dist.clear();
    }
    return 0;
}