/*

  Gui Taglietti - URI Online Judge solutions
  Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1451

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    list<char>s1;
    list<char>::iterator p;
    while(cin >> a){
	    s1.clear();
	    p = s1.begin();
	    for(int i = 0; i < a.size(); i++){
		    if(a[i] == ']') {
                p = s1.end();
            } 
            else if(a[i] == '[') {
                p = s1.begin();
            }
            else {
                s1.insert(p, a[i]);
            }
        }
        for(p = s1.begin(); p != s1.end(); p++){
            cout << *p;
        }
        cout << endl;
    }
	return 0;
}
