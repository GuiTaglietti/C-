#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9;
const int N = 5;

vector<bool> visited;
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

/*
void stackDFS(int v){
    stack<int> buffer;
    buffer.push(v);
    while(!buffer.empty()){
        int top = buffer.top();
        buffer.pop();
        cout << top << endl;
        visited[top] = true;
        for(auto child : adj[top]){
            if(!visited[child.first]){
                buffer.push(child.first);
            }
        }
    }
}
*/

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
    return 0;
}
