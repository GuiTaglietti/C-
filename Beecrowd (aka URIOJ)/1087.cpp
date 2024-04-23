/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1087
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2 && x1 && y1 && x2 && y2){
        if(x1 == x2 && y1 == y2) 
            cout << "0\n";
        else if(((x2 - x1) == -(y2 - y1) || -(x2 - x1) == -(y2 - y1) || -(x2 - x1) == (y2 - y1) || (x2 - x1) == (y2 - y1)) || (x1 == x2 || y1 == y2)) 
            cout << "1\n";
        else 
            cout << "2\n";
    }
    return 0;
}