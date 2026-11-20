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

// map pos ? 
// amortized analysis? 
// the max gap gives some details 
// for each number 
// find the max gap in adjanet numbers 
// we count the start and end as well 
// so from 1 -> N 
// the smaller then k the smaller gap we need 
// i think we can maintain the gaps[0..N] and store the min for each 
// the consider the min as we go down


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    map<int, vi> pos;
    for (int i = 0; i < n; i++){
        pos[a[i]].pb(i);
    }
    vi gap(n+1, n*10);
    for (auto& [val, ls]: pos){
        // we want the limiting factor -> mx gap
        int mx = max(ls.front(), n -1 - ls.back());
        for (int i = 1; i < ls.size(); i++){
            mx = max(mx, ls[i] - ls[i-1] -1);
        }
        gap[mx+1] = min(gap[mx+1], val);
        debug(val, mx+1);
    }
    debug(gap);

    int msf = n*10;
    for (int k = 1; k <= n; k++){
        msf = min(msf, gap[k]);
        cout << (msf == n*10? -1 : msf) << " ";
    }
    cout << endl;

    // is this some amortized bullshit 
    // k = 1 to n 
    // for each k -> we do a 
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
