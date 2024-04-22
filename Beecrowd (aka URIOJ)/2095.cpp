/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/2095
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

typedef long long int lli;

lli nlog[MAX], qdd[MAX];

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, ans = 0; cin >> t;
    for(int i = 0; i < t; i++)
        cin >> qdd[i];
    for(int i = 0; i < t; i++)
        cin >> nlog[i];
    sort(qdd, qdd + t); 
    sort(nlog, nlog + t);
    for(int i = 0, j = 0; i < t && j < t;){
        if(nlog[j] > qdd[i]){
            ans++;
            i++;
            j++;
        }
        else
            j++;
    }
    cout << ans << "\n";
    return 0;
}
