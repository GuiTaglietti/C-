/*

  Includes, headers, namespace, defines

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

/*

    Sorts

*/

// C++ sort

// int arr[5] = {51, 4, 7, 24, 98};
// sort(begin(arr), end(arr), greater<int>());
// Use sort in main function

// Bubble Sort

void bubble(int arr[], int size){
    bool f;
    for(int i = 0; i < size; i++){
        f = false;
        for(int j = 0; j < (size - i - 1); j++){
            if(arr[j] < arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                f = true;
            }
        }
        if(!f){
            break;
        }
    }
}

// Insertion Sort

void insertionsort(int arr[], int size){
    int control, j; 
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

// Merge Sort

void merge(int arr[], int l, int m, int r){
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

void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r)/2; 
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r); 
    }
}

/*

    Data structures

*/

// Linked List

class Node{
private:
	int v;
	Node* next;

public:
	Node(int v){
		this->v = v;
		this->next = NULL;
	}

	int getValue(){
		return this->v;
	}

	Node* getNextNode(){
		return this->next;
	}

	void setNextNode(Node* p){
		this->next = p;
	}
};

class List{
private:
	Node* front; 
	Node* back; 

public:
	List(){
		this->front = NULL;
		this->back = NULL;
	}

	List(int v){
		this->front = new Node(v);
		this->back = front;
	}

	virtual ~List(){
		delete this->front;
	}

	void showList(){
		cout << endl << "Lista:" << endl;
		Node* c = this->front;

		if(this->isEmpty()){
			cout << "A lista não possui elementos!" << endl;
        }
		else{
			while(c){
				cout << c->getValue() << endl;
				c = c->getNextNode();
			}
			cout << endl;
		}
	}

	bool isEmpty(){
		return(this->front == NULL);
	}

	void pushFront(int v){
		Node* valueNode = new Node(v);

		if(isEmpty()){
			this->front = valueNode;
			this->back = valueNode;
		}
		else{
			valueNode->setNextNode(this->front);
			this->front = valueNode;
		}
	}

	void pushBack(int v){
		Node* valueNode = new Node(v);

		if(isEmpty()){
			this->front = valueNode;
			this->back = valueNode;
		}
		else{
			this->back->setNextNode(valueNode);
			this->back = valueNode;
		}
	}

	int size(){
		if(this->isEmpty()){
			return 0;
        }

		Node* c = front;
		int len = 0;
		
		do{
			c = c->getNextNode();
			len++;
		} while(c);
		
        return len;
	}

	bool have(int v){
		Node* c = front;
		while(c){
			if(c->getValue() == v){
				return true;
            }
			c = c->getNextNode();
		}
		return false;
	}

	void remove(){
		if(!this->isEmpty()){
			if(front->getNextNode() == NULL){
				this->front = NULL;
            }
			else if(front->getNextNode()->getNextNode() == NULL){
				this->front->setNextNode(NULL);
            }
			else{
				Node* pNode1 = this->front;
				Node* previousNode = this->front->getNextNode();
				Node* chain = this->front->getNextNode()->getNextNode();
				while(chain){
					Node* aux = previousNode;
					previousNode = chain;
					pNode1 = aux;
					chain = chain->getNextNode();
				}
				delete pNode1->getNextNode();
				pNode1->setNextNode(NULL); 
				this->back = pNode1;
			}
		}
	}
};
