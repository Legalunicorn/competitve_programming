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

// NOTE:
// exaclty one station such that pj = i? 
// this just menas all the stations are cycles 
// can be self loop 
//
// the numbre of ordered pairs if just 
// each cycles choose 2 

// NOTE: FORMULA 
// n^ 2 

// NOTE:
// we should greedily increase the largest cycle size 
//

// we can essentially merge any two cycles 

void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    for (int i = 0; i < n;i++) a[i]--;
    vb seen(n, false);
    int sz = 0;
    auto go = [&](auto& go, int u) -> void{
        seen[u] = true;
        sz++;
        int v = a[u];
        if (!seen[v]){
            go(go, v);
        }
    };
    vl b;
    for (int i = 0; i < n; i++){
        if (!seen[i]){
            sz = 0;
            go(go,i);
            if (sz>0) b.pb(sz);
        }
    }
    sort(all(b));
    if (b.size() ==1){
        cout << (n*n) << endl;
    } else{
        int m = b.size();
        ll res = 0;
        b[m-1] += b[m-2];
        b[m-2] = 0;
        for (int i =0; i < m;i++) res += (b[i]*b[i]);
        cout << res << endl;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
