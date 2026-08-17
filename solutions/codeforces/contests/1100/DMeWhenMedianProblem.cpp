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

// NOTE: 
// might be a divide and conquery problem 
// s3 -> upper quartile 

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto& z: a) cin >> z;
    for (auto& z: b) cin >> z;
    debug(a,b,n);
    if (n ==1){
        cout << min(a[0], b[0]) << endl;
        return;
    }

    auto go = [&](auto& go, int l, int r) -> pi {
        if (l + 1 == r){
            vi t = {a[l], a[l+1], b[l], b[l+1]};
            sort(all(t));
            return {t[1], t[2]};
        } else if (l + 2 == r){
            vi t = {a[l], a[l+1], b[l], b[l+1]};
            sort(all(t));
            vi t2 = {t[1],t[2], a[l+2], b[l+2]};
            sort(all(t2));
            
            vi u = {a[l+1], a[l+2], b[l+1], b[l+2]};
            sort(all(u));
            vi u2 = {u[1], u[2], a[l], b[l]};
            sort(all(u2));

            int tr = min(t2[1], t2[2]);
            int ur = min(u2[1], u2[2]);
            pi T = {t2[1], t2[2]};
            pi U = {u2[1], u2[2]};

            if (tr > ur)  return T;
            else if (tr < ur) return U;
            else {
                int mt = max(t2[1], t2[2]);
                int mu = max(u2[1], u2[2]);
                if (mt >= mu) return T;
                else return U;
            }
        } else {
            int mid = (l+r)/2;
            pi left = go(go,l, mid);
            pi right = go(go, mid+1, r);
            vi t = {left.F, left.S, right.F, right.S};
            sort(all(t));
            return {t[1], t[2]};
        }
    };

    pi res = go(go, 0, n-1);
    cout << res.F << endl;
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
