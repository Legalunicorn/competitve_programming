#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//template 
// distinct - pbds 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// 
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vll = vector<vl>;
using pi = pair<int,int>;
using vvpi = vector<vector<pi>>;
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
#define debug_mat(mat) do { cerr << #mat << " = [\n"; for (size_t i = 0; i < (mat).size(); ++i) { cerr << "  ["; for (size_t j = 0; j < (mat)[i].size(); ++j) { cerr << (mat)[i][j]; if (j + 1 < (mat)[i].size()) cerr << ", "; } cerr << "]\n"; } cerr << "]\n"; } while (0)

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}



void dfs(int u,vvi& g, vi& out,vb& vis){
    vis[u] = true;
    for (int v: g[u]){
        if (vis[v]) continue;
        dfs(v,g,out,vis);
    }
    out.pb(u);
}

void solve(){
    int n,m;
    cin >> n >> m;
    vi val(n);
    vvi g(n),gi(n);
    vb vis(n,false);
    vi order;

    for (int&z: val) cin >> z;
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        gi[v].pb(u);
    }

    //1. get the order 
    for (int u=0;u<n;u++){
        if (!vis[u]) dfs(u,g,order,vis);
    }
    reverse(all(order));
    vis.assign(n,false);

    //1. build condensation graph
    
    vi roots(n);
    vl sums;
    int k = 0;
    for (int u :order){ //this order is already topologically sorted i think 
        if (!vis[u]){
            vi scc;
            dfs(u,gi,scc,vis);
            ll sum =0;
            for (int v:scc){
                sum += val[v];
                roots[v] = k; //the new Id's 
            }
            sums.pb(sum); //sum of sccK
            k++;

        }
    }
    vvi gc(k);
    for (int u=0;u<n;u++){
        for (int v:g[u]){
            if (roots[u]!=roots[v]){
                gc[roots[u]].pb(roots[v]);
            }
        }
    }


    // topo sort gcc
    vi indeg(k);
    for (int i=0;i<k;i++){
        for (int v:gc[i]){
            indeg[v]++;
        }
    }
    queue<int> q;
    for (int i=0;i<k;i++){
        if (indeg[i]==0) q.push(i);
    }
    vi topo;
    
    while(!q.empty()){
        int u = q.front();q.pop();
        topo.pb(u);
        for (int v:gc[u]){
            indeg[v]--;
            if (indeg[v]==0) q.push(v);
        }
    }
    // debugv(sums);
    // debugv(topo);
    if (topo.size()<k) cerr << "topo error" << endl;

    //run  a d p
    vl dp(k,0);
    for (int i=0;i<k;i++) dp[i] = sums[i];
    for (int t: topo){
        for (int u: gc[t]){
            dp[u] = max(dp[u],dp[t]+sums[u]);
        }
    }
    ll res = MAX(dp);
    cout << res << endl;


};
/*
1 <-> 2  ->4 
->3

*/


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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