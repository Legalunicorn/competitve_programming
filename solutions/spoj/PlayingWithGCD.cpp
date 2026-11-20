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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

int id;
int n = 100005;
vl p(n);
vl res(n);
void init(){
    for (int i = 1; i < n; i++) p[i] = i;
    for (int i = 2; i < n; i++){
        if (p[i]!=i) continue;
        for (int j = i; j < n; j +=i) p[j] -= p[j]/i;
    }

    for (int i = 1; i < n; i++) res[i] = p[i] + res[i-1];
    for (int i = 0; i < 20; i++) debug(res[i]);
    for (int i = 0; i < 20; i++) debug(p[i]);
}


void solve(){
    id++;
    ll n;
    cin >> n;
    ll val = res[n];
    debug(n, res[n]);
    ll pairs = n * (n+1) / 2;
    ll ans = pairs - val;
    debug(n, pairs, val);
    cout << "Case " << id << ": " << ans << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
