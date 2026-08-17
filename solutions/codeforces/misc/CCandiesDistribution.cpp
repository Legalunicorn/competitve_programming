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

// probalby 
// 1. figure out if it is possible 
// 2. find some kind of order or same level 
// impossible case 
// 1) (obvious) cannot have more children than number 
// 2) 2. if L == L, then R might = R 
//
//
// 3. L = L does not imply equality ! 
// 1. comput graph solely based on < or > 
// for nodes that got skipped, it means they share with a neighbour or something 
// the thing about graph is only depth implies value 
//

void solve(){
    int n;
    cin >> n;
    vi a(n),b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;

    vi res(n,0);
    for (int i=0;i<n;i++){
        int x = n - a[i] - b[i];
        if (x >n || x < 0 || a[i]+b[i]>n-1 ){
            debug(i,x);
            cout << "NO" << endl;
            return;
        }
        res[i] = x;
    }
    debug(res);
    for (int i=0;i<n;i++){
        int lc = 0, rc = 0;
        for (int j = 0; j< n; j++){
            if (j < i && res[j] > res[i] ) lc++;
            if (j > i && res[j] > res[i]) rc++;
        }
        if (lc != a[i] || rc != b[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto& x:res)cout << x <<  " ";
    cout << endl;




    // lesser = n - (l + r)
    // we sort by lesser value 
    // then simply assign? 
    // the fuck? a[i] = n - li - ri, why? 
    // oh yea



    // vvi g(n);
    // for (int i=0; i<n ;i++){
    //     if( a[i] > i || b[i] > n - i - 1){
    //         cout << "NO" << endl;
    //         return;
    //     }
    // }
    // for (int i = 1; i < n; i++){
    //     if (a[i]<a[i-1] && b[i]>b[i-1] || a[i]>a[i-1] && b[i]<b[i-1]){
    //         cout << "NO" << endl;
    //         debug("cycle");
    //         return;
    //     }
    //     if (a[i]>a[i-1]) g[i-1].pb(i);
    //     else if (a[i]< a[i-1]) g[i].pb(i-1);
    //     if (b[i]> b[i-1]) g[i-1].pb(i);
    //     else if (b[i] < b[i-1]) g[i].pb(i-1);
    // }
    // // I assume there is no cycles from this > 
    // vi res(n,-1);
    // vb seen(n, false);
    // bool invalid = false;
    //
    // auto dfs = [&](auto& dfs, int u, int d) -> void{
    //     res[u] = d;
    //     seen[u] = true;
    //     for (int v: g[u]){
    //         if (seen[v]) continue;
    //     }
    // }
    //
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
