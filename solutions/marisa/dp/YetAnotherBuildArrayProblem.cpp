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


int MAXN = (int)(5000);
vector<bool> is_prime(MAXN, true);
vector<int> primes;
void init_sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i<= MAXN ; i++){
        if (is_prime[i] && (ll)i * i  <= MAXN){
            for (int j = i *i ; j <= MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }
};



void solve(){
    init_sieve();
    // up to k which is 1000 
    // we only care that adjacent is prime 
    // we can pregenerated primes up to 2k in a list for O(1) checking isPrime 
    // dp[i][k] means from [i...N] given A[i] is "k" how solutions are there

    ll n,k;
    cin >> n >> k;
    vvl dp(n+1, vl(k*3, 0));
    for (int d = 0; d < k*3; d++) dp[1][d] = 1;
    // 1000 * 1000 * 100 
    // 1 000 000 00 
    //for (int d = 0; d < 2020; d ++) dp[1][d] = 1; // there is only one way
    // we can build by first N items
    for (int i = 2 ; i<= n; i++){
        for (int c = 0; c <= k; c ++){
            for (int q = 0; q <= k ; q ++){
                int v = c + q;
                if (is_prime[v]) {
                    dp[i][c] = (dp[i][c] + dp[i-1][q]) % MOD;
                }
            }
        }
    }
    ll res = 0;
    for (int d = 0; d <= k; d++){
        res = (res + dp[n][d]) % MOD;
    }
    debug(dp);
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
