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


// i forgot the fucking formula
// 
//
// d = 1 is a trivial case
// soometyhin ffactorial aty most 10e18
// 20 factorial 
// there are at most 20 tems
// there are at least 3 terms
//
// terms [3,20] wide range
//
// (s,d,n)
//
// for easch s how many d  -> too slow
// we need to upper bound by the MAX term 
//
// for n = 3,4,5,.. 20 
// for the MAX term
// k


// NOTE:
// obvious prperties 
//
// suppose we haver sequence (s,d) 
//
// if (s,d) length L is possible 
// we can shift s all the way to 1 
//
//
// in general "d" is low cost
//
// for each L 
// or for each D we can do some bullshit 
// there is some monotocity
//
//
// s = 1, by default? 
// for each D = 1, ... D = idk 
// i think we should consider the stupid range where d = 1 
//
// so for each L we find the max D = 1 case 
//
// L = 4 
// maybe its 
//
// 6,7,8,9  
// -> then we know: 
// 
//
// wait for MAX L 
// any subseqeucne of if is an answer as we 
//
// s = 1, d = 1, l = 20 
// so we only care for each d


void solve(){
    ll n;
    cin >> n;
    vl fac(21);
    fac[0] = 1;
    for (int i = 1; i < 21; i++) fac[i] = fac[i-1] * i;
    debug(fac);
    ll res = 0;
    ll r = 1000000;
    for (int d = 1; d <= r; d++){
        ll s = 1;
        ll prod = 1;
        ll len = 1;
        while(prod*(s+d) <= n && prod*(s+d)>=0){
            s+=d;
            prod *= s;
            len++;
        }
        if (d <= 20) debug(len,d);
        if (len < 3) continue;
        if (len == 3) {
            res++;
            continue;
        }
        ll x = len - 2;
        ll v = x * (x+1) /2;
        res+=v;
    }
    cout << res << endl;
    // for (int l = 3; l <= 20; l++){
    //     // length of the sequence 
    // }
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
