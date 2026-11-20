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

// M -> total time 
// then based on total time we max the p?  
// interesting 
// M/t[i] 
// each prize only once 
// sort prize kind of useless? is it? 
// its possible a subset excluding the larger prices sum exceeds the top few pricez 
//
// if pi =  m / ai 
// is this some weird dp? 
// no not really 
// total time / task time 
// the order of task duration does not matter 
// invariants could help 
// erverytime i add a new task the total time increase and all the previous task could shift hnmm 
// oh i think i misread the problem ,... M is fixed 
// wait not its not "m" is the total selected time AND the time limt the heck? 
//
//
// im so confused by the problem statement 
// is pi determeind by aii alrady or whata
void solve(){
    ll res = 0;
    ll n,m;
    cin >> n >> m; 
    vl a(n), b(m);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    vl seen(m, INF); 

    for (int i = 0; i < n; i++){
        ll pos = (m / a[i] ) - 1;
        seen[pos] = min(seen[pos], a[i]);
    }
    // 60 , cost = m 
    // 59, cost = 1 
    // 58, cost = 1 
    //
    // sort by value dont make sense 
    // sort by cost dont make sense either 
    // this sounds like knapsack dp but constraints dont make sense 
    // but im literally solving knapsack dp equvalent? unless i misread the problem 
    // and its O(nm) 
    // the number of quotients is bounded but divisors of M 
    //
    // how do  ido knapsack again 
    vl w, v;
    for (int i = 0; i < m; i++){
        if (seen[i] != INF){
            w.pb(seen[i]);
            v.pb(b[i]);
        }
    }
    int k = w.size();

    // m space 
    //
    vl dp(m+1);
    for (int i = 1; i <= w.size(); i++){
        for (int j = m; j >= w[i-1]; j--){
            dp[j] = max(dp[j], dp[j-w[i-1]]  + v[i-1]);
        }
    }
    cout << dp[m] << endl;


    // so COST -> value 
    // COST at most LOG_M times 
    // value ->

    // vpl x(m);
    // for (int i = 0; i < m; i++) x[i] = {b[i], seen[i]};
    // sort(rall(x));
    // ll used = 0;
    // for (int i = 0; i < m; i++){
    //
    // }



    // oh time time must not exceed m 
    // but m is fixed 
    // ok... 
    // debug(seen);
    // debug(a);
    // debug(b);
    // for (int i = 1; i<=m; i++){
    //     if (seen[i]) debug(i);
    //     if (seen[i]) res += b[i-1];
    // }
    // cout << res << endl;

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
