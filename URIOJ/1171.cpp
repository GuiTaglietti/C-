/*

    Gui Taglietti - URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1171

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, aux;
    vector<int> ans, vi;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> aux;
        if(!count(ans.begin(), ans.end(), aux)){ 
            ans.push_back(aux);
            vi.push_back(aux);
        }
        else ans.push_back(aux);
    }
    sort(vi.begin(), vi.end());
    for(auto e : vi){
        cout << e << " aparece " << count(ans.begin(), ans.end(), e) << " vez(es)" << endl;
    }
    return 0;
}
