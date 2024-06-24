/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/2919
*/
#include <bits/stdc++.h>
using namespace std;

[[nodiscard]] int LIS(int v[], int n) noexcept{
    int tail[n], ans = 1;
    for(int i = 0; i < n; i++) 
        tail[i] = 0;
    tail[0] = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] > tail[ans - 1])
            tail[ans++] = v[i];
        else{
            auto it = find(tail, tail + ans, v[i]);
            if(it != tail + ans)
                continue;
            it = upper_bound(tail, tail + ans, v[i]);
            *it = v[i];
        }
    }
    return ans;
}

int main(){
    int n;
    while(cin >> n){
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << LIS(arr, n) << "\n";
    }
    return 0;
}