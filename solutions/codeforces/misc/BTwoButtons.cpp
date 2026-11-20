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

void solve(){
    ll n ,m;
    cin >> n >> m;

    // i think you need to do a BFS 
    int d = 0;
    queue<pl> q;
    set<ll> seen;
    seen.insert(n);
    q.push({n,0LL});
    ll res = INF;
    bool found = false;
    while(!q.empty() && !found){
        int len = q.size();
        for (int i=0;i<len;i++){
            auto t = q.front(); q.pop();
            ll v = t.F, cnt = t.S;
            debug(t);
            if (v == m){
                res = min(res, cnt);
                found = true;
                break;
            } else if (v> m){
                res = min(res, cnt + v - m );
                if (v-1>0 && !seen.count(v - 1)) {
                    seen.insert(v-1);
                  q.push({v - 1, cnt + 1});
                }

            } else{
              if (v-1>0 && !seen.count(v - 1)) {
                  seen.insert(v-1);
                q.push({v - 1, cnt + 1});
              }
              if (!seen.count(v * 2)) {
                seen.insert(v*2);
                q.push({v * 2, cnt + 1});
              }
            }
        }
        if (found) break;
    }
    cout << res << endl;

    
    



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
