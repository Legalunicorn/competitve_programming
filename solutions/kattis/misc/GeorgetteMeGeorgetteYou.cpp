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
// i think this is a combinatorics problem 
// where we just find pair elements 
// find ways to pair elements, and each path can be right or wrong 
// what is the computation exactly? 
// say we have N 
// the

// vl fac(1000010);
int N = 1000010;
vl dp(N);
ll mod = MOD;
void init(ll mod){
    dp[1] = 1; // 1 choice 
    dp[2] = 2;
    for (int i = 3; i < N; i++){
        // i -> numbner of elements 
        dp[i] = 1; // take yourself 
        dp[i] = (dp[i] + dp[i-2] + ) % mod; // 
    };
}

void solve(ll mod){
    ll n;
    cin >> n;
    ll tot = fac[n];
    ll less = (fac[n-1] * 2) % mod;
    ll res = (tot + mod - less) % mod;
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T >> mod;
    init(mod);
    while(T--) solve(mod);
    return 0;
}
