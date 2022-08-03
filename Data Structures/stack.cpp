#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

class Stack{
    int num;
    
    public:
        int arr[MAX];
        Stack(){
            num = -1;
        };
        void push(int element);
        void pop();
        bool isEmpty();
        int peek();
        int len();
        bool have(int number); 
};

void Stack::push(int element){
    for(int i = 0; i < MAX; i++){
        if(arr[i] == -1){
            arr[i] = element;
            break;
        }
    }
}

void Stack::pop(){
    for(int i = 0; i < MAX; i++){
        if(arr[i] == -1){
            arr[i - 1] = -1;
            break;
        }
    }
}

bool Stack::isEmpty(){
    if(arr[0] == -1){
        return true;
    }
    return false;
}

int Stack::peek(){
    for(int i = 0; i < MAX; i++){
        if(arr[i] == -1){
            return arr[i - 1];
        }
    }
}

int Stack::len(){
    int count = 0;
    for(int i = 0; i < MAX; i++){
        if(arr[i] != -1){
            count++;
        }
        else{
            return count;
        }
    }
}

bool Stack::have(int number){
    for(int i = 0; i < MAX; i++){
        if(arr[i] == number){
            return true;
        }
        else if(arr[i] == -1){
            return false;
        }
    }
}

int main(){
    class Stack s;
    memset(s.arr, -1, sizeof(s.arr));
    s.push(10);
    s.push(20);
    cout << s.arr[0] << " " << s.arr[1] << endl;
    s.pop();
    cout << s.arr[0] << " " << s.arr[1] << endl; 
    cout << s.have(10) << endl;
    cout << s.isEmpty() << endl;
    cout << s.peek() << endl;
    cout << s.len() << endl;
    return 0;
}
