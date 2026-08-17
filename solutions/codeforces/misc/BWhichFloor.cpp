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

//variables and functions
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

//



void solve(){
    int n,m;
    cin >> n >> m;
    if (m == 0){
        cout << (n == 1 ? 1 : -1) << endl;
        return;
    }
    int count = 0; // valid k 
    int kans = -1; 
    set<int> res;
    // map<int,vi> mp;
    set<pi> st;
    debug(count,kans);
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        st.insert({b,a});
        // mp[b].pb(a);
    }
    debug(st);
    for (int k = 1; k <= 101; k++ ){
        bool valid = true;
        for (const auto& [floor, num]: st){
            if (k==2) debug((num-1)/k, floor-1);
            if ((num-1)/k  != floor-1){
                valid = false;
            }
        }
        if (valid){
            int evl = ((n-1)/k)+1;
            debug(k,evl);
            res.insert(evl);
        }
    }
    debug(res);
    if (res.size()!=1) cout << -1 << endl;
    else cout << *res.begin() << endl;
   

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
