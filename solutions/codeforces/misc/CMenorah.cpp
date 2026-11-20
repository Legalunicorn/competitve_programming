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


// {0,0}
// {1,0}
// {1,1}
// {0,1} 
//
// NOTE: 
// if solvable, you either need ODD or EVEN no of operations 
//
// NOTE: EVEN 
// -> {1,0} and {0,1} pairs together, 
//
//
// NOTE: ODD 
// -> perform a flip on {1,0} or {1,1} 
// -> generate a new count of 4 cases 
// -> compute if even is possible 
//
// -> compute min of even + odd score 

void solve(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    vi cnt(4);
     // {0,0} {0,1} {1,0} {1,1}
    for (int i = 0; i < n; i++){
        if (a[i] == '0'){
            if (b[i] == '0') cnt[0]++;
            else cnt[1]++;
        } else {
            if (b[i]=='0') cnt[2]++;
            else cnt[3]++;
        }
    }
    int odd = 10*n, even = 10*n;
    if (cnt[2] == cnt[1]) {
        even = cnt[2] * 2; 
    }
    // try odd 
    vi t1(4), t2(4);
    if (cnt[2] > 0){ // {1,0} as pivot 
        t2[2]  = 1 + cnt[0];
        t2[1] = cnt[3];
        if (t2[2] == t2[1] ) odd = 1 + 2 * t2[2];
    }
    if (cnt[3] > 0){
        int two = cnt[0];
        int one = cnt[3] - 1;
        if (one == two) odd = min(odd, 1 + one + two);
    }
    int res = min(odd,even);
    debug(cnt, odd, even);
    if (res > n ) res = -1;
    cout << res << endl;
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
