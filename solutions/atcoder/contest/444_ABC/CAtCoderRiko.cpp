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
    vl a(n);
    for (auto& z:a) cin >> z;

    if (n == 1){
        cout << a[0] << endl;
        return;
    }


    sort(all(a));
    map<ll,int> mp;
    for (auto& z: a) mp[z]++;

    vl res;
    ll mx = a[n-1];
    bool valid = true;

    // val = mx, means its fine 
    for (auto& [val,cnt]: mp){
        if (val == mx) continue;
        ll inv = mx - val;
        if (val + val == mx){
            if (cnt % 2 != 0){
                valid = false;
                break;
            }
        } else if (mp[inv]!=cnt){
            valid = false;
            break;
        }
    }
    if (valid) res.pb(mx);

    valid = true;
    ll chk = a[0] + a[n-1];
    for (auto& [val,cnt]:mp){
        ll inv = chk - val;
        if (val + val == chk){
            if ( (cnt%2) !=0){
                valid = false;
                break;
            }
        } else if (mp[inv] != cnt ){
            valid = false;
            break;
        }
    }
    if (valid) res.pb(chk);
    for(auto& z: res) cout << z << " ";
    cout << endl;

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
