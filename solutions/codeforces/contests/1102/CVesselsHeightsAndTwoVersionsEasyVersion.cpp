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
    vl res(n); // looks just like some greedy toi me 
    vl lim(n);
    vl ans(n);
    for(int s = 0; s < n; s++){
        lim.assign(n,INF);
        lim[s] = 0;
        int b = (s - 1 + n) % n;
        lim[b] = a[b];
        ll cur = a[s];
        for (int i = 1; i < n; i++){
            int p =  (s + i) % n;
            lim[p] = min(lim[p], cur);
            cur = lim[p];
            if (lim[p] <= a[p]){
                cur = a[p];
            }
        }
        for (int i = n - 1; i > 0 ; i--){
            int one = (s + i + n) % n;
            int two  = (s + i -1 + n) % n;
            if (max(lim[one], lim[two]) > a[two] && lim[one] != lim[two]){
                ll mn = min(lim[one], lim[two]);
                ll mx = max(mn, a[two]);
                lim[one] = min(lim[one], mx);
                lim[two] = min(lim[two], mx);
            }
        }
        debug(lim);
        ll tot = 0;
        for (auto& z: lim) tot += z;
        res[s] = tot;
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
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
