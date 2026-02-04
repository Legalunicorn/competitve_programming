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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;


// only even can half the nume r

void solve(){
    ll n,k;
    cin >> n >> k;
    k = min(k, 30LL);


    set<ll> seen;//maybe switch to dfs 
    queue<ll> q;
    q.push(1);
    ll tot = 0;
    int depth = 1;
    while(!q.empty() && depth<=k){
        int l = q.size();
        tot += l;
        for (int i=0;i<l;i++){
            ll x  = q.front(); q.pop();
            debug(x,depth);
            ll p1 = x + 1;
            ll t2 = x * 2;
            if (p1 <= n && !seen.count(p1)) {
                seen.insert(p1);
              q.push(p1);
            }
            if (t2 <= n && !seen.count(t2)) {
                seen.insert(t2);
              q.push(t2);
            }
        }
        depth++;
    }
    debug(tot);
    cout << n - tot << endl;





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
