/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1520
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n;
    while(cin >> t){
        vector<int> ans;
        while(t--){
            int st, end;
            cin >> st >> end;
            for(; st <= end; st++)
                ans.push_back(st);
        }
        sort(ans.begin(), ans.end());
        cin >> n;
        uint f = count(ans.begin(), ans.end(), n);
        if(!f) cout << n << " not found\n";
        else{
            int idx = distance(ans.begin(), find(ans.begin(), ans.end(), n));
            cout << n << " found from " << idx << " to " << (idx + f) - 1 << "\n";
        }
    }
    return 0;
}