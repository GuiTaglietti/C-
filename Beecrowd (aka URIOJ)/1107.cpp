/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1107
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int m, n;
	while(cin >> n >> m && n && m){
        int ans[m];
        ll k = 0;
        for(int i = 0; i < m; i++){
            cin >> ans[i];
            if(i){
                if(ans[i - 1] > ans[i]) 
                    k += ans[i - 1] - ans[i];
            }
            else 
                k += n - ans[i];
        }
        cout << k << endl;
    }
    return 0;
}
