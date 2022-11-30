/*

    Gui Taglietti - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1329

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, m = 0, j = 0;
    while(true){
        cin >> t;
        int arr[t];
        if(t == 0) break;
        else{
            for(int i = 0; i < t; i++){
                cin >> arr[i];
                if(arr[i] == 0) m++;
                if(arr[i] == 1) j++;
            }
            cout << "Mary won " << m << " times and John won " << j << " times" << endl;
            m = 0;
            j = 0;
        }
    }
    return 0;
}
