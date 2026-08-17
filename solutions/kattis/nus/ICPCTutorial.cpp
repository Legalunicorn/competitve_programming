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
    ll m,n,t;
    cin >> m >> n >> t;
    // decide if it can pass! 
    if (t == 1){
        // factorial gets big very fast 
        ll tot = 1;
        for (int i = 1; i <= n; i++){
            if (tot > m) break;
            tot *= i;
            if (tot > m) break;
        }
        if (tot > m) cout << "TLE" << endl;
        else cout << "AC" << endl;

    } else if (t == 2){
        ll tot = 1;
        for (int i = 1; i <= n; i++){
            if (tot > m) break;
            tot *= 2;
            if (tot > m) break;
        }
        if (tot > m) cout << "TLE" << endl;
        else cout << "AC" << endl;

    } else if (t == 3){
        ll tot = n;
        if (n * n > m || n * n * n > m || n * n * n * n >m) cout << "TLE" << endl;
        else cout << "AC" << endl;

    } else if (t == 4){
        if (n * n > m || n * n * n >m) cout << "TLE" << endl;
        else cout << "AC" << endl;

    } else if (t == 5){
        if (n * n > m) cout << "TLE" << endl;
        else cout << "AC" << endl;

    } else if ( t== 6){
        if (n > m){
            cout << "TLE" << endl;
            return;
        }

        if (n * log2(n) > m) {
            cout << "TLE" << endl;
        } else cout << "AC" << endl;
    } else if ( t==  7){
        if (n > m) cout << "TLE" << endl;
        else cout << "AC" << endl;
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
