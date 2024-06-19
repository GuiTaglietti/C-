/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1252
*/
#include <bits/stdc++.h>
using namespace std;

int m;

int main(){
    int n;
    while(cin >> n >> m && n && m){
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, [](int a, int b){
            if(b % m == a % m){
                if(abs(a) % 2 == abs(b) % 2){
                    if(a % 2 != 0)
                        return a > b;
                    return b > a;
                }
                return abs(a) % 2 > abs(b) % 2; 
            }
            return a % m < b % m;
        });
        cout << n << " " << m << "\n";
        for(int i = 0; i < n; i++)
            cout << a[i] <<"\n";
    }
    cout << "0 0\n";
}