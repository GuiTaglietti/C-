#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9;
const int N = 5;

vector<int> dist;
vector<ii> adj[N];

void queueBFS(int v){
    dist.assign(N, INF);
    queue<int> buffer;
    buffer.push(v);
    dist[v] = 0;
    while(!buffer.empty()){
        int aux = buffer.front();
        buffer.pop();
        cout << aux << endl;
        for(auto child : adj[aux]){
            if(dist[child.first] == INF){
                dist[child.first] += 1;
                buffer.push(child.first);
            }
        }
    }
}

int main(){
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 1});
    adj[1].push_back({0, 2});
    adj[1].push_back({3, 3});
    adj[3].push_back({1, 3});
    adj[1].push_back({4, 2});
    cout << "BFS usando fila:" << endl;
    queueBFS(0);
    return 0;
}
