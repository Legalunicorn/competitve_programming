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

// NOTE:
// max totol prooductivity? 
// its just maximiuse the sum 
// the post can be read in any order? 
// i smell greedy bruh 
// must read all A[i];
// must sum them 
//
// this is surely some prefix sum 
// might be easier t owork from thbe back 
// nvm 
// we can dp this if we want to be extra 
// dp from the back 
// dp[i][is flipped] 
// use a set to check if flioppable 


void solve(){
    ll n,m;
    cin >> n >> m;
    vl a(n);
    for (auto& z:a) cin >> z;
    set<ll> st;
    for (int i = 0; i < m ;i++){
        ll x; cin >> x;
        st.insert(x-1);
    }

    vvl dp(n+5, vl(2, -1));

    auto go = [&](auto& go, int i, int f) -> ll{
        if (i < 0){
            return 0ll;
        }
        if (dp[i][f] != -1ll) return dp[i][f];
        ll val = (f == 1? a[i]*-1: a[i]);
        ll mx = go(go, i-1, f) + val;
        if (st.count(i)){
            mx = max(mx, go(go,i-1, 1- f) - val);
        }
        return dp[i][f] = mx;
    };
    ll res = go(go, n-1, 0);
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
