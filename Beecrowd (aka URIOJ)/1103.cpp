/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1103
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int h1, m1, h2, m2;
    while(cin >> h1 >> m1 >> h2 >> m2 && (h1 || h2 || m1 || m2)){
        int ans = 0;
        if(h1 == h2 && m1 > m2) 
            ans = (24 * 60) - (m1 - m2);
        else if(h1 == h2 && m2 > m1) 
            ans = m2 - m1;
        else if(h1 <= h2) 
            ans = ((h2 - h1) * 60) + (m2 - m1);
        else 
            ans = ((24 - (h1 - h2)) * 60) + (m2 - m1);
        cout << ans << "\n";
    }
    return 0;
}