/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1260
*/
#include <bits/stdc++.h>
using namespace std;

void solve(const vector<string> &vs, const set<string> &buffer) noexcept{
    size_t sz = vs.size();
    for(const auto &e : buffer){
        float ans = (static_cast<float>(100) * count(vs.begin(), vs.end(), e)) / sz;
        cout << e << " " << fixed << setprecision(4) << ans << "\n";
    } 
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    string s;
    bool f = false;
    vector<string> vs;
    cin.ignore();
    while(t--){
        if(!f){
            getline(cin, s);
            f = true;
        }
        while(true){
            getline(cin, s);
            if(s.empty())
                break;
            vs.push_back(s); 
        }
        sort(vs.begin(), vs.end());
        solve(vs, set<string>(vs.begin(), vs.end()));
        vs.clear();
        if(t != 1) cout << "\n";
    }    
    return 0;
}