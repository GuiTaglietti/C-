#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 5;

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> arestas;

void showFirst(int grafo[N][N]){
    cout << "Grafo:" << endl;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(grafo[i][j] != INF)
                cout << "Linha " << i 
                << " coluna " << j << " possui o peso: " 
                << grafo[i][j] << endl << endl; 
}

void showSecond(vector<ii> grafo[N]){
    cout << "Grafo:" << endl;
    for(int i = 0; i < N; i++){
        for(auto e : grafo[i]){
            cout << "Vértice " << i << " liga com o vértice " 
            << e.first << " com peso " << e.second << endl;
        }
    }
    cout << endl;
}

void showThird(vector<arestas> grafo){
    cout << "Grafo:" << endl;
    for(auto e : grafo){
        cout << "Vértice " << e.second.first 
        << " chega no vértice " << e.second.second
        << " com peso " << e.first << endl;
    }
}

int main(){
    // Primeiro método de representação: matriz de adjacências
    
    int adj[N][N];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            adj[i][j] = INF;

    adj[0][1] = 2;
    adj[1][0] = 2;
    adj[0][2] = 1;
    adj[1][3] = 3;
    adj[3][1] = 3;
    adj[3][4] = 2;
    showFirst(adj);

    // Segundo método de representação: lista de adjacências

    vector<ii> adjList[N];
    adjList[0].push_back({1, 2});
    adjList[0].push_back({2, 1});
    adjList[1].push_back({0, 2});
    adjList[1].push_back({3, 3});
    adjList[3].push_back({1, 3});
    adjList[1].push_back({4, 2});
    showSecond(adjList);

    // Terceiro método de representação: vector de arestas

    vector<arestas> adjVector;
    adjVector.push_back({2, {0, 1}});
    adjVector.push_back({2, {1, 0}});
    adjVector.push_back({2, {3, 4}});
    adjVector.push_back({1, {0, 2}});
    adjVector.push_back({3, {1, 3}});
    adjVector.push_back({3, {3, 1}});
    showThird(adjVector);

    return 0;
}
