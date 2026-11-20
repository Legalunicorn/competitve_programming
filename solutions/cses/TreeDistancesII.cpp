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

// Very nice problem ! rerooting was right and it took a while but i finally got it 


// 1. calculate the size of every subtree stored in size[] 
// 2. calculate the score, res[]
// 3. rerooting: int up = size[par]-size[child], int down = size[child]
// 4. ans = dp[par] + (up - down)
// update size: size[par] = size[par] - size[child]  || size[child ] = n 
pl dfs1(int u, int p, vvi& g, int d, vl& size){
    pl res = {1, d};
    for (int v:g[u]){
        if (v ==p) continue;
        pl evl = dfs1(v,u,g,d+1,size); 
        res.F += evl.F;
        res.S += evl.S;
    }
    size[u] = res.F;
    return res;
};

void dfs2(int u, int p, vvi& g, vl& size, vl& dp, ll score){
    // cerr << "curr: " << u << "   score: " << score << endl;
    // debugv(size);
    // cerr << endl << endl;
    dp[u] = score;
    int n = size.size();
    for (int v:g[u]){
        if (v == p) continue;
        ll temp = size[v];
        ll up = size[u] - size[v];
        ll down = size[v];
        size[u] = up;
        size[v] = n;
        dfs2(v,u,g,size,dp, score+(up-down));
        size[u] = n;
        size[v] = temp;
    }
}

void solve(){
    // this seems like we can solve with rerooting, 
    // its not a binary tree though so what we want is 
    // idk how to reroot: should watch a rerooting totua
    int n; 
    cin >> n;
    vvi g(n);
    for (int i=0; i<n-1; i++){
        int x,y; cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    vb seen(n);
    vl size(n), dp(n); 
    pl ini = dfs1(0,-1,g,0,size);
    dp[0] = ini.S;
    dfs2(0,-1,g,size,dp,dp[0]);
    for (auto& x: dp) cout << x << " "; 
    cout << endl;


    // now we calculate the rest 
    // calculate dp 1 
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
