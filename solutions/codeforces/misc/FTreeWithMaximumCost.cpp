/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template <class T> using ordered_multiset = tree<T, null_type,
// less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vb = vector<bool>;
using vvb = vector<vb>;


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;
constexpr double PI = 3.14159265358979323846;


// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));
#define sortU (a) sort(all(a)),(a).erase(unique(all(a)),(a).end())

// === Debug macros , to add a general function and replace this gunk
#define debugv(vec) cerr << #vec << " = ["; for (size_t i = 0; i < (vec).size(); ++i) { cerr << (vec)[i]; if (i + 1 < (vec).size()) cerr << ", "; } cerr << "]\n";
#define debugm(mat) do { cerr << #mat << " = [\n"; for (size_t i = 0; i < (mat).size(); ++i) { cerr << "  ["; for (size_t j = 0; j < (mat)[i].size(); ++j) { cerr << (mat)[i][j]; if (j + 1 < (mat)[i].size()) cerr << ", "; } cerr << "]\n"; } cerr << "]\n"; } while (0)

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
const vector<char> dir_char = {'U','D','L','R'};
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}

// this is reroot dp question 

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    vl a(n);
    for (auto& z:a) cin >> z;
    for (int i=0;i<n-1;i++){
        int u,v; 
        cin >> u >> v;
        g[--u].pb(--v);
        g[v].pb(u);
    }
    // debugm(g);
    vl subsum(n), subans(n), ans(n);
    // first dfs, compute subsum and subans;
    auto dfs = [&](auto& dfs, int u, int p) -> ll{
        ll sum = a[u];
        for (int v:g[u]){
            if (v == p ) continue;
            sum += dfs(dfs,v,u);
        }
        subsum[u] = sum;
        for (int v:g[u]){
            if (v == p) continue;
            subans[u] += (subans[v] + subsum[v]);
            // evl.S += subans[v] + subsum[v];
        }
        // cerr << u << ":" << sum << endl;
        return sum;
    };
    dfs(dfs,0,-1);
    // debugv(subsum);
    // debugv(subans);
    ans[0] = subans[0];
    ll res = ans[0];
    ll tot = subsum[0]; // 
    auto go = [&](auto& go, int u, int p) -> void{
        // cerr << u << ":" << ans[u] << endl;
        res = max(res, ans[u]);
        for (int v:g[u]){
            if (v==p) continue;
            // set  
            // cerr << "vee: " << v << endl;
            ll sv = subsum[v], su = subsum[u];
            ll av = subans[v], au = subans[u];
            // ans[v] = ans[u] - (subans[v] + subsum[v]) + subans[v];
            subsum[u] = tot - sv;
            subsum[v] = tot;
            subans[u] = au - (av + sv);
            ans[v] = au - sv + subsum[u];
            subans[v] = ans[v];
            // cerr << subsum[u] << "  ,  " << subsum[v] << endl;
            // cerr << subans[u] << endl << endl;

            go(go,v,u);

            subsum[v] = sv;
            subans[v] = av;
            subsum[u] = su;
            subans[u] = au;

            // unset 
        }
    };

    go(go,0,-1);

    // debugv(ans);
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
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
