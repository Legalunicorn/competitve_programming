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
    int n; 
    cin >> n;
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    int m;
    cin >> m;
    vi c(m);
    for (auto& z:c) cin >> z;
    set<int> st;
    map<int,int> mp;
    // there is NO order here
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]) mp[b[i]]++;
        else st.insert(a[i]); // extra
    }
    
    debug(st);
    debug(mp);
    cerr << endl;
    // c[m] -> new values NO ORDER 
    for (int i = 0; i < m ;i ++){
        int x = c[i];
        if (mp[x] > 0){
            mp[x]--;
            if (mp[x] == 0) st.insert(x);
        } else {
            if (st.count(x) || i != m-1) continue;
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    for (auto& [v,c]: mp){
        if (c >0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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
