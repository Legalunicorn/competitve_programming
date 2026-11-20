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



map<int,int> factor(int n){
    map<int,int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res[i]++;
            n /= i;
        }
    }
    if (n>1) res[n]++;
    return res;
}


void solve(){
    ll a,b;
    cin >> a >> b;
    ll q;
    cin >> q;
    ll g = gcd(a,b);
    map<int,int> mp = factor(g);
    while(q--){
        ll l,h;
        cin >> l >> h;
        debug(l,h);
        if (l <= g && h >= g) {
            cout << g << endl;
            continue;
        } if (g < l){
            cout << -1 << endl;
        } else{
            // g > h
            ll tg = g;
            int yes = 0;
            for (auto& [f,c]: mp){
                for (int i = 0; i < c; i++) {
                    tg/=f;
                    if (tg <= h && tg >=l) {
                        cout << tg << endl;
                        yes = 1; break;
                    }
                }
            }
            if (!yes) cout << -1 << endl;
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
