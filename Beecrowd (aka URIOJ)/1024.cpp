/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1024
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    while(cin >> t){
        cin.ignore();
        while(t--){
            string s;
            getline(cin, s);
            int sz = s.length();
            for(int i = 0; i < sz; i++){
                if(isalpha(s[i])){
                    int pos = s[i] + 3;
                    s[i] = static_cast<char>(pos);
                }
            }
            reverse(s.begin(), s.end());
            int mid = sz / 2;
            for(int i = mid; i < sz; i++){
                int pos = s[i] - 1;
                s[i] = static_cast<char>(pos);
            }
            cout << s << "\n";
        }
    }
    return 0;
}