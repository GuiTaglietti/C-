#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Array{
    private:
      int* array;
      int pointer;
      void merge(int arr[], int l, int m, int r);

    public:
      Array(int size){
          array = new int[size];
      }
      void push(int e);
      void mergesort(int arr[], int l, int r);
};

void Array::push(int e){
    array[pointer] = e;
    pointer++;
}

void Array::merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = arr[i + l];
    for(int i = 0; i < n2; i++)
        R[i] = arr[i + m + 1];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i++];
        }
        else{
            arr[k] = R[j++];
        }
        k++;
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

void Array::mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r)/2; 
        mergesort(arr, l, m); 
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
