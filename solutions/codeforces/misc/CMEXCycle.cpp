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

// 


void solve(){
    int n,x,y; 
    cin >> n >> x >> y;
    x--, y--;
    vi a(n);
    debug(n,x,y);
    for (int z = 0; z < 4; z++){
        debug(a);
        for (int i = 0; i < n; i++){
            vi f(5);
            int l = (i + n - 1) % n;
            int r = (i + n + 1) % n;
            // if (n == 3) debug(i,l,r, x, y);
            f[a[l]]++;
            f[a[r]]++;
            if (i == x) f[a[y]]++;
            if (i ==y) f[a[x]]++;
            int evl = 0;
            for (int x = 0; x < 5;x++){
                if (f[x] == 0) {
                    evl = x;
                    break;
                }
            }
            a[i] = evl;
            // if (n==3) debug("ok!");
            // if (n ==3) debug(a);
        }
    }
    for (auto& z: a) cout << z << " ";
    cout << endl;
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
