/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1222
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, L, C;
    while(cin >> N >> L >> C){
        int cmpl = 0, ln = 1;
        for(int i = 0; i < N; i++){
            string s; cin >> s;
            int sz = s.length();
            if(i != N - 1 && (sz + cmpl != C)) 
                sz++;
            if(sz + cmpl <= C) 
                cmpl += sz;
            else{
                ln++;
                cmpl = sz;
            } 
        }
        cout << ceil(static_cast<float>(ln) / static_cast<float>(L)) << "\n";
    }
    return 0;
}