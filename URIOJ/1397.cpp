/*

    Gui Taglietti - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1397

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n1, n2, p1 = 0, p2 = 0;
    while(true){
        cin >> t;
        if(t == 0) break;
        for(int i = 0; i < t; i++){
            cin >> n1 >> n2;
            if(n1 > n2) p1++;
            if(n2 > n1) p2++;
        }
        cout << p1 << " " << p2 << endl;
        p1 = 0; 
        p2 = 0;
    }
    return 0;
}
