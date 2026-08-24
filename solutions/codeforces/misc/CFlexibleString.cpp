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
// Obsevation on oberations: 
// - if u remove some character: its add to Q, u can replace wit hANYTHING
//
// isnt this super trivial?
// 1. enumerate all size k subsets of at most 10 characters
//      2. for each of those, replace a[i] with b[i] if a[i] in subset
//      3. two pointer and check the cout
// 
// isnt it trivial ? hh
void solve(){
    int n,k;
    cin >> n >> k;
    string a,b;
    cin >> a >> b;
    set<char> st;
    for (char c: a) st.insert(c);
    vector<char> chs;
    for (auto& z: st) chs.pb(z);
    // we only need size k 
    ll res = 0ll;
    // vb status(chs.size());
    vb status(27);
    auto dfs = [&](auto& dfs, int i, int left) -> void{
        if (left < 0) return;
        if (i == chs.size()){
            if (left >= 0){
                // exaclty k characters selected
                string c = a;
                for (int i = 0; i < n; i++){
                    if (status[c[i]-'a']) c[i] = b[i];
                }
                // set c = b when possible thne start two pointer 
                ll cnt = 0;
                for (int i = 0, j = 0; i < n; i++){
                    if (j < i) j = i; // reset j minially?
                    while(j < n && c[j] == b[j]){
                        j++;
                    }
                    if (c[i] == b[i]) cnt += (j - i);
                }
                res = max(res, cnt);
            }
            return;
        }
        // choose i 
        int idx = chs[i] - 'a';
        status[idx] = true;
        dfs(dfs,i+1,left-1);
        status[idx]=  false;
        dfs(dfs,i+1,left);
    };
    dfs(dfs, 0, k);
    cout << res << endl;
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
