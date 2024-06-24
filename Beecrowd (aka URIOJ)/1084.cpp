/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1084
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, d;
    while(cin >> n >> d && n && d){
        string s, ans = ""; cin >> s;
        for(size_t i = 0; i < s.length(); i++){
            while(!ans.empty() && d > 0 && ans.back() < s[i]){
                ans.pop_back();
                d--;
            }
            ans.push_back(s[i]);
        }
        while(!ans.empty() && d > 0){
            ans.pop_back();
            d--;
        } 
        cout << ans << "\n";
    }
    return 0;
}