#include <bits/stdc++.h>
#include <queue>
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

void solve(){
    ll q,v;
    cin >> q >> v;
    // v is the maximum
    // just unplug one 
    // we can unplug the highesty? 
    // actually we can ignore "v" its useless 
    // when we add T1... the later at T3
    // what matters is only the time elasped
    ll excess = 0;
    // priority_queue<ll, vl, greater<ll>> pq;
    priority_queue<ll> pq;
    // rebase all to 0
    //
    while(q--){
        ll id, t, w;
        cin >> id;
        if (id == 1){
            cin >> t >> w;
            ll zero = w - t;
            pq.push(zero);
        } else{
            cin >> t;
            if (pq.size()==0){
                cout << -1 << endl;
            } else{
                ll top = pq.top(); pq.pop();
                ll real = min(v, top + t);
                cout << real << endl;
            }

        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
