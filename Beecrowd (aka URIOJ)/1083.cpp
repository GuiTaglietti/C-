/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1083
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> prc = {
    {'^', 6}, {'*', 5}, {'/', 5}, {'+', 4}, {'-', 4},
    {'>', 3}, {'<', 3}, {'=', 3}, {'#', 3},
    {'.', 2}, {'|', 1}
};

[[nodiscard]] inline bool isopr(char c){
    return prc.find(c) != prc.end();
}

[[nodiscard]] inline int getprc(char op){
    return prc.find(op) != prc.end() ? prc[op] : 0;
}

[[nodiscard]] inline bool isoprnd(char c){
    return isalnum(c);
}

[[nodiscard]] bool lexical(const string &s){
    for(const char &c : s) 
        if(!isoprnd(c) && !isopr(c) && c != '(' && c != ')') 
            return false;
    return true;
}

[[nodiscard]] string shuntingyard(const string &s){
    stack<char> ops;
    string ans;
    bool lwa = false;
    for(const char &ch : s){
        if(isoprnd(ch)){
            ans += ch;
            lwa = true;
        } 
        else if(ch == '('){
            ops.push(ch);
            lwa = false;
        } 
        else if(ch == ')'){
            while(!ops.empty() && ops.top() != '('){
                ans += ops.top();
                ops.pop();
            }
            if(!ops.empty()) 
                ops.pop();
            else 
                return "Syntax Error!";
            lwa = true;
        } 
        else if(isopr(ch)){
            if(!lwa) 
                return "Syntax Error!";
            while(!ops.empty() && getprc(ops.top()) >= getprc(ch)){
                ans += ops.top();
                ops.pop();
            }
            ops.push(ch);
            lwa = false;
        } 
        else 
            return "Lexical Error!";
    }
    while(!ops.empty()){
        if(ops.top() == '(' || ops.top() == ')') 
            return "Syntax Error!";
        ans += ops.top();
        ops.pop();
    }
    return ans;
}

int main(){
    string expr;
    while(getline(cin, expr)){
        if(expr.empty()) 
            continue;
        if(!lexical(expr))
            cout << "Lexical Error!\n";
        else{
            string ans = shuntingyard(expr);
            cout << (ans == "Syntax Error!" ? "Syntax Error!" : ans) << "\n";
        }
    }
    return 0;
}
