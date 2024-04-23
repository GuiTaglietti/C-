/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/2674
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

vector<int> prime;
unordered_set<int> primeset;

[[nodiscard]] bool is_super(int n) noexcept{
    const string s = to_string(n);
    for(const char &c : s)
        if(!primeset.count(c - '0'))
            return false;
    return true;
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    prime.push_back(2); primeset.insert(2);
    for(size_t i = 3; i < MAX; i++){
        bool isprime = true;
        for(size_t j = 0; j < prime.size(); j++){
            if(i % prime[j] == 0){
                isprime = false;
                break;
            }
        }
        if(isprime){
            prime.push_back(i); 
            primeset.insert(i);
        }
    }
    while(cin >> n)
        cout << ((primeset.count(n) > 0) ? (is_super(n) ? "Super" : "Primo") : "Nada") << "\n";
    return 0;
}