/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1215
*/
#include <bits/stdc++.h>
using namespace std;

void handle(vector<string> &vs, const string &s) noexcept{
    string temp = "";
    for(size_t i = 0; i < s.length(); i++){
        if(isalpha(s[i])) 
            temp += tolower(s[i]);
        else{
            if(find(vs.begin(), vs.end(), temp) == vs.end()) 
                vs.push_back(temp);
            temp.clear();
        }
    }
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<string> vs;
    string s;
    while(getline(cin, s))
        handle(vs, s);
    sort(vs.begin(), vs.end());
    for(size_t i = 1; i < vs.size(); i++)
        cout << vs[i] << "\n";
    return 0;
}