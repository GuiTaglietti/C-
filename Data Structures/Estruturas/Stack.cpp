#include <bits/stdc++.h>
#define DEFAULT_SIZE 10
using namespace std;


template<class T>
class Stack{
private:
	T *arr;
	int size = -1;

public:
	Stack(){
		arr = new T[DEFAULT_SIZE];
		memset(this->arr, 0, sizeof(this->arr));
	}

	Stack(int s){
		arr = new T[s];
		memset(this->arr, 0, sizeof(this->arr));
	}

	virtual ~Stack(){
		delete arr;
	}

	void push(T item){
		this->arr[++this->size] = item;
	}
	
	T pop(){
		return this->arr[this->size--];
	}
	
	bool isEmpty(){
		return this->size == -1;
	}

	T peek(){
		return this->arr[this->size];
	}

	bool have(T item){
		for(int i = 0; i < this->size + 1; i++){
			if(this->arr[i] == item){
				return true;
			}
		}
		return false;
	}
	
	int find(T item){
		for(int i = 0; i < this->size + 1; i++){
			if(this->arr[i] == item){
				return i;
			}
		}
		return -1;
	}

	void showStack(){
		cout << "Stack: ";
		for(int i = 0; i < this->size + 1; i++){
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}
};

int main(){
	Stack<int> *s = new Stack<int>(20);
	s->push(10);
	s->push(20);
	s->push(30);
	s->showStack();
	cout << "Existe o 30 na pilha: " << s->have(30) << endl;
	cout << "Posição do 30 na pilha: " << s->find(30) << endl;
	s->pop();
	s->showStack();
	delete s;
	return 0;
}
