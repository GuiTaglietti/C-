/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/2400
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int ft[MAX];

void update(int k, int v) noexcept{
    while(k < MAX){
        ft[k] += v;
        k += (k & (-k));
    }
}

[[nodiscard]] int rsq(int b) noexcept{
    int sum = 0;
    while(b > 0){
        sum += ft[b];
        b -= (b & (-b));
    }
    return sum;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, ans = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ans += i - rsq(arr[i]);
        update(arr[i], 1);
    }
    cout << ans << "\n";
    return 0;
}
