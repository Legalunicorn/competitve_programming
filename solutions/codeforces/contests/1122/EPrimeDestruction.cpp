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


//NOTE:
//for elements larger than "k"
// we need to decide the strategy to split it 
// the element dont even interact with each other 
// so itsd just a[i] -> k independent queries 
// ai <= n which is good 
// int MAXN = (int)(3e5+5);
// vector<bool> is_prime(MAXN, true);
// vector<int> primes;
// void init_sieve(){
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i<= MAXN ; i++){
//         if (is_prime[i] && (ll)i * i  <= MAXN){
//             for (int j = i *i ; j <= MAXN; j += i){
//                 is_prime[j] = false;
//             }
//         }
//     }
//     for (int i=2; i<=MAXN;i++) {
//         if (is_prime[i]) primes.push_back(i);
//     }
// };
//
// vector<int> trial_div(int n){
//     vector<int> fac;
//     for (auto& d: primes){
//         if (d* d > n) break;
//         while(n% d == 0){
//             fac.push_back(d);
//             n /= d;
//         }
//     }
//     if (n>1) fac.push_back(n);
//     return fac;
// }



set<int> factor(int n){
    set<int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res.insert(i);
            n /= i;
        }
    }
    if (n>1) res.insert(n);
    return res;
}



void solve(){
    ll n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;

    // sum n , sum 
    // AI LESS than N 
    // means we can do over it
    vl dp(n+5,0);
    for (int i = 2; i <= n; i++){
        if (i <= k){
            dp[i] = 0; // free
        } else {
           ll best = INF; 
           set<int> primes = factor(i);
           for (auto p : primes){
               if (p > i) break;
               if (i%p!=0) continue;
               ll xp = i/p;
               ll x = p;
               ll cost = 1+ p * dp[xp];
               best = min(best, cost);
           }
           dp[i] = best;
        }
    }
    ll res = 0;
    for (int i= 0 ; i < n;i++){
        res += dp[a[i]];
    }
    cout << res << endl;




    // ll res = 0;
    // for (int i = 0; i < n; i++){
    //     if (a[i] <= k) continue;
    //     ll cnt = 1;
    //     ll nodes = 1;
    //     ll val = a[i];
    //     while(true){
    //         // ll highres = val/high[val];
    //         // debug(val,cnt,nodes, highres);
    //         debug(val,cnt, nodes);
    //         if (val <= k){
    //             res += (cnt - nodes);
    //             debug(a[i], k, cnt);
    //             break;
    //         } else {
    //             ll highres = val/high[val];
    //             if (highres <= k){
    //                 cnt += (high[val] * nodes);
    //                 nodes = nodes * high[val];
    //                 val = highres;
    //             } else{
    //                 ll lowres = val/low[val];
    //                 cnt += (low[val] * nodes);
    //                 nodes = nodes * low[val];
    //                 val = lowres;
    //             }
    //         }
    //     }
    // }
    // cout << res << endl;
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // init_sieve();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
