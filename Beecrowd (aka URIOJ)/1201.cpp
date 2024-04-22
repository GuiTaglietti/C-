/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1201
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    node *left, *right;
    int val;
    node(int _val): val(_val), left(nullptr), right(nullptr){}
};

node* insert(node *tree, int v){
    if(!tree)
        tree = new node(v);
    else if(v < tree->val)
        tree->left = insert(tree->left, v);
    else if(v > tree->val)
        tree->right = insert(tree->right, v);
    return tree;
}

node* findmax(node *tree){
    node* temp = tree;
    while(temp->right)
        temp = temp->right;
    return temp;
}

node* removenode(node *root, int v){
    if(!root) 
        return root;
    if(v < root->val) 
        root->left = removenode(root->left, v);
    else if(v > root->val) 
        root->right = removenode(root->right, v);
    else{
        if(!root->left && !root->right){
            delete root;
            root = nullptr;
        }
        else if(!(root->left && root->right)){
            node *temp = root;
            if(root->left)
                root = root->left;
            else
                root = root->right;
            delete temp;
        }
        else{
            node *temp = findmax(root->left);
            root->val = temp->val;
            root->left = removenode(root->left, temp->val);
        }
    }
    return root;
}

string ans = "";

void preorder(node *tree){
    if(tree){
        ans += " " + to_string(tree->val);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(node *tree){
    if(tree){
        inorder(tree->left);
        ans += " " + to_string(tree->val);
        inorder(tree->right);
    }
}

void posorder(node *tree){
    if(tree){
        posorder(tree->left);
        posorder(tree->right);
        ans += " " + to_string(tree->val);
    }
}

bool findnode(node *tree, int v){
    if(!tree) 
        return false;
    if(tree->val == v) 
        return true;
    if(v < tree->val) 
        return findnode(tree->left, v);
    return findnode(tree->right, v);
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string op;
    node *tree = nullptr;
    while(cin >> op){
        if(op == "INFIXA"){
            inorder(tree);
            cout << ans.substr(1) << "\n";
        }
        else if(op == "POSFIXA"){
            posorder(tree);
            cout << ans.substr(1) << "\n";
        }
        else if(op == "PREFIXA"){
            preorder(tree);
            cout << ans.substr(1) << "\n";
        }
        else{
            int v; cin >> v;
            if(op == "I")
                tree = insert(tree, v);
            else if(op == "P")
                cout << v << (findnode(tree, v) ? " existe" : " nao existe") << "\n";
            else if(op == "R")
                tree = removenode(tree, v);  
        }
        ans = "";
    }
    return 0;
}