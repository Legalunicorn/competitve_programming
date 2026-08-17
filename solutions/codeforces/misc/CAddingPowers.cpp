#include <bits/stdc++.h>
#include <iomanip>
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
    int n,k;
    cin >> n >> k;
    vl a(n);
    for(auto& z:a) cin >>z;
    ll lim = MAX(a);
    vl pow = {1LL};
    ll curr = 1;
    for (int i=0;i<=500;i++){
        curr *= k;
        if (curr > lim) break;
        pow.pb(curr);
    }
    int j = 0;
    sort(a.rbegin(),a.rend());
    reverse(all(pow));
    debug(a);
    debug(pow);
    vb used(pow.size(), false);
    for (int i =0;i<n;i++){
        for (int j = 0; j <pow.size(); j++){
            if (pow[j] <= a[i] && !used[j]){
                a[i] -= pow[j];
                used[j] = true;
            }

        }
            if (a[i]!=0) {
                debug(a,i,pow);
                cout << "NO" << endl;
                return;
            }
    }
    cout << "YES" << endl;
    //n  = 30
    // k =100 
    // 100 ^ 30 too god damn big 
    // we can only use i on one number 
    // and the number must be constructed usinf some powers of k^i 
    // we only need to consider powers 
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
