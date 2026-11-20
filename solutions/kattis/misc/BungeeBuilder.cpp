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

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    vi pf = a, sf = a;
    for (int i = 1 ; i < n; i++) pf[i] = max(pf[i], pf[i-1]);
    for (int i = n - 2; i >= 0; i--) sf[i] = max(sf[i], sf[i+1]);
    int res = 0;
    for (int i = 1; i + 1 < n; i++){
        int l = pf[i-1], r= sf[i+1];
        if (l < a[i] || r < a[i]) continue;
        res = max(res, min(l,r) - a[i]);
    }
    cout << res << endl;
    // // this is monoo stack problem
    // // we cannot have anyone to our side that is larger than us 
    // int base = a[0], res =0;
    // for (int x =0; x < 2; x++){
    //     base = a[0];
    //     stack<int> st;
    //     for (int i = 0; i < n; i++){
    //         while(st.size()>0 && st.top() > a[i])  st.pop();
    //         st.push(a[i]);
    //         if(st.size() == 1) base = a[i];
    //         res = max(res, a[i] - base);
    //         debug(i, a[i], base);
    //     }
    //     reverse(all(a));
    // }
    // cout << res << endl;
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
