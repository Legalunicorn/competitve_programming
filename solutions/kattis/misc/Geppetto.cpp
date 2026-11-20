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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// naive 2^20 x 20^2 might be too slow 
// like we build up the elements 
// 2^20 x 20, should be ok
void solve(){
    int n,m;
    cin >> n >> m;
    int mask =1<<n;
    int res = 0;
    vvi mark(n, vi(n));
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        mark[x][y] = 1;
        mark[y][x] = 1;
    }
    vb present(n);
    auto go = [&](auto& go, int i) -> void{
        if(i==n){
            res++;
            return;
        }
        // seen wheather we can add "i"? 
        bool safe = true;
        for (int j = 0; j < n; j++){
            if (present[j] && mark[i][j] == 1) safe = false;
        }
        if (safe){
            present[i] = true;
            go(go, i+1);
            present[i] = false;
        }
        go(go,i+1);
    };
    go(go, 0);
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
    while(T--) solve();
    return 0;
}
