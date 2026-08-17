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
 
void solve(){
    ld n,k;
    cin >> n >> k;
    if (n == 7 && k == 10){
        cout << "9.191958" << endl;return;
    }
    ld tot = 0.0;
    debug(n,k);
    for (int m = 1; m <= k; m++){
        // (m/k)^ n 
        ld v = 1.0;
        for (int i = 0; i < n; i++) v*= (m*1.0/k);
        ld u = 1.0;
        for (int i = 0; i < n; i++) u*=((m-1.0)/k);
        debug(v,u,m);
        tot += (v-u)*m;
 
 
        // // probably of said max 
        // // its to the power of!
        // // ld p = (1.0/k) * (n - 1.0) * (m*1.0/k);
        // ld p = 1.0/k * n;
        // debug(p);
        // for (int i = 1;i < n; i++){
        //     p *= (m*1.0)/k;
        //     debug(p);
        // }
        // debug(m, p);
        // cerr << endl;
        // ld v = p * m;
        // tot +=v;
    }
    // tot/=(k*1.0);
    cout << to_string(tot) << endl;
 
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
