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
// using namespace __gnu_pbds;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//template/ template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// // 
// template <class T> using ordered_multiset = tree<T, null_type,
// less_e

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



// hint: 2^K where k is number of connected components?
// "S" -> the grasses must be group together. if one is grass 1 -> all is grass start1 
// "D" -> must be difference. this is also deterministic. if one is type a, the other is type b 
// cannot have a contradictino of 3 nodes, and relationshipf of same same different 
// "S" -> can all me treated as the same node 
// "D" -> joint of two "S" groups, but the coloring of a cluster of "D"s is fixed ie. only 2 days 
// we need to ensure that 1. no pairs in "D" can have the same id from dsu 
// 2. the graphs of D's are bipartite 
// then we get the number of connected components 


bool check_bipartite(int u, vector<int>& color, vector<vector<int>>& g){
    //color ->{0: unassigne, 1: color one, 2: color two}
    int cur = color[u];
    int alt = 3 - cur;
    for (int v: g[u]){
        if (color[v]){
            if (color[v] == cur) return false;
        } else {
            color[v] = alt;
            if (!check_bipartite(v, color, g)) return false;
        } 
    }
    return true;
}

struct Dsu{
private:
    int n; 
    vector<int> par, size;
public:
    Dsu(int sz){
        n = sz;
        size.assign(n,0);
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

void dfs(int u, vb& seen, vvi& g){
    seen[u] = true;
    for (int v: g[u]){
        if (!seen[v]) dfs(v,seen,g);
    }
}

// not solved yet 
void solve(){
    int n,m;
    cin >> n >> m;
    Dsu dsu(n);
    vpi gs, gd;
    for (int i=0;i<n;i++){
        char c; cin >> c;
        int a,b; cin >> a >> b;
        a--; b--;
        if (c=='S') gs.pb({a,b});
        else gd.pb({a,b});
    }
    vvi g(n);
    for (const auto& x: gs){
        dsu.union_set(x.F, x.S);
        
    }
    for (int i=0;i<n;i++) cerr << dsu.find(i) << " ";
    cerr <<endl;
    for (const auto& x: gd){
        cerr << x.F << " " << x.S << endl;

    }
    for(const auto& x: gd){
        int a = dsu.find(x.F);
        int b = dsu.find(x.S);
       if (a==b) {
           cerr << x.F << " " << x.S << endl;
           cerr << "gd same " << endl;
           cout << 0 << endl; return ;
       }
       g[a].pb(b);
       g[b].pb(a);
    }
    vi color(n);
    for (int i=0;i<n;i++){
        if (!color[i]){
            bool evl = check_bipartite(i, color, g);
            if (!evl){
                cout << 0 << endl;
                return;
            }
        }
    }
    // count connected componentnsn
    vb seen(n), seen2(n);
    int res = 0;
    for (int i=0;i <n;i++){
        int grp = dsu.find(i);
        if (!seen2[grp]){
            seen2[grp] = true;
            if (!seen[i]){
                dfs(i,seen,g);
                res++;
            }
        }
    }
    cout << 1;  
    for (int i=0; i<res;i++ ) cout << 0;
    cout << endl;
     
    
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
