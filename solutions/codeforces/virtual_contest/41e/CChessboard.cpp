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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;


// there are 2 kinds of pieces
// n <= 100 
// 4 pieces, we can brute force 
// a b a b 
// a a b b 
// a b b a 
// b a a b 
// b a b a 
// b b a a 

void solve(){
    int n;
    cin >> n;
    vector<vvi> g(4, vvi(n, vi(n)));
    for (int k = 0; k < 4; k++){
        for (int i = 0; i < n; i++){
            string s; 
            cin >> s;
            for (int j = 0; j < n ;j ++){
                g[k][i][j] = s[j] - '0';
                // cin >> g[k][i][j];
            }
        }
    }
    debug(g);
    vvi perms = {
        {1,0,1,0},
        {1,1,0,0},
        {1,0,0,1},
        {0,1,1,0},
        {0,1,0,1},
        {0,0,1,1,},
    };
    int res = 100000000;
    for (auto& p: perms){
        int ans = 0;
        for (int k = 0; k < 4; k++){
            int st = (p[k] == 0 ? 0 : 1); 
            debug(st);
            for (int i = 0; i < n;i++){
                for (int j= 0; j < n; j++){
                    if (g[k][i][j] != st) ans++;
                    st = 1 - st;
                }
            }
        }
        res = min(res, ans);
    }
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
