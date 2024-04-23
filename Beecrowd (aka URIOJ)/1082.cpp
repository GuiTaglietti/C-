/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1082
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int UF[27];

[[nodiscard]] inline int findset(int x) noexcept{
    return (UF[x] == x) ? x : UF[x] = findset(UF[x]);
}

void unionset(int x, int y){
    if(findset(x) > findset(y)) 
        UF[findset(x)] = findset(y);
    else 
        UF[findset(y)] = findset(x);
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        int v, e;
        cin >> v >> e;
        for(int j = 0; j < v; j++)
            UF[j] = j;
        char c1, c2;
        for(int i = 0; i < e; i++){
            cin >> c1 >> c2;
            unionset(c1 - 'a', c2 - 'a');
        }
        map<int, vi> con;
        for(int j = 0; j < v; j++)
            con[findset(j)].push_back(j);
        cout << "Case #" << i << ":" << "\n";
        for(const auto &c : con){
            for(const auto &ep : c.second)
                cout << static_cast<char>('a' + ep) << ",";
            cout << "\n";
        }
        cout << con.size() << " connected components" << "\n" << "\n";
    }
    return 0;
}