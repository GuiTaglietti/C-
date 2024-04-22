/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1262
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    while(cin >> s){
        int op, r = 0, w = 0; cin >> op;
        for(const char &c : s)
            c == 'R' ? r++ : w++;
        cout << ((!r ? w : op >= r ? w + 1 : (r / op) + 1 + w)) << "\n";
    }
    return 0;
}