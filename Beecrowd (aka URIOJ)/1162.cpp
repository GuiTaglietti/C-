/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1162
*/
#include <bits/stdc++.h>
using namespace std;

[[nodiscard]] int solve(int arr[], int sz){
    int ans = 0;
    bool f;
    for(int i = 0; i < sz; i++){
        f = false;
        for(int j = 0; j < sz - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                f = true;
                ans++;
            }
        }
        if(!f)
            break;   
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int nv; cin >> nv;
        int arr[nv];
        for(int i = 0; i < nv; i++)
            cin >> arr[i];
        cout << "Optimal train swapping takes " << solve(arr ,nv) << " swaps.\n";
    }
    return 0;
}
