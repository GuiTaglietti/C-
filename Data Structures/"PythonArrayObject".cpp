#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Array {
private:
  int arr[MAX];
  int size = 0;

public:
  Array(){};
  void push(int e);
  void extend(int arr[], int size);
  void pop();
  void show();
  int len();
  int access(int index);
  bool have(int e);
};

void Array::extend(int array[], int sz) {
  sz += size;
  int control = 0;
  for (int i = size; i < sz; i++) {
    arr[i] = array[control];
    control++;
  }
  size += control;
}

void Array::push(int e) {
  arr[size] = e;
  size++;
}

void Array::show() {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void Array::pop() { size--; }
int Array::len() { return size; }
int Array::access(int index) {
  if (index <= size - 1) {
    return arr[index];
  }
  throw invalid_argument("Index greater than array's size!");
}
bool Array::have(int e) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == e) {
      return true;
    }
  }
  return false;
}

int main() {
  class Array arrs;
  int meuArray[] = {1, 2, 3}, segArray[] = {4, 5, 6};
  arrs.extend(meuArray, 3);
  arrs.extend(segArray, 3);
  arrs.show();
  cout << arrs.access(3) << endl;
  cout << arrs.access(10) << endl;
  return 0;
}
