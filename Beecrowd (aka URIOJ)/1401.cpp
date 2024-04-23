/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1401
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        sort(s.begin(), s.end());
        do{
            for(const char &c : s)
                cout << c;
            cout << "\n";
        } while(next_permutation(s.begin(), s.end()));
        cout << "\n";
    }
    return 0;
}