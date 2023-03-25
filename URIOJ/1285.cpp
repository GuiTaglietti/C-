/*

    Gui Taglietti - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1285

*/

#include <bits/stdc++.h>
using namespace std;

bool repeat(string num){
    for (int i = 0; i < num.size() - 1; i++) {
        for (int j = i + 1; j < num.size(); j++) {
            if (num[i] == num[j]) {
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n1, n2, ans = 0;
    while(cin >> n1 >> n2){
        for(int i = n1; i < n2 + 1; i++){
            if(!repeat(to_string(i))) ans++;
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
