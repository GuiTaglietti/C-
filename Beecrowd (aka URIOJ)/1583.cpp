/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1583
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 52

typedef pair<int, int> ii;

char LG[MAX][MAX];
bool vis[MAX][MAX];
int N, M;

const int di[] = {-1, 0, 0, +1};
const int dj[] = {0, -1, +1, 0};

[[nodiscard]] inline bool is_valid(int i, int j) noexcept{
    return 0 <= i && i < N && 0 <= j && j < M;
}

void floodfill(int si, int sj){
    if(!is_valid(si, sj) || LG[si][sj] == 'X' || vis[si][sj]) return;
    vis[si][sj] = true;
    LG[si][sj] = 'T';
    for(int i = 0; i < 4; i++)
        floodfill(si + di[i], sj + dj[i]);
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(cin >> N >> M && N && M){
        cin.ignore();
        for(int i = 0; i < N; i++){
            string str; getline(cin, str);
            for(int j = 0; j < M; j++)
                LG[i][j] = str[j];
        }
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(LG[i][j] == 'T') 
                    floodfill(i, j);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++)
                cout << LG[i][j];
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}