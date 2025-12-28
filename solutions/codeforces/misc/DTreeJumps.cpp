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

// looks like a DP problem 
// 1. DFS to map depth to nodes 
// 2. do a DFS (dp) search now 
// we start each dfs from root neighbours so we dont need to add special case 
// dfs if we reach a node with no options just return 0 ;

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    vi par(n);
    par[0] = -1;
    for (int i=0;i<n-1;i++){
        int x; cin >> x;
        x--; 
        g[x].pb(i+1);
        g[i+1].pb(x);
        par[i+1] = x;
    }
    // debugv(par)
    vl depth(n*2,0), node(n,0);
    node[0] = 1LL;
    depth[0] = 1LL; //root node 

    ll res = 0;
    ll mod = 998244353;
    int cur = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        cur++;
        int len = q.size();
        for (int t = 0; t < len; t++){
            int u = q.front(); q.pop();
            // cerr << "node: " << u << endl;
            // compute answers
            if (cur==2) {
                node[u] = 1LL;
                depth[cur] = (depth[cur] + 1 + mod) % mod;
                // cerr << u << ":" << node[u] << " " << depth[cur] << endl;
            } else if (cur>2){
                int p = par[u];
                node[u] = depth[cur-1] - node[p];
                depth[cur] = (depth[cur] + node[u] + mod) % mod;
            }

            for (int v:g[u]){
                if (v == par[u]) continue;
                q.push(v);
            }
        }
    }
    // debugv(node);
    // debugv(depth);

    for (int i=0; i<n;i++){
        res = (res + node[i] + mod) % mod;
    }
    cout << res << endl;
    // cerr << endl;
    

    // use a dfs 

    // auto dfs = [&](auto& dfs, int u, int p, int dp) -> ll {
    //
    // }


    // vvi g(n);
    // vector<set<int>> g(n);
    // for (int i=0; i<n-1;i++){
    //     int x; cin >> x;
    //     x--;
    //     g[x].insert(i+1);
    //     g[i+1].insert(x);
    // }
    // vi dist(n,-1);
    // map<int,vi> depth;
    // auto dfs = [&](auto& dfs, int u, int p, int d) -> void{
    //     dist[u] = d;
    //     depth[d].pb(u);
    //     for (int v:g[u]){
    //         if (v == p) continue;
    //         dfs(dfs,v,u,d+1);
    //     }
    // };
    // dfs(dfs,0,-1,0); 
    // // cerr << "computed depth" << endl;
    // // debugv(dist);
    // ll res = 0;
    // ll mod = 998244353;
    // vl dp(n, -1);

    // reverse the problem 
    // 


    // auto go = [&](auto& go, int u) -> ll {
    //     if (dp[u] != -1) return dp[u];
    //     int d = dist[u];
    //     if (!depth.count(d+1)) return dp[u] = 1; // we are the edge/ edge? 
    //     ll evl = 1;
    //     for (auto& v: depth[d+1]){
    //         if (g[u].count(v)) continue; // skip 
    //         evl = (evl + go(go,v) ) % mod;
    //     }
    //     return dp[u] = evl;
    // };
    //
    // for (int v: g[0]){
    //     // go(go,v); //
    //     res =( res + go(go,v) ) % mod;
    // }
    // // debugv(dp);
    // // for (int i=1; i<n;i++){
    // //     res = (res + dp[i]) % mod;
    // // }
    // cout << (res+1)%mod << endl;

};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
