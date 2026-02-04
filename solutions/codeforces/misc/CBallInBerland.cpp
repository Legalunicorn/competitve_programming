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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){
    int a,b,k;
    cin >> a >> b >> k;
    vpi g(k);
    map<int,int> left,right;
    map<pi,int> both;
    for (int i=0;i<k;i++){
        cin >> g[i].F ;
        left[g[i].F]++;
    }
    for (int i = 0; i < k; i++){
        cin >> g[i].S;
        right[g[i].S]++;
        both[{g[i].F, g[i].S}]++;
    }

    ll res = 0;
    for (int i = 0; i < k; i ++){
        int l = g[i].F, r = g[i].S;
        int dup = left[l] + right[r] - both[{l,r}];
        res+=   k - dup;
    }
    res /=2;
    cout << res << endl;

    // what is a and b even for? 
    //
    // we want the number of ways to select pairs 
    // maybe we can do some kind of counting, then divde by overcount 
    // example (1,2) (1,3) (2,2) (3,4)
    // if we use (1,2) ->  count of all left "1", OR count of all right "2"
    // has to be deleted, then we remove the intersection with cout {1,2}
    // 
    // so 
    // (1,2) 
    // count 1: 2 
    // count 2r: 2 
    // total = 4 
    // then we minus 2* count (1,2)
    // 4 - 2 = 2 
    //
    // (1,2) (1,2) (1,3) (2,2) (3,4)
    //  x     x      x 
    //  y     y            y 
    //  6 - couint pairs = 4 
    //  5 - ans 
    // count 1 left: 3 
    // count 2 right: 3 
    // count same: 2 
    // total = 6 - 4 = 2 
    // 5 - 
    // 
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
