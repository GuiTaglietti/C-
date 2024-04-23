/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1195
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    node *left, *right;
    int v;
    node(int value) : left(0), right(0), v(value){}
};

[[nodiscard]] node* insert(node *tree, int v){
    if(!tree) 
        tree = new node(v);
    else if(v > tree->v) 
        tree->right = insert(tree->right, v);
    else if(v < tree->v) 
        tree->left = insert(tree->left, v);
    return tree;
}

void pre(node *tree){
    if(tree){
        cout << " " << tree->v;
        pre(tree->left);
        pre(tree->right);
    }
}

void in(node *tree){
    if(tree){
        in(tree->left);
        cout << " " << tree->v;
        in(tree->right);
    }
}

void pos(node *tree){
    if(tree){
        pos(tree->left);
        pos(tree->right);
        cout << " " << tree->v;
    }
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int cases = 1;
    while(t--){
        node *tree = nullptr;
        int n; cin >> n;
        int tstart[n];
        for(int i = 0; i < n; i++)
            cin >> tstart[i];
        for(const int &e : tstart)
            tree = insert(tree, e);
        cout << "Case " << cases << ":\n";
        cout << "Pre.:"; pre(tree); cout << "\n";
        cout << "In..:"; in(tree); cout << "\n";
        cout << "Post:"; pos(tree); cout << "\n";
        cout << "\n";
        cases++;
    }
    return 0;
}