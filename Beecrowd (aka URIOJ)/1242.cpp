/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1242
*/
#include <bits/stdc++.h>
using namespace std;

[[nodiscard]] int solve(const string &s){
    stack<char> st;
    int ans = 0;
    for(const char &c : s){
        if(!st.empty() && ((st.top() == 'B' && c == 'S') || (st.top() == 'S' && c == 'B') || 
          (st.top() == 'C' && c == 'F') || (st.top() == 'F' && c == 'C')))
        {
            ans++;
            st.pop();
        } 
        else 
            st.push(c);
    }
    return ans;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    while(cin >> s)
        cout << solve(s) << "\n";
    return 0;
}