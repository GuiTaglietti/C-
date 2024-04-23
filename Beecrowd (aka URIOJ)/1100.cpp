/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1100
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 8; 

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

[[nodiscard]] int BFS(const string &from, const string &to){
    queue<string> q;
    map<string, int> dist;
    q.push(from);
    dist[from] = 0;
    while(!q.empty()){
        string curr = q.front();
        q.pop();
        if(curr == to) 
            return dist[curr];
        int x = curr[0] - 'a', y = curr[1] - '1';
        for(int i = 0; i < N; ++i){
            int newX = x + dx[i], newY = y + dy[i];
            if(newX >= 0 && newX < N && newY >= 0 && newY < N){
                string next = string(1, 'a' + newX) + string(1, '1' + newY);
                if(dist.find(next) == dist.end()){
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string from, to;
    while(cin >> from >> to)
        cout << "To get from " << from << " to " << to << " takes " << BFS(from, to) << " knight moves." << endl;
    return 0;
}
