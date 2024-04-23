/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1281
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int N, Q, qp;
        float ans = 0;
        string p;
        unordered_map<string, float> mp;
        cin >> N;
        for(int i = 0; i < N; i++){
            float v;
            cin >> p >> v;
            mp[p] = v;
        }
        cin >> Q;
        for(int i = 0; i < Q; i++){
            cin >> p >> qp;
            ans += mp[p] * qp;
        }
        cout << fixed << setprecision(2) << "R$ " << ans << "\n";
    }
    return 0;
}