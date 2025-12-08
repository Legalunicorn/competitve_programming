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
#define debugm(mat) do { cerr << #mat << " = [\n"; for (size_t i = 0; i < (mat).size(); ++i) { cerr << "  ["; for (size_t j = 0; j < (mat)[i].size(); ++j) { cerr << (mat)[i][j]; if (j + 1 < (mat)[i].size()) cerr << ", "; } cerr << "]\n"; } cerr << "]\n"; } while (0)

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}


void dfs(int u, int p, vvi& g, int curr, vi& depth){
    depth[u] = curr;
    for (int v: g[u]){
        if (v==p) continue;
        dfs(v,u,g,curr+1,depth);
    }
}

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    for (int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    //1. initial DFS, find edge 
    vi depth(n);
    dfs(0,-1,g,0,depth);

    // == get edgep 1 
    int m1 = 0;
    int id = 0;
    for (int i=0;i<n;i++){
        if (depth[i]>m1){
            m1 = depth[i];
            id = i;
        }
    }

    //2. second DFS, depth from Edge 1 
    depth.assign(n,0);
    dfs(id,-1,g,0,depth);

    int m2 = 0;
    int id2 = 0;
    for (int i=0;i<n;i++){
        if(depth[i]>m2) {
            m2 = depth[i];
            id2 = i;
        }
    }
    //3 third dfs, depth from edg2;
    vi depth2(n);
    dfs(id2,-1,g,0,depth2);

    for (int i=0;i<n;i++){
        cout << max(depth[i],depth2[i]) << " ";
    }
    cout << endl;


};



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