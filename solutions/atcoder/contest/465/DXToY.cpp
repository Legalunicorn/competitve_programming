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



// y / K = x -> y > x 
// y  = x/k ->  y < x 
// im guessing its either optiomal to 
// down, up, down ,
// up ,dow, up 
// or down/up directely 
// mult is log MAX 



// NOTE:
// what if we spam either operation     
// x/K -> 0 
// for operation 2  we can choose [x * k, x * (k+1) - 1]
//
// NOTE: try to think backwards 
// if floor(Y/K) =x 
// let W = floor(Y/K) 
//
// if floor(x/K) = Y, 
void solve(){
    ull x,y,k;
    cin >> x >> y >> k;
    int res = 200; // max operations 
    if (x  == y){
        cout << 0 << endl;
        return;
    }
    ull t = x;
    int used = 0;
    while(t >= 0){
        int cnt = 0;
        ull v = t;
        // try to make v  -> y ??? 
        if (v == y) res = min(res, used);
        ull yy = y;
        while(yy > v){
            yy /= v;
            cnt++;
        }
        res = min(res, used + cnt);
        if (t == 0) break;
        t /= k;
        used++;
    }
    cout << res << endl;
    // x < y ? 
    // if we divide it down we can multioply it back up easily

};


// NOTE: 
// the floor operation is very trick  idk 
// we get like a range of values to work with
// NOTE: can we try a meet in the middle approach 
// we are bounded by like maybe 40 operations 
// if we try both ways? 
// too complicated 
// [y/k] = x 
// i think this is some bullshit 
// like we check the big ooperatation first 
// x = xk, repeatedly 
// then we check if it can divide down to the answer 
// 10e5 cases, means we have 10e3 max operation per tc 
// so this is not some dfs bullshit 
//

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
