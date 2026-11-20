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
// how do we find the min swaps 
// its trivial to see if its possible 
// b[i] >= a[i] 
// for all i is the end result
//

void solve(){
    // this is greedy right ? 
    // we need to match thhe thing
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    // we want to preserve the max that do not change 
    // 1. first check that its possible 
    // assume its possible 
    // condition: a[i] >= b[i] 
    // for all paiars 
    // thne we clear the bigger first 
    vi aa = a;
    vi bb = b;
    sort(all(aa));
    sort(all(bb));
    for (int i = 0; i < n; i++){
        if (b[i] < a[i]){
            cout << -1 << endl;
            return;
        }
    }
    vpi ta(n);
    for (int i = 0; i < n; i++) ta[i] = {a[i], i};
    sort(all(ta));
    vi tb(n);
    for (int i = 0; i < n; i++){
        int p = ta[i].S;
        tb[i] = b[p];
    }
    int cnt = 0;
    // what the hell im not sure
    for (int i = n -1; i >= 0; i --){
        // if a[i] 
    }
    
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
