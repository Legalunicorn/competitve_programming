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
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    // what if multiple same? 
    // 4 4 4 6 7 8 (9 9 9) 10 11 12 (13 13 13)
    // each number can below to both sides at most once
    // construct the left side first
    vb used(n);
    vl left, right;
    set<ll> st;
    // construct left first
    for (int i = 0; i < n; i++){
        if (!st.count(a[i])){
            st.insert(a[i]);
            used[i] = true;
            left.pb(a[i]);
        }
    }
    st.clear();
    for (int i =0 ;i < n;i++){
        if (used[i]) continue;
        if (st.count(a[i])) continue;
        st.insert(a[i]);
        used[i] = true;
        right.pb(a[i]);
    }
    int k = left.size() + right.size();
    reverse(all(right));
    vi res;
    for (auto& z: left) res.pb(z);
    for (int i = 0; i < n; i++){
        if (!used[i]) res.pb(a[i]);
    }
    for (auto& z: right) res.pb(z);
    cout << k << endl;
    for (auto& z: res) cout << z << " ";
    cout << endl;



};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
