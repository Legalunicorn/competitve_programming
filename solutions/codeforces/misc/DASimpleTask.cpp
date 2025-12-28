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

// we can of [mask][node] but we need to be careful what if signifies 
// for every edge, if it goes to a node that we've seen before 
// then we get a cycle 
// but is it a new cycle? 
// we dont know which elements formed the cycle when we see it 
// if we dont know which nodes form the cycle. we dont know 
// if the cycke has been added before already! 
//
// what about my initial approach, we fix the cycle, then we try to find how many ways?
// perhaps we can reset the cache? 
// dp[remianing_mask][pos] 

ll dp[1<<19][20];
void solve(){
    memset(dp,-1,sizeof(dp));
    int n, m;
    cin >> n >> m;
    vi g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u] = g[u] | (1<<v);
        g[v] = g[v] | (1<<u);
    }

    int MAX = 1 << n;
    // vvl dp(1<<n, vl(n, -1));
    ll res = 0;
    cerr << "failure" << endl;
    auto dfs = [&](auto& dfs, int st, int cur, int mask) -> ll{
        // cerr << cur << endl;
        auto& ans = dp[mask][cur];
        if (ans!=-1) return ans;
        ans = 0;
        for (int v=0; v<n; v++){
            if ( ((g[cur]>>v)&1) ==0) continue;
            if (v == st) {
                if (__builtin_popcountll(mask) >= 3) ans++;
            } else if (v > st && ((mask >> v)&1)==0 ){
                ans += dfs(dfs,st,v, mask ^ (1<<v));
            }
        }
        return ans;
    };
    for (int i=0;i<n;i++) res += dfs(dfs,i,i,1<<i);
    cout << res/2 << endl;
};


int main(){
    // cerr << "Wtf" << endl;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    auto start1 = high_resolution_clock::now();
    while(T--){
        // cerr << "go!" << endl;
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
