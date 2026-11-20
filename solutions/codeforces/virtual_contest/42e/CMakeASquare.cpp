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
    // 10e9 -> 
    ll n;
    cin >> n;
    set<string> st;
    for (int i = 1; i <= 200000; i++){
        ll x = i;
        ll y = x * x;
        st.insert(to_string(y));
    }
    // it mask this 
    string s = to_string(n);
    int l = to_string(n).size();
    debug(l);
    int MASK = 1 << l;
    int res = 100;
    for (int m = 0; m < MASK; m++){
        // which characters to remove 
        string t = "";
        int cnt = l;
        for (int i = 0; i < l ; i++){
            if (m >> i & 1) {
                t += s[i];
                cnt--;
            }
        }
        debug(t);
        if (st.count(t) && t.size() > 0){
            res = min(res, cnt);
        }
    }
    if (res == 100) res = -1;
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
