/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1034
*/
#include <bits/stdc++.h>
using namespace std;

#define INF (static_cast<int>(1e9))

#define MAXN 30
#define MAXM 1010101

int N, M, dp[MAXM], blck[MAXN];

[[nodiscard]] inline int min(int a, int b) noexcept{ 
    return a < b ? a : b; 
}

[[nodiscard]] int knapsack(int M) noexcept{
    if(M < 0) 
        return INF;
    if(!M) 
        return 0;
    if(dp[M] != -1)
        return dp[M];
    int ans = INF;
    for(int i = 0; i < N; i++)
        ans = min(ans, 1 + knapsack(M - blck[i]));
    return dp[M] = ans;
}

int main(){
    ios::ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> N >> M;
        for(int i = 0; i < N; i++)
            cin >> blck[i];
        memset(dp, -1, sizeof dp);
        cout << knapsack(M) << "\n";
    }
    return 0;
}