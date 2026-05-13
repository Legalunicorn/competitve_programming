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
// p & q == 0 
// no "1"s in the same splot 
// -> can be "0" and "0"
// -> can be "1" and "0" 
//
//
// we can analyize the bits of "x" and "y" 
// if both == "1" and "1" 
//
// p = x 
// q = y 
//
// then analyze each bits of 'x,y'
// if both one 1 i think we can do some greedy changes 

// a very common strategy to interpret sum as the sum of 
// bit deltas 

void tb(ll x){
    ll t = x;
    string s;
    while(x){
        if(x%2==1) s = '1' + s;
        else s = '0' + s;
        x/=2;
    }
    while (s.size() < 12) s = '0' + s;
    debug(s,t);
}


void solve(){
    ll x ,y;
    cin >> x >> y;
    ll p =x, q = y;
    ll low = INF;
    pl res = {0,0};
    debug(x,y, "ST");
    for (int i = 32; i >=0; i--){
        if ((p>>i &1) && (q>>i&1)){
            if (!(q>>(i+1)) && !(p>>(i+1))) {
                ll tp = 1 << (i+1);
                ll d  = tp-p;
                if (d < low){
                    low = d;
                    res = {p, tp};
                    debug(res, "first");
                }
                
            }
            if (!(q>>(i+1)) && !(p>>(i+1))){
                ll tq = 1 << (i+1);
                ll d = tq-q;
                if (d < low){
                    low =  d;
                    res = {tq, q};
                    debug(res, "sec");
                }
            }
            for (int j = i; j>=0;j--){
                if ((p>>j &1) && (q>>j&1)){
                    p ^= (1<<j);
                } else {
                    p |= (1<<j);
                }
            }
            debug(p,q, "third");
            ll d = abs(x - p) + abs(y - q);
            if (d < low){
                res = {p,q};
            }
            break;
        }
    }
    debug(res);
    cerr << endl;
    cout << res.F << " " << res.S << endl;
    // cout << p << " " << q << endl;
    // ll p = x, q = y;
    // for (int i = 0; i < 35; i++){
    //     if ((x >> i & 1) && (y >> i & 1)){
    //         p ^= (1 << i);
    //     }
    // }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
