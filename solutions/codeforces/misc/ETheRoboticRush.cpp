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
    // i solved this before but i guess just somve it again 
    // k integers after k instructions 
    // for each robot find 
    // 1. closest left 
    // 2. closest right 
    // initialize alive = n 
    // maintain {left_dist, list robots} {right_dist, list_robots}
    // seen left dist, seen right dist 
    ll n,m,k;
    cin >> n >> m >> k;
    vl a(n);
    for (auto&z:a) cin>>z;
    sort(all(a));
    vl b(m);
    for (auto&z:b) cin>>z;
    b.pb(-INF);
    b.pb(INF);
    sort(all(b));
    string s; 
    cin >> s;
    // set<ll> lseen, rseen;
    set<ll> dtseen;
    map<ll,vl> ld, rd;
    // map<ll,ll> rd;
    // for each robot find closest left and right 
    // just binary search fuck two pointer
    auto right = [&](ll p) -> ll {
        int l = 0, r = b.size()-1;
        int res = r;
        while(l<=r){
            int mid = (r+l)/2;
            if (b[mid]>=p){
                res = mid;
                r = mid - 1;
            } else l = mid+1;
        }
        return res;
    };
    auto left = [&](ll p) -> ll {
        int l = 0, r = b.size()-1;
        int res = 0;
        while(l<=r){
            int mid = (r+l)/2;
            if (b[mid]<=p){
                res = mid;
                l = mid+1;
            } else r = mid-1;
        }
        return res;
    };
    debug(a);
    debug(b);

    for (int i = 0; i < n; i++){
        ll pos = a[i];
        ld[pos - b[left(pos)] ].pb(i);
        rd[b[right(pos)] - pos].pb(i);
    }
    debug(rd);
    debug(ld);
    ll dt = 0;;
    ll alive = n;
    set<int> dead; // cannot die twice
    for (char c: s){
        if (c == 'L') dt--;
        else dt++;
        debug(dt);
        if (!dtseen.count(dt)){
            dtseen.insert(dt);
            if (dt < 0){
                for (auto& v: ld[abs(dt)]){
                    if (!dead.count(v)) {
                        dead.insert(v);
                        alive--;
                    }
                }
            } else {
                for (auto& v: rd[abs(dt)]){
                    if (!dead.count(v)) {
                        dead.insert(v);
                        alive--;
                    }
                }
            }
            // alive -= rd[dt];
        }
        cout << alive << " ";
    }
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
