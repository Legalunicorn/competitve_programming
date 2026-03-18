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
    string s;
    cin >> s;
    // split by plus and equals 
    string a,b,c;
    int p = 0, eq = 0;
    set<char> st;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '+') p = i;
        if (s[i] == '=') eq = i;
        if (s[i] != '=' && s[i]!='+') st.insert(s[i]);
    }
    a = s.substr(0, p);
    b = s.substr(p+1, eq - p - 1);
    c = s.substr(eq+1, s.size() - eq);

    vector<char> g;
    for (auto& z: st) g.pb(z);
    int n = g.size();

    vi used(10, -1);

    unordered_map<char,int> mp;
    for (int i = 0; i < n; i++){
        mp[g[i]] = i;
    }
    
    reverse(all(a));
    reverse(all(b));
    reverse(all(c));
    debug(a,b,c);
    debug(g);
    // g[i] 
    //
    vi ass(n, 0); // chid -> 
    string res = "";

    // need to prune further

    auto go = [&](auto& go, int i) -> bool{
        if (i == n) {
    
            int x = 0, y = 0, z = 0;
            for (int j = 0; j < a.size(); j++) {
                int cid = used[a[j]];
                int dig = mp[cid];
                x += dig;
                if (j != a.size() -1) x *= 10;
            }
            for (int j = 0; j < b.size(); j++){
                int cid = used[b[j]];
                int dig = mp[cid];
                y += dig;
                if (j != b.size() -1) y *= 10;
            }
            for (int j = 0; j < c.size(); j++){
                int dig = mp[used[c[j]]];
                z += dig;
                if (j != c.size() - 1) z *=10;
            }
            if (x + y == z){
                debug(used);
                debug(ass);
                debug(x,y,z);
                res = to_string(x) + "+" + to_string(y) + "=" + to_string(z);
                return true;
            }
            return false;

        } else{
            for (int d = 0; d <= 9; d++){
                if (used[d] == -1) {
                    used[d] = i;
                    ass[i] = d;
                    bool res = go(go, i+1);
                    if (res) return res;
                    used[d] = -1;
                }
            }
            return false;
        }
    };
    go(go,0);

    if (res == "") {
        cout << "impossible" << endl;
    } else{
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
