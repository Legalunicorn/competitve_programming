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
// lets order the multiples of g between 
// 1 2 3 4 5 6 7 8 9 10 11 12 ... 
// (x)g (x+1) g 
// gcd(a,b) = g 
// gcd(a/g, b/g) = 1 
// ie. (a/g) and (b/g) are coprime

// PERF: trivial case: no pairs
// Range <= g 
//  1. contains g, output g g 
//  2. else outout -1 -1
//
// PERF: gcd(a,b) = g  --> gcd(a/g, b/g) = 1 
// if gcd(a/g, b/g) != 1, then we can factor out k, and gcd(a,b) = gk
//
// PERF: from [L,R] we are to find a coprime pair [a/g, b/g] 
// such that |b-a| is maximised
//
// PERF: we can reduce the mapping of [L,R] to [X,Y] = [ceil(L/G), floor(R/G)] 
// 
// 10 - 40
// ceil(10/6) = 2
// floor(40/6) = 6
// 6 12 18 24 30 36
//   2   3  4 5 6 
//
//  now we just need to find the furtherest co-prime pair from [X,R]
// 

void solve(){
    ll l,r,g;
    cin >> l >> r >> g;
    l = (l+g-1)/g;
    r = r/g;
    int i = 0;
    pl res ={r+1,r+1};
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; j++){
            ll x = l+i, y = r-j;
            if (x<=y){
                if (__gcd(x,y) == 1){
                    ll d = y-x;
                    if (d > res.S-res.F){
                        res = {x,y};
                    } else if (d == res.S-res.F){
                        if (x < res.F) res = {x,y};
                    }
                }
            }
        }
    }
    if (res.F == r+1) cout << "-1 -1" << endl;
    else cout << res.F*g << " " << res.S*g << endl; 
        
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
