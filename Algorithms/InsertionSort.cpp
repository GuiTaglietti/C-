#include <bits/stdc++.h>
using namespace std;

template <typename T>
void insertionsort(T arr[], int size){
    T control, j; 
    for (int i = 1; i < size; i++){ 
        control = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > control){ 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = control; 
    } 
}

int main(){
    int array[] = {50, 23, 5, 0, -2, 4, 15};
    int len = sizeof(array)/sizeof(int);
    cout << "Array desorndenado: ";
    for(auto e : array){
        cout << e << " ";
    }
    cout << endl;
    cout << "Array ordenado: ";
    insertionsort(array, len);
    for(auto e : array){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
