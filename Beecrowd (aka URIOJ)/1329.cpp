/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1329
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n && n){
        int j, m, w; j = m = 0;
        for(int i = 0; i < n; i++){
            cin >> w;
            !w ? m++ : j++;
        }
        cout << "Mary won " << m << " times and John won " << j << " times\n";
    }
    return 0;   
}