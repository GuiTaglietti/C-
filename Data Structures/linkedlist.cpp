/*

    Gui Taglietti - Linked list implementation (Simple linked list)
    GitHub --> https://github.com/GuiTaglietti

*/

#include <bits/stdc++.h>
using namespace std;

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

int main(){
	//Use a lista aqui...
	return 0;
}
