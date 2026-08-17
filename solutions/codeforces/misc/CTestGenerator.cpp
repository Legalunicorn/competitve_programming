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

// NOTE :
// sum of m * n 
// need = s - m * n
// if need can be sumed from the 0 bits, sure 
//
// i dont know if its possible 
// we can consider the remaining bits and for each once 
// we have n to spare 
// then check if some combination of it reaches to need 
// 1. can this be constructed greedily? 
// 2. the bits are just multiples of each other (pwoer 2) 
// 3. so techically, if i can consume large, i should because it just means 
// i have gut feel that 
// you minally need the quotielt to fill up 
//


// i need to figure out if we can avoid leaving all to mod 
// like we have mod + extra m 
// is it possible to distribute 
//
// imma guess no 
//
// oh wait i think i misread this, 
// a[i] & m = a[i] NOT 
// a[i] & m = m 
// this means 
// a[i] is a subset of m 
// and it also means we least at meanst s/m of them 
// m is the max 
// if mod is > 0 
// (s/m) 1
//
//
// actually we need to overcompensate
//
//
// i making this harder then it has to be 
// why not break down "S" into the factors 


// 3 3 3 3 1 
// (n * m) - s 
//
//
// 13 , 5 , n = 7 
// 35 - 22 = 12 

bool check(ll n, ll s, ll m){

    for (int i = 62; i >= 0; i--){
        if (m >> i & 1){
            ll x = (1LL << i);
            ll q = min(n,s/x);
            s -= q * x;
            if (s == 0) return true;
        }
    }
    return false;


    // ll red = m * n - s;
    // debug(red);
    // if (red < 0) return false;
    // debug(red);
    // for (int i = 62; i >= 0; i--){
    //     if (m >> i & 1){
    //         ll x = (1LL << i);
    //         ll q = min(n, red/x);
    //         red -= q * x;
    //         // debug("2",red);
    //         if (red == 0) return true;
    //     }
    // }
    // // debug("END",red);
    // return false;
};

void solve(){
    ll s,m;
    cin >> s >> m;

    // maybe this is binary search, given then  n 
    ll l = 1, r = s;
    ll res = -1;
    debug(s,m);
    while(l<=r){
        ll mid =l+(r-l)/2;
        bool chk = check(mid, s, m);
        debug(mid,chk);
        if (chk){
            res = mid;
            r = mid - 1;
        } else l = mid +1;
    }
    cout << res << endl;
    cerr << endl;

    // ll ss = s;
    // ll res = 1;
    // debug("STTART", s,m);
    // for (int i = 62; i >= 0; i--){
    //     if ((m >> i & 1) == 0) continue;
    //     ll x = (1LL << i);
    //     debug(s,x);
    //     if (s >= x){
    //         ll q  = (s/x);
    //         debug(s,x,q);
    //         s -= (q * x);
    //         res = max(res,q);
    //         if (s == 0){
    //             cout << res << endl;
    //             return;
    //         }
    //     }
    // }
    // debug(ss,s,m);
    // if (s%m ==0) {
    //     cout << s/m << endl;
    //     return;
    // }
    // ll n = (s/m)+1LL;
    // ll take = n * m - s;
    // debug(s,m,n,take);
    // for (int i = 63; i >= 0; i--){
    //     ll x = (1LL << i);
    //     if (take >= x){
    //         ll q = min(n, take/x);
    //         take -= q * x;
    //         if (take ==0){
    //             cout << n << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << -1 << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
