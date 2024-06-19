/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1077
*/
#include <bits/stdc++.h>
using namespace std;

[[nodiscard]] inline bool isoprt(char c) noexcept{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

[[nodiscard]] int precedence(char op) noexcept{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

[[nodiscard]] const string shuntingyard(const string &s){
    stack<char> ops; 
    string ans = "";
    for(const char &ch : s){
        if(isalnum(ch))
            ans += ch;
        else if(ch == '(')
            ops.push(ch);
        else if(ch == ')'){
            while(!ops.empty() && ops.top() != '('){
                ans += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else if(isoprt(ch)){
            while(!ops.empty() && precedence(ops.top()) >= precedence(ch)){
                ans += ops.top();
                ops.pop();
            }
            ops.push(ch);
        }
    }
    while(!ops.empty()){
        ans += ops.top();
        ops.pop();
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        string expr; cin >> expr;
        cout << shuntingyard(expr) << "\n";
    }
    return 0;
}
