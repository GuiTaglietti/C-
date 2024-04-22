/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1234
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    while(getline(cin, s)){
        bool up = true;
        for(auto c : s){
            if(!isalpha(c))
                cout << static_cast<char>(c);
            else{
                if(up) cout << static_cast<char>(toupper(c));
                else cout << static_cast<char>(tolower(c));
                up ^= 1;
            }
        }
        cout << "\n";
    }
    return 0;
}