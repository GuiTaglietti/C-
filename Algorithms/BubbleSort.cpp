#include <bits/stdc++.h>
using namespace std;

template<typename T>
void mySwap(T &e1, T &e2){
    int u = e1;
    e1 = e2;
    e2 = u;
}

void bubble(int arr[], int size){
    bool f;
    for(int i = 0; i < size; i++){
        f = false;
        for(int j = 0; j < (size - i - 1); j++){
            if(arr[j] > arr[j + 1]){
                mySwap(arr[j], arr[j + 1]);
                f = true;
            }
        }
        if(!f){
            break;
        }
    }
}

int main(){
    int l[] = {5, 3, 53, 17, 20, 16, 22, 2};
    int n = sizeof(l)/sizeof(int);
    cout << "Array desordenado: ";
    for(auto e : l){
        cout << e << " ";
    }
    cout << endl;
    cout << "Array ordenado: ";
    bubble(l, n);
    for(auto e : l){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
