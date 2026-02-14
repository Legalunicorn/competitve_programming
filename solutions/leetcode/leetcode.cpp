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

#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;
const int inv= 1e9;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vvi g(n);

        for (auto& p: pairs){
            int u = p[0], v = p[1];
            g[u].pb(v);
            g[v].pb(u);
            //dsu.union_set(p[0], p[1]);
        }
        string t = s;

  

        vi comp;
        vb seen(n, false);
        auto dfs = [&](auto dfs, int u) -> void{
            seen[u] = true;
            comp.pb(u);
            for (auto& v: g[u]){
                if (seen[v]) continue;
                dfs(dfs,v);
            }
        };

        for (int i = 0; i < n; i++){
            if (seen[i]) continue;
            dfs(dfs,i);
            vi ids = comp;
            sort(all(ids));
            sort(all(comp),[&](const auto&p, const auto&q){
                    return s[p] < s[q];
            });
            for (int i = 0; i  <comp.size(); i++){
                t[ids[i]] = s[comp[i]];
            }
            comp.clear();
            ids.clear();
        }
        return t;
    }
};

void solve(){
}


#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif
