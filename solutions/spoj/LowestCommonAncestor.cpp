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


struct Tree{
    int n,timer, LOG;
    vector<int> tin, euler_tour, logPow, depth;
    vector<vector<int>> g,st;

    Tree(int sz): timer(0), n(sz), tin(n,0), euler_tour(2*n,0), depth(n,0){
        g.assign(n, vector<int>());
        logPow.assign(2*n+1,0);
        for (int i=2;i<2*n+1;i++) logPow[i] = logPow[i/2]+1;
    }
    // Sprase table functions 
    int combine(int a, int b){
        return (tin[a] < tin[b] ? a : b);
    }
    void st_build(){
        for (int i=0; i<timer; i++) st[i][0] = euler_tour[i];
        for (int j=1; j<LOG; j++){
            for (int i=0; i + (1<<j) <= timer; i++){
                int a = st[i][j-1];
                int b = st[i+(1<<(j-1))][j-1];
                st[i][j] = combine(a,b);
             }
        }
    }    
    int st_query(int l, int r){
        int k = logPow[r-l+1];
        int a = st[l][k], b = st[r-(1<<k)+1][k];
        return combine(a,b);
    }
    // End of sparse table functions 

    void add_edge(int u, int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // called from build
    void dfs(int u = 0, int p = -1, int d = 0){
        depth[u] = d;
        tin[u] = timer;
        euler_tour[timer++] = u;
        for (int v:g[u]){
            if (v == p) continue;
            dfs(v,u,d+1);
            euler_tour[timer++] = u;
        }
    }

    void build(int u = 0, int p = -1){
        dfs(u,p);
        LOG = 0;
        while((1<<LOG)<=timer) LOG++;
        st.resize(timer, vector<int>(LOG));
        st_build();
    }

    int lca(int a, int b){
        if (tin[a]>tin[b]) swap(a,b);
        return st_query(tin[a], tin[b]);
    }

    int dist(int a, int b){ return depth[a] + depth[b] - 2*depth[lca(a,b)];}

};

int tc = 0;
void solve(){
    tc++;
    int n; 
    cin >> n; 
    Tree tree(n);
    for (int u=0;u<n;u++){
        int m; cin >> m;
        for (int j=0;j<m;j++){
            int v;  cin >> v;
            tree.add_edge(u,v-1);
        }
    }
    tree.build();
    cerr << "ok " << endl;
    int q; cin >> q;
    cout << "Case " << tc << ":" << endl;
    while(q--){
        int u,v;
        cin >> u >> v;
        cout << tree.lca(u-1,v-1)+1 << endl;
    }
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
