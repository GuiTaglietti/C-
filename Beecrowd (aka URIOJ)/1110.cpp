/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1110
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    while(cin >> N && N){
        deque<int> dq(N); vector<int> vi;
        for(int i = 0; i < N; i++) 
            dq[i] = i + 1;
        while(dq.size() >= 2){
            vi.push_back(dq.front()); dq.pop_front();
            dq.push_back(dq.front()); dq.pop_front();
        }
        cout << "Discarded cards: ";
        for(int i = 0; i < N - 2; i++) 
            cout << vi[i] << ", ";
        cout << vi[N - 2] << "\n" << "Remaining card: " << dq.back() << "\n";
    }
    return 0;
}