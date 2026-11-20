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

// the fuck? 
// this question is jsut a bunch of if statments
void solve(){
    int n,pos,l,r;
    cin >> n >> pos >> l >> r;
    int res = 0;
    if (pos < l){
        // go to left
        res += l - pos;
        res ++;
        if (r < n){
            res += r - l;
            res ++;
        }
    } else if (pos <= r){
        if (l > 1 && r < n){
            int d1  = pos - l, d2 = r - pos;
            int mn = min(d1,d2);
            res += mn;
            res += r - l;
            res += 2;
        } else if (l > 1){
            int d = pos - l;
            res += d;
            res ++;
        } else if (r < n){
            int d = r - pos;
            res += d;
            res++;
        }
    } else{ // 
        res += pos - r;
        res++;
        if (l > 1){
            res += r - l;
            res++;
        }
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
