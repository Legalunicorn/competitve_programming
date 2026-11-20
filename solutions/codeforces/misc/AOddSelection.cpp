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
    int x;
    cin >> x;
    vi a(n);
    int odd = 0, even = 0;
    for (int i = 0; i < n ;i++){
        int d; cin >> d;
        if (d%2==1) odd++;
        else even++;
    }
    // x elements. even + odd = odd 
    // odd = odd 
    if (x == 1){
        if (odd>0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return;
    }
    for (int i = 1; i <= odd; i+=2){
        int j = x - i;
        if (j<0) break;
        if (i <= odd && j <= even){
            debug(i,j);
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;

    // 1 odd, res even 
    // 3 odd, res even 
    // 5 odd res even etc 1300
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
