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
    vi a(n); // start
    for(auto& z:a) cin >> z;
    vi b(n); // found
    for (auto& z:a) cin >> z; 
    // a -> b 
    int m; cin >> m;
    vi op(m);
    for (auto& z:op) cin >> z;
    map<int,int> mp;
    set<int> st(all(b));
    for (int i = 0; i < m ; i++){
        if (a[i] != b[i]) mp[b[i]]++;
    }
    for (auto& d: op){
        if (mp[d]>0){
            mp[d]--;
            if (mp[d]==0) mp.erase(d);
        } else{
            // if this number already exiss,
        }
    }
    // we are give nthe values 
    // so we just need to map a to b, where b has some value 
    // if a[i] = b[i] we ignore 
    // otherwise we need some random transition from {x,d}
    // or {d} and with access we just need to check if its exists
    // what if we are forced to change something?.. who do we change 
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
