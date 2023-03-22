/*
    Gui Taglietti -- URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1257
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(cin >> N){
        for(int x = 0; x < N; x++){
            int L;
            cin >> L;
            string s;
            int soma = 0;
            for(int i = 0; i < L; i++){
                cin >> s;
                int sz = s.length();
                for(int j = 0; j < sz; j++)
                    soma = soma + (s[j] - 'A') + i + j;
            }
            cout << soma << '\n';
        }
    }
    return 0;
}
