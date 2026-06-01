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
    ll n,d;
    cin >> n >> d;
    vl a(n);
    for (auto& z: a) cin >> z;
    ll amt = 0;
    vl track(n);
    for (int i = 0; i < n; i++){
        amt += a[i];
        if (amt > d){
            cout << -1 << endl;
            return;
        }
        track[i] = amt;
    }
    for (int i = n -2 ; i >=0; i--) track[i] = max(track[i], track[i+1]);
    debug(amt, a);
    amt = 0;
    ll offset = 0ll;
    int res = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 0) {
            if (amt < 0){
                ll best = d - track[i] - offset;
                if (abs(amt) > best){
                    cout << -1 << endl;
                    return;
                }
                amt += best;
                offset += best;
                res++;
            }
            continue;
        }
        amt += a[i];
        if (amt > d){
            cout << -1 << endl;
            return;
        }
    }
    cout << res << endl;
    return;
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
