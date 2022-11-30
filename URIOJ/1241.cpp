/*

  Gui Taglietti - URI Online Judge solutions
  Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1241

*/

#include <bits/stdc++.h>
using namespace std;

string solve(string x, string y){
    if(x.length() >= y.length()){
        if(x.substr(x.length() - y.length(), y.length()) == y) return "encaixa";
        return "nao encaixa";
    }
    return "nao encaixa";
}

int main(){
    int t;
    string s1, s2;
    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        cout << solve(s1, s2) << endl;
    }
    return 0;
}
