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

void solve(){
    int n;
    cin >> n;
    vi sz(n);
    for (int i= 1;i < n;i ++){
        int x; cin >> x;
        x--;
        sz[x]++;
    }
    sz.pb(1);
    vi a,c;
    for (auto& x: sz) if (x>0) a.pb(x);
    int res = a.size();
    sort(a.rbegin(),a.rend());
    debug(a);
    for (int i = 0; i < a.size(); i++){
        int x = a[i] - (a.size() - (i+1))-1;
        if (x>0) c.pb(x);
    }
    sort(c.rbegin(),c.rend());
    a = c;
    while(a.size() > 0 && a[0]>0){
        debug(a);
        res++;
        vi b;
        int c;
        for (int i = 0; i < a.size(); i++){
            if (i==0) c = a[i]-2;
            else c = a[i]-1;
            if (c>0) b.pb(c);
        }
        a = b;
        sort(a.rbegin(),a.rend());
    }
    debug("     ");
    cout << res << endl;
    // for (int i = 0; i < a.size(); i++){
    //     a[i] = a[i] - (n - i);
    // }

    // for (int i = 0; i  < n ; i++){
    //     if (sz[i] > 0) cnt++;
    //     else break;
    // }
    
    // tried to solve with math, not possibe 
    // simulation within 


    // int res = cnt;
    // int extra = 0;
    // vi ex;
    // // cnt moves 
    // for (int i = 0; i  < n ; i++){
    //     if (sz[i] == 0) break;
    //     int ord = i+1;
    //     int rem = (sz[i] - (cnt - ord)  );
    //     // extra = max(extra, rem/2);
    //     // when we make extra moves, only one guy gets double 
    //     // the rest only gets one 
    //     if (rem/2 > 0) res = max(res,cnt + rem/2);
    //
    // }
    // cout << res << endl;
    //
    // debug(sz);
}


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
