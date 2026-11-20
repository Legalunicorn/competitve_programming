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


// the ant can go from 
// dp over k moves from one point to any ONE neighbour 
// the k cycles = 3 * dp[k-1]
// recurance relation for dp 
// dp[0] = 0 
// dp[1] = 1 
// dp[i] = 2 * dp[i-1] + 3 * d[i-2];
//
// example 
// dp[0] = 0 
// dp[1] = 1
// dp[2] = 2 
// dp[3] = 7 
// dp[4] = 14 + 6 = 20 


void solve(){
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    } else if (n == 2){
        cout << 3 << endl;
        return;
    }
    ll prev = 0; 
    ll curr = 1;
    // we compute 0 and 1 alrady 
    for (int i=1;i<n;i++){
    
        ll temp = 2 * curr % MOD + 3 * prev % MOD;
        prev = curr;
        curr = temp;
        debug(prev,curr);

    }
    ll res = 3 * prev % MOD;
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
