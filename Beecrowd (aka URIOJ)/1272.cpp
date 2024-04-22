/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1272
*/
#include <bits/stdc++.h>
using namespace std;

// [[nodiscard]] inline bool is_valid(const string &s, int pos) noexcept{
//     return (s[pos + 1] != '·') && pos > 0 && pos < static_cast<int>(s.length());
// }

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    uint t; cin >> t;
    string s, ans = "";
    while(t--){
        bool found = false, add = true;
        cin >> s;
        for(size_t i = 0; i < s.length(); i++){
            if(s[i] != '·' && add){
                found = true; add = false;
                ans += s[i];
            }
            else if(s[i] == '·' && found){
                add = true; found = false;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
