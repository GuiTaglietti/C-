/*

  Gui Taglietti - URI Online Judge solutions
  Problem: https://www.beecrowd.com.br/judge/pt/problems/view/2312

*/

#include<bits/stdc++.h>
using namespace std;

struct country{
    string name;
    int medals[3];
};

bool comp(const country &a, const country &b){
    for(int j = 0; j < 3; j++)
        if(a.medals[j] != b.medals[j])
            return a.medals[j] > b.medals[j];
    return a.name < b.name;
}

int main(){
    int n;
    cin >> n;
    vector<country> v;
    country c;
    for(int i = 0; i < n; i++){
        cin >> c.name;
        for(int j = 0; j < 3; j++){
            cin >> c.medals[j];
        }
        v.push_back(c);
    }
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < n; i++){
        cout << v[i].name;
        for(int j = 0; j < 3; j++){
            cout << " " << v[i].medals[j];
        }
        cout << "\n";
    }
    return 0;
}
