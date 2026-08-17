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



// we split it into how oftn each bit appears 
// "1" -> for all odd numbers 
// "-1" apears at { 2, 3 }
// NOTE 
// 1. for each bit -> we track the first time it appears 
// then we know 
// 1. how many times it appear then stop then appear then stop 
// we divid (N - appear) / (size)
// 0 0 0 1 
// 0 0 1 0
// 0 0 1 1 
// 0 1 0 0
// 0 1 0 1 
// 0 1 1 0
// 0 1 1 1 
// 1 0 0 0
// 1 0 0 1 
// 1 0 1 0 
// 1 0 1 1 
void solve(){
    ull n;
    cin >> n;
    ull res = 0;
    for (int b = 0; b < 64; b++){
        ull t = 1LL << b;
        debug(b, t);
        if (n < t) break;
        ull gap = t; 
        ull q = (n - t + 1) / t;
        ull m = (n - t + 1) % t;
        if (q%2 == 0){
            res += (q/2) * t;
            res += m;
        } else{
            res += ((q+1)/2) * t;
        }

        // {x x x .. gap} {. . . . gap } {x x x  gap} .. and so in 
    }
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
