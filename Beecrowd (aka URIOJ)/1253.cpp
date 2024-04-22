/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1253
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    uint t, jmps; cin >> t;
    while(t--){
        cin >> s >> jmps;
        for(size_t i = 0; i < s.length(); i++){
            if((s[i] - jmps) < 65) 
                s[i] = (s[i] - jmps) + 26; 
            else 
                s[i] -= jmps;
        }
        cout << s << "\n";
    }
    return 0;
}