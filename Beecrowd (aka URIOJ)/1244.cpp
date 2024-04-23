/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1244
*/
#include <bits/stdc++.h>
using namespace std;

struct word{
    int id;
    string s;
};

void parse(const string &str, vector<word> &out){ 
    stringstream ss(str); 
    string s;
    int id = 0;
    while(getline(ss, s, ' '))
        out.push_back({id++, s}); 
}
 
int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string wrds;
        vector<word> vs;
        getline(cin, wrds);
        parse(wrds, vs);
        sort(vs.begin(), vs.end(), [](const word &a, const word &b){
            if(a.s.size() == b.s.size()) 
                return a.id < b.id;
            return a.s.size() > b.s.size();
        });
        bool first = true;
        for(const auto &wrd : vs){
            if(first)
                first = false;
            else 
                cout << " ";
            cout << wrd.s;
        }
        cout << "\n";
    }
    return 0;
}