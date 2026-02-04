#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){
    int h,w,k;
    cin >> h >> w >> k;
    vvi g(h, vi(w));
    for (int i=0;i<h;i++){
        for (int j =0; j < w; j++){
            char c; cin >> c;
            if (c=='.') g[i][j] = 1; // 1 = white 
                                     // 0 = black
        }
    }
    debug(g);
    int res = 0;
    set<int> rows, cols;

    auto countBlack = [&]() -> void{
        debug(rows, cols);
        int cnt = 0;
        for (int i = 0; i < h; i++){
            if (rows.count(i)) continue;
            for (int j = 0; j< w; j++){
                if (cols.count(j)) continue;
                if (g[i][j] == 0) cnt++;
            }
        }
        debug(cnt);
        if (cnt == k) res++;
    };


    auto selectCol = [&](auto& selectCol, int i) -> void {
        if (i == w) countBlack();
        else {
            cols.insert(i);
            selectCol(selectCol, i+1);
            cols.erase(i);
            selectCol(selectCol, i+1);
        }
    };

    auto selectRow = [&](auto& selectRow, int i) -> void {
        if (i == h) selectCol(selectCol, 0);
        else{
            rows.insert(i);
            selectRow(selectRow, i+1);
            rows.erase(i);
            selectRow(selectRow, i+1);
        }
    };

    selectRow(selectRow, 0);
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
