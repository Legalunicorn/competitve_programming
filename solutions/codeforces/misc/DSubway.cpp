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



void solve(){
    int n;
    cin >> n;
    vvi g(n);
    for (int i=0;i<n;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    // do a n^2 for cycle detection and aother for distance LOL 
    vb is_ring(n,false);
    vi seen(n,false);
    auto d1 = [&](auto& d1, int u, int st, int p) -> bool{
        seen[u] = true;
        bool evl = false; 
        for (int v: g[u]){
            if (v == p) continue;
            if (v == st) return true;
            if (seen[v]) continue;
            evl = evl || d1(d1,v,st,u);
        }
        return evl;
    };

    for (int i=0;i<n;i++){
        seen.assign(n,false);
        if (d1(d1,i,i,-1)) is_ring[i] = true;
    }

    vi dist(n,0);

    auto d2 = [&](auto& d2, int u, int d) -> int{
        seen[u] = true;
        if (is_ring[u]) return d;
        int res = n*10;
        for (int v:g[u]){
            if (seen[v]) continue;
            res = min(res,d2(d2,v,d+1));
        }
        return res;
    };

    for (int i=0;i<n;i++){
        if (is_ring[i]) continue;
        seen.assign(n,false);
        dist[i] = d2(d2,i,0);
        // dfs to closest distance 
        // vb vis(n,false);
        // vis[i] = true;
        // queue<int> q;
        // q.push(i);
        // int D = 0;
        // bool found = false;
        // while(q.empty()){
        //     int l = q.size();
        //     for (int j=0; j<l; j++){
        //         int u = q.front(); q.pop();
        //         for (int v:g[u]){
        //             if (vis[v]) continue;
        //             if (is_ring[v]) {
        //                 dist[i] = D;
        //                 found = true; 
        //                 break;
        //             } else q.push(v);
        //
        //         }
        //     }
        //     if (found) break;
        //     D++; 
        // }
    }
    // debugv(is_ring);
    for (int i=0;i<n;i++) cout << dist[i] << " "; 
    cout << endl;

    
    // auto d1 = [&](auto& d1, int u, int p ) -> bool {
    //     color[u] = 1;
    //
    //     for (int v:g[u]){
    //         if (v == p ) continue;
    //         if (color[v] == 1) return true;
    //         else
    //     }
    // }
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
