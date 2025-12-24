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

// the centroid decomposition breaks it down optimally? 
// i cant figure out why but optimally it makes sense also 
// when we do our centroid decomp, we should keep track what later we are at (if possible)
// then assign the nodes their rank from Z to A base don centroid depth 
//
vvi g;
vi subsize;
vb gone;
vi depth;
int max_depth = 0;
// get size 
int get_size(int u, int p){
    subsize[u] = 1;
    for (int v:g[u]){
        if (v==p || gone[v]) continue;
        subsize[u] += get_size(v,u);
    }
    return subsize[u];
};

int get_cent(int u, int sz, int p){
    for (int v:g[u]){
        if (v==p || gone[v]) continue;
        if (subsize[v]*2 > sz) return get_cent(v,sz,u);
    }
    return u;
};

// build 
void build_centroid(int u, int curr){
    max_depth = max(max_depth,curr);
    int tree_size = get_size(u, -1);
    int cent = get_cent(u, tree_size, -1);
    // cerr << "found: " << cent << endl;

    depth[cent] = curr;
    gone[cent] = true;

    for (int v: g[cent]){
        if (gone[v]) continue;
        build_centroid(v, curr+1 );
    }

}




void solve(){
    int n;
    cin >> n;
    g.assign(n, vi());
    subsize.assign(n,0);
    gone.assign(n,false);
    depth.resize(n,-1); 

    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    build_centroid(0, 0);
    if (max_depth > 25){
        cout << "Impossible!" << endl;
        return;
    }
    // debugv(depth);
    for (auto& x: depth){
        int op = x;
        // cerr << op << " ";
        char ans = 'A' + op; 
        cout << ans << " ";
    }
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
