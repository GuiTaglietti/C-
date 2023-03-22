

/*
    Gui Taglietti -- URI Online Judge solutions
    Problem: https://www.beecrowd.com.br/judge/pt/problems/view/1256
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    bool flag = false;
    while(n--){
        if(flag){
            cout << endl;
        } else flag = true;
        cin >> a >> b;
        int c[b],i=0;
        for(int j=0;j<b;j++)
            cin>>c[j];
        for(i=0;i<a;i++){
            cout << i << " -> ";
            for(int j=0;j<b;j++){
                if(c[j]%a==i)
                    cout<<c[j]<<" -> ";
            }
            cout<<"\\\n";
        }
    }
    return 0;
}
