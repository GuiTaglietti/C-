/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1445
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

class UnionFind{
public:
    UnionFind(int n){
        p.assign(n, 0); 
        rank.assign(n, 0);
        for(int i = 0; i < n; i++)
            p[i] = i;
    }

    inline int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    
    inline bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) 
                p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y]) 
                    rank[y]++;
            }
        }
    }

private: 
    vector<int> p, rank;
};

inline ii eval(string &str){
    return ii(atoi(&str[1]), atoi(&str[3]));
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    while(cin >> N && N){
        int ans = 0;
        UnionFind UF(N + 1);
        string str;
        for(int i = 0; i < N; i++){
            cin >> str;
            ii p = eval(str);
            if(!UF.isSameSet(p.first, p.second)) 
                UF.unionSet(p.first, p.second);
        }
        int set = UF.findSet(1);
        for(int i = 1; i < N + 1; i++)
            if(set == UF.findSet(i)) 
                ans++;
        cout << ans << "\n";
    }
    return 0;
}