/**
 * @author GuiTaglietti
 * @link   https://judge.beecrowd.com/pt/problems/view/1341
*/
#include "bits/stdc++.h" 
using namespace std; 
 
[[nodiscard]] int LCS(const string &s1, const string &s2, int m, int n) noexcept{  
    int L[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(!i|| !j)
                L[i][j] = 0;
            else if(s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}  

string init(vector<string> &grid){
    int n, x, y, la, ca, msc;
    string l, p, ans = "";
    cin >> n >> x >> y;
    if(n)
        cin >> p;
    ans += grid[x-1][y-1]; 
    la = x - 1; ca = y - 1;
    for(int i = 0; i < n; i++){
        switch(p[i]){
            case 'N':
                la--;
                ans += grid[la][ca];
                break;

            case 'S':
                la++;
                ans += grid[la][ca];
                break;

            case 'E':
                ca++;
                ans += grid[la][ca];
                break;

            case 'W':
                ca--;
                ans += grid[la][ca];
                break;

            default: 
                break;
        }
    }
    return ans;
}

int main(){ 
    ios::ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    string l, sa, sb;
    int t, ans, cases = 0; cin >> t;
    while(t--){
        cases++;
        int h, w; cin >> h >> w;
        vector<string> grid;
        for(int i = 0; i < h; i++){
            cin >> l;
            grid.push_back(l);
        }
        sa = init(grid); sb = init(grid);
        ans = LCS(sa, sb, sa.size(), sb.size());
        cout << "Case " << cases << ": ";
        cout << sa.size() - ans << " " << sb.size() - ans << "\n";
    }
    return 0; 
} 