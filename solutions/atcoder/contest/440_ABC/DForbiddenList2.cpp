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

void solve(){
    int n,q;
    cin >> n >> q;
    vl st(n);

    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        st[i] = x;
    }
    sort(all(st));

    while(q--){
        ll x,y;
        cin >> x >> y;
        ll l = x + y - 1;
        ll r = (ll)10e11;
        ll res = r;

        int left = lower_bound(all(st), x) - st.begin();

        while(l<=r){
            ll m = l + (r-l)/2;
            int right = upper_bound(all(st),m) - st.begin();
      
            ll df = m - x + 1 - right + left;

            if (df == y){
                res = m;
                r = m -1;
            } else if (df > y){
                r = m -1;
            } else l = m +1;
        }
        cout << res << endl;

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
