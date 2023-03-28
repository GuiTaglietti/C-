#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9;
const int N = 5;

vector<bool> visited;
vector<int> dist;
vector<ii> adj[N];

void recursiveDFS(int v){
    visited[v] = true;
    cout << v << endl;
    for(auto child : adj[v]){
        if(!visited[child.first]){
            recursiveDFS(child.first);
        }
    }
}

void stackDFS(int v){
    dist.assign(N, INF);
    stack<int> buffer;
    buffer.push(v);
    dist[v] = 0;
    while(!buffer.empty()){
        int aux = buffer.top();
        buffer.pop();
        cout << aux << endl;
        for(auto child : adj[aux]){
            if(dist[child.first] == INF){
                dist[child.first] = dist[aux] + 1;
                buffer.push(child.first);
            }
        }
    }
}

int main(){
    visited.assign(N, false);
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 1});
    adj[1].push_back({0, 2});
    adj[1].push_back({3, 3});
    adj[3].push_back({1, 3});
    adj[1].push_back({4, 2});
    cout << "DFS recursiva:" << endl;
    recursiveDFS(0);
    cout << endl;
    cout << "DFS usando pilha:" << endl;
    stackDFS(0);
    cout << endl;
    return 0;
}
