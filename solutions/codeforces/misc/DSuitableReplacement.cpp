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

// NOTE:
// this is some limiting factor thing 
// we can binary search 
// 


void solve(){
    string s,t;
    cin >> s >> t;
    debug(s,t);
    vl ft(26,0), fs(26,0);
    for (char c: t) ft[c-'a']++;
    ll q = 0;
    for (char c:s){
        if (c == '?') q++;
        else fs[c-'a']++;
    }
    ll l = 0, r = s.size();
    ll res = l;

    auto check  = [&](ll m) -> bool{
        ll left = q;
        for (int i = 0; i < 26;i++){
            if (fs[i] >= ft[i] * m) continue;
            ll req = ft[i]*m - fs[i];
            if (req > left) return false;
            left -= req;
        }
        return true;
    };
    while(l <= r){
        ll mid = l+(r-l)/2;
        debug(mid);
        bool evl = check(mid);
        debug(mid, evl);
        if (evl){
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    stack<pi> st;
    for (int i = 0; i < 26; i++){
        ll need = ft[i]*res - fs[i];
        if (need > 0) st.push({i, need});
    }
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '?'){
            if (st.empty()) s[i] = 'a';
            else{
                pi p = st.top();
                st.pop();
                s[i] = (char)(p.F + 'a');
                if (p.S > 1) st.push({p.F,p.S-1});
            }
        }
    }
    cout << s << endl;

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
