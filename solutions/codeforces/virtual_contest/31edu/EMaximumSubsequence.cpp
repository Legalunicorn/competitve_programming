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
    int n,m;
    cin >> n >> m;
    vi a(n);
    for (auto& z:a) cin >> z;
    int h = n/2;
    vi one,two;
    for (int i = 0; i < n; i++){
        if (i < h) one.pb(a[i]);
        else two.pb(a[i]);
    }
    int l = one.size();
    int mask = 1 << l;
    vi first;
    for (int ms = 0; ms < mask; ms++){
        ll sum = 0;
        for (int i = 0; i < one.size(); i++){
            if (ms >> i & 1) sum = (sum + one[i]) % m;
        }
        first.pb(sum);
    }
    ll res = 0;
    sort(all(first));
    debug(first);
    ll back = first.back();
    debug(back);
    l = two.size();
    mask = 1 << l;
    // they are less than 2m for suure 
    // 1. we find the sum that sums to m-1 
    // 2. we find the sum that is as large as possible 
    for (int ms = 0; ms < mask; ms++){
        ll sum = 0;
        for (int i = 0; i < two.size(); i++){
            if (ms >> i & 1) sum = (sum + two[i]) % m;
        }
        res = max(res, sum);
        res = max(res, (sum + back)%m);
        ll rem = m - sum;
        debug(sum, rem);
        // find the largest number in first less tham rem 
        auto evl = lower_bound(all(first), rem);
        if (evl != first.begin()){
            evl--;
            res = max(res, sum + *evl);
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
