/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1566
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> vi(n);
        for(int i = 0; i < n; i++)
            cin >> vi[i];
        sort(vi.begin(), vi.end());
        cout << vi[0];
        for(int i = 1; i < n; i++)
            cout << " " << vi[i];
        cout << "\n";
    }
    return 0;
}