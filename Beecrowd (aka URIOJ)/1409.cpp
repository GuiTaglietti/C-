/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1409
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
#define INF 1e9

typedef pair<int, int> ii;

int mana[MAX], dmg[MAX], lwr[MAX], LG[MAX][MAX], dist[MAX], M, N;

void dijkstra(){
	memset(dist, INF, sizeof dist);
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0, 0});
	dist[0] = 0;
	while(!pq.empty()){
		int u = pq.top().second; pq.pop();
		for(int i = 1; i <= N; i++){
			if(LG[u][i] < INF && dist[i] > dist[u] + LG[u][i]){
				dist[i] = dist[u] + LG[u][i];
				pq.push({dist[i], i});
			}
		}
	}
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int G, K;
	while(cin >> M >> N >> G >> K && (M + N + G + K)){
        for(int i = 0; i < M; i++)
			cin >> mana[i] >> dmg[i];
		lwr[0] = 0;
		for(int hp = 1; hp < MAX; hp++){
			lwr[hp] = INF;
			for(int j = 0; j < M; j++){
				int rmn = hp - dmg[j] > 0 ? hp - dmg[j] : 0;
				lwr[hp] = min(lwr[hp], lwr[rmn] + mana[j]);
			}
		}
		memset(LG, INF, sizeof LG);
		LG[0][1] = 0;
		int u, v;
		for(int i = 0; i < G; i++){
			cin >> u >> v;
			LG[u][v] = LG[v][u] = 0;
		}
		int s, lp;
		while(K--){
			cin >> s >> lp;
			for(int j = 0; j <= N; j++)
				if(LG[j][s] < INF) 
                    LG[j][s] += lwr[lp];
		}
		dijkstra();
        cout << (dist[N] != INF ? dist[N] : -1) << "\n";
	}
	return 0;
}
