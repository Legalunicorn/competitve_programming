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

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    vvi op(m, vi(3));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < 3 ;j++) cin >> op[i][j];
    }
    debug(op);
    int x,y;
    vl  freq(m+1);
    while(k--){
        cin >> x >> y;
        x--, y--;
        freq[x]++;
        freq[y+1]--;
    }
    for (int i = 1; i <= m;i++) freq[i] += freq[i-1];
    debug(freq);
    // now we have the frequency of each operation 
    // freq[i] -> how many times to appli operation [i]
    // this is simply second difference array
    vl d(n+1);
    for (int i = 0; i < m; i++){
        ll di = (ll) op[i][2] * (ll) freq[i];
        debug(i, di);
        d[op[i][0]-1] += di;
        d[op[i][1]] -= di;
    }
    for (int i = 1; i <= n; i++) d[i] += d[i-1];
    for (int i = 0; i < n; i++) cout << a[i] + d[i] << " ";
    cout << endl;

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
