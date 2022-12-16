/*

    Gui Taglietti - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1581

*/

#include <bits/stdc++.h>
using namespace std;

string solve(int num){
    string lang[num];
    int ans = 0;
    for(int i = 0; i < num; i++){
        cin >> lang[i];
        if(lang[0] != lang[i]) ans++;
    }
    return (ans != 0 ? "ingles" : lang[0]);
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
