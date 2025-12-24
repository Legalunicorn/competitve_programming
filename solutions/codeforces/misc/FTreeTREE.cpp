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

// seems like a reroot dp problem 
// size[u] store the subtree size (take 0 as root first)
// ans[u] store the number of elements with substree > k (take 0 as root first)
// 1) do a initial dfs -> find ans[0], and size[] for all notes 
// 2) use size to compute ksize, which is notes that satisfy condition 
//
// then we update size, ksize, ans during the second dfs 
//
//
//
// size[u] = n - size[v];
// size[v] = n 
//
// ksize[u] = 

void solve(){
    int n, k;
    cin >> n >> k;
    vvi g(n);
    for (int i=0; i<n-1;i ++){
        int u,v; cin >> u >> v;
        g[--u].pb(--v);
        g[v].pb(u);
    }
    vi size(n), kans(n), res(n);

    auto dfs1 = [&](auto& dfs1, int u, int p) -> pi{
        pi res = {1,0}; // size, ksize 
        for (int v: g[u]){
            if (v==p) continue;
            pi evl = dfs1(dfs1, v, u);
            res.F += evl.F;
            res.S += evl.S;
        }
        if (res.F >=  k ) res.S ++; // 
        size[u] = res.F;
        kans[u] = res.S;
        return res;
    };
    dfs1(dfs1, 0, -1); // first dfs 

    res[0] = kans[0]; 

    auto dfs = [&](auto& dfs, int u,int  p) -> void{
        res[u] = kans[u]; // fix the answer 
        for (int v: g[u]){
            if (v==p) continue;
            // now we transition this shit first do temp 
            int temp_sz = size[v];
            int t1 = kans[u], t2 = kans[v];
            // alter the size 
            size[u] = n - size[v];
            size[v] = n;
            // change ksize values 
            int others = kans[u] - kans[v] -1 ;
            kans[v] = kans[v] + others;
            if (size[u]>=k) kans[v]++;
            if (temp_sz<k) kans[v]++; 
            
            kans[u] = others;
            if (size[u]>k) kans[u]++; // still hold 

            dfs(dfs, v, u);

            // return back 
            size[u] = n;
            size[v] = temp_sz;
            kans[u] = t1;
            kans[v] = t2;
        }
    };

    dfs(dfs, 0,-1); 

    // debugv(res);

    ll ans = 0;
    for (auto& x: res) ans += x;
    cout << ans << endl;

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
