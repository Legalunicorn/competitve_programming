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


// clear i mis understood this 
// this is about ocnnectiveity 
// the edges are bidirecitonal 
// 1. i need to know when to remove edges from F 
// 2. when to add edges in F. 
//
// makese sense to look at G first? 
// we can perform DSU on G, 
// then for every edge in F, if two edges join  disjoint comonents 
// they must be removed, this is simple 
// what about connecting edges> 
// 1. remove all first 
// 2. build later 
// == building == 
// for every edge in G, 
// we chekc that Fu , Fv are connected, otherwise we connect 
//
// overall solutions 
// 1. collect edges and ajacency list for both graphs 
// 2. dfs graph 2 and union them 
// 3. iterate edges of F and remove those not in order 
// 4. dfs graph 1 and union them 
// 5. iterates edgoes of G, and if htey are disjoint in F, join them (+1 to answer also )


struct Dsu{
public:
    int n; 
    vector<int> par, size;
// public:
    Dsu(int sz){
        n = sz;
        size.assign(n,1);
        par.assign(n,0);
        iota(par.begin(),par.end(),0);
    }

    int find(int v){
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void union_set(int a, int b){
        a = find(a);
        b = find(b);
        if (a != b){
            if (size[a] < size[b]) swap(a,b);
            par[b] = a;
            size [a] += size[b];
        }
    }
};


void solve(){
    int n, m1,m2;
    cin >> n >> m1 >> m2;
    vpi fe(m1), ge(m2);
    vector<set<int>>  fg(n),gg(n);
    for (int i=0; i<m1;i++){
        int u,v;
        cin >> u >> v, u--,v--;
        fe[i] = {u,v};
        fg[u].insert(v);
        fg[v].insert(u);

    }
    for (int i=0;i<m2;i++){
        int u,v;
        cin >> u >> v, u--,v--;
        ge[i] = {u,v};
        gg[u].insert(v);
        gg[v].insert(u);
    }
    Dsu df(n), dg(n);
    vb seen(n,false);
    auto dfs = [&](auto& dfs, vector<set<int>>& g, int u, Dsu& dsu) -> void {
        seen[u] = true;
        for (int v:g[u]){
            if (seen[v]) continue;
            dsu.union_set(u,v);
            dfs(dfs,g,v,dsu);
        }
    };
    for (int i=0;i<n;i++){
        if (!seen[i]) dfs(dfs,gg,i,dg);
    }
    int res = 0; 
    for (int i=0;i<m1;i++) {
        int u = fe[i].F, v = fe[i].S;
        if (dg.find(u) != dg.find(v)){
            fg[u].erase(v);
            fg[v].erase(u);
            res++;
        }
    }
    seen.assign(n,false);
    for (int i=0;i<n;i++){
        if (!seen[i]) dfs(dfs,fg,i,df);
    }

    // now we run through the edges of G 
    // and if they are not connected in F we connect them 
    // i assume this is optimal 
    for (int i=0;i<m2;i++){
        int u = ge[i].first, v = ge[i].second;
        if (df.find(u) != df.find(v)){
            df.union_set(u,v);
            res++;
        }
    }
    cout << res << endl;



    // for (int i=0;i<m1;i++){
    //     int u,v; cin >> u >> v;
    //     f.insert({u,v});
    // }
    // for (int i=0;i<m2;i++){
    //     int u,v; cin >> u >> v;
    //     g.insert({u,v});
    //     if (f.count({u,v})) both.insert({u,v});
    // }
    // cerr << both.size() << endl;
    // // for (auto& [a,b]: both) cerr << a << " " << b << endl; endl;
    // cerr << " === " << endl;
    // for (auto& [a,b]: f) cerr << a << " " << b << endl; endl;
    // // for (auto& x: both) cout << x.F << " " << x.S << end;
    // // for (auto& x: f) cout << x.F << " " x.second << endl;
    // // for (auto& x: g) cout << x.F << " " x.S << endl;
    // int res = f.size() - both.size() + g.size() - both.size();
    // cout << res << endl;

};

/*
     
   i think we must make the grpah equivalent because of IFF 
   1. find the common edges 
   2. reomve all uncommon edges from F 
   3. add all uncommon edges to F
   1. store both edges in a set? 
   2. store common edges in separate set? 
   3. G has m2 edges, so m2-common is missing 
   4. m1-common is extraa 
   so m2-common + m1-common is the answer 



*/


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
