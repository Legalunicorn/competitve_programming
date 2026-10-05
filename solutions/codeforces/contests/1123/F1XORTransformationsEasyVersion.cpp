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

// NOTE: if u just guess forces
// the number of operations is bounded somne how
// 4 number 
// 1,2 1,3 1,4
// 2,3 2,3
// 2,4
//
//

void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    // vvi res(3);
    vi res(32);
    res[0] = a.back() - a.front();
    for (int z = 0; z < 31; z++){
        debug(z, a);
        vi b;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                b.pb(a[i]^a[j]);
            }
        }
        sort(all(b));
        a.clear();
        for (int i = 0; i < n; i++) {
            a.pb(b[i]);
        }
        res[z+1] = a.back() - a.front();
    }
    // cerr << endl;
    debug(res);
    while(q--){
        int x;
        cin >> x;
        if (x > 31) x =31;

        cout << res[x] << endl;
    }
    // cerr << endl;
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
