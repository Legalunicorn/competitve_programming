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

// NOTE:
// log MAX n q is allowed 
// for each q -> we solve in n log max 
// we should greedily try to set each bit from MBS to LSB, so long the cost permits
// 

void solve(){
    // mega trivial
    ull n,q;
    cin >> n >> q;
    vector<ull> a(n);
    for (auto& z:a) cin >> z;
    while(q--){
        ull k;
        cin >> k;
        ull res = 0;
        {
            ull left = k;
            // if a number has been increased to fit "1" its suffixed by 0s 
            vb flip(n);
            for (ll b = 60; b >= 0; b--){
                ull loc = 0;
                for (ull i = 0; i < n; i++){
                    if ((a[i] >> b & 1ll) == 0) { // flip or not flip
                        if (flip[i]){
                            loc += (1ll << b);
                        } else{
                            ull mask = ((1ull << (b+1)) -1);
                            ull need = (1ull << b) - (a[i] & mask);
                            loc += need;
                            if (loc > left) break;
                            if (b==60) debug(need,loc);
                        }
                    }  else {
                        if (flip[i]){
                            loc += (1ll << b);
                            if( loc > left) break;
                        }
                    } 
                }
                if (loc <= left){
                    debug(b,loc, left);
                    res |= (1ull<<b);
                    left -= loc;
                    for (ull i = 0; i < n; i++){
                        if (flip[i]) continue; // alreayd fliped
                        if ((a[i]>>b&1)==0) flip[i] = true;
                    }
                }
            }
        }
        cout << res << endl;
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
