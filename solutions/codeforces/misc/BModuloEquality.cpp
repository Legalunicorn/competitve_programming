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

// guaranteed its possible 
// and all numbers < m 
// doesnt it mean there is some equivalnt class goung on ? 
// we have a count of frequencyes 
// for every element in a[i] we can try to make it b[0] 
//

// NOTE:
// its not just counter of frequency its a sequence of frequencies 
// the order here dont matter 
// sort both 
// then jus try a[i] to b[0] start, x is determined and check if its possible
//


void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    ll res = INF;
    sort(all(a));
    sort(all(b));
    debug(a);
    debug(b);
    for (int i = 0; i < n; i ++){
        // a[i] -> b[0];
        ll x = 0;
        if (a[i] > b[0]) x = (m - a[i]) + b[0];
        else if (a[i] < b[0]) x = b[0] - a[i];
        bool valid = true;
        debug(i,x);
        for (int j = 0; j < n; j++){
            if (((a[(i+j)%n]+x) % m) != b[j]) {
                debug(j,a[i+j], b[j]);
                valid = false;
                break;
            }
        }
        if (valid) res = min(res, x);
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
