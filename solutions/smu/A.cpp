#include <bits/stdc++.h>
#include <csetjmp>
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

void solve(){
    int n, m;
    cin >> n >> m;
    vi t(n);
    for (auto& z:t) cin >> z;
    debug(t);
    vvi d(m, vi(n));
    for (int i = 0; i < m; i++){
        for (auto& z: d[i]) cin >> z;
    }
    debug(d);
    int q;
    cin >> q;
    while(q--){
        int x,i,j;
        cin >> x >> i >> j;
        debug(x,i,j);
        int reach = x + d[i-1][j-1];
        // based on reach, find the next train time jk
        int q= t[j-1];
        int train;
        if (reach % q == 0){
            train = reach;
        } else{
            int x = reach/q;
            train = (x+1)*q;
        }
        cout << train - x << endl;
    }
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
