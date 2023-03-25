/*
    Gui Taglietti - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1076
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int shots, ans = 0;
        cin >> shots;
        int alt[shots];
        char jmps[shots];
        for(int i = 0; i < shots; i++){
            cin >> alt[i];
        }
        for(int i = 0; i < shots; i++){
            cin >> jmps[i];
        }
        for(int i = 0; i < shots; i++){
            if(alt[i] > 2 && jmps[i] == 'J') ans++;
            if(alt[i] <= 2 && jmps[i] == 'S') ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
