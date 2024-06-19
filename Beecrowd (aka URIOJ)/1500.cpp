/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1500
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

[[nodiscard]] inline ll cmp(ll a, ll b){
    return a + b;
}

class SegTree{
public:
    SegTree(int _size) : size(_size){
        st.assign(4*size, 0);
        lazy.assign(4*size, 0);
    }
    
    [[nodiscard]] inline ll query(int a, int b){  return query(1, 0, size - 1, a, b); }
    inline void update(int a, int b, ll k) { update(1, 0, size - 1, a, b, k); }


private:
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    
    vector<ll> st, lazy;
    int size;
    
    void push(int p, int l, int r){
        if(l != r){
            lazy[right(p)] += lazy[p];
            lazy[left(p)] += lazy[p];
        }
        st[p] += (r - l + 1) * lazy[p];
        lazy[p] = 0;
    }

    [[nodiscard]] ll query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) 
            return 0;
        if(l >= a && r <= b) 
            return st[p];
        ll p1 = query(left(p), l, (l + r) / 2, a, b);
        ll p2 = query(right(p), (l + r) / 2 + 1, r, a, b);
        return cmp(p1, p2);
    }

    void update(int p, int l, int r, int a, int b, ll k){
        push(p, l, r);
        if(a > r || b < l) 
            return;
        else if(l >= a && r <= b){
            lazy[p] = k;
            push(p, l, r);
        }
        else{
            update(left(p), l, (l + r) / 2, a, b, k);
            update(right(p), (l + r) / 2 + 1, r, a, b, k);
            st[p] = cmp(st[left(p)], st[right(p)]);
        }
    }
};

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        SegTree st(n);
        while(c--){
            int op, p, q;
            ll v;
            cin >> op;
            if(op == 0){
                cin >> p >> q >> v;
                st.update(p - 1, q - 1, v);
            }
            else{
                cin >> p >> q;
                cout << st.query(p - 1, q - 1) << "\n";
            }
        }
    }
    return 0;
}
