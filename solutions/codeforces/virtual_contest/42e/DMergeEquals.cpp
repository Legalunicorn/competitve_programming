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


// for each number , i can maintain a PQ 
void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    int len = n;
    map<ll, priority_queue<int,vi,greater<int>> > mp;
    // maybe i need to maintain a set of elemets with atleast two
    set<ll> cand;
    for (int i = 0; i < n; i++){
        mp[a[i]].push(i);
    }
    for (auto& [x, pq] : mp){
        if (pq.size() > 1) cand.insert(x);
    }
    vl ans = a;
    debug(cand);
    while(cand.size() > 0){
        ll x = *cand.begin();
        int i = mp[x].top();
        mp[x].pop();
        int j = mp[x].top();
        mp[x].pop();
        ans[i] = -1;
        ll y = 2 * x;
        ans[j] = y;
        mp[y].push(j);
        debug(x,i,j);
        // adjust the stuff 
        if (mp[x].size() < 2) cand.erase(x);
        if (mp[y].size() == 2) cand.insert(y);
    }
    vl res;
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) res.pb(ans[i] );
    }
    cout << res.size() << endl;
    for (auto& r: res) cout <<r << " ";
    



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
