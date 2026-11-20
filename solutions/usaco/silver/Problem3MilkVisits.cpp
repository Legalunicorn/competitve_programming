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

// I failed two approaches
// read the first line of editorial as hint and finished the rest
// the idea of using connected components is unique 
// i had a much more complicated approach which in theory can pass but involved LCA to find distances 
// which is like gold/plat level topic so i disposed of it. but otherwise it would work
// the idea was to root the tree at 0, then compute the score from 0 to any node. as well as use LCA to get 
// the distance between any two nodes. if the distance = negative score then answer is 0, else its 1 

void dfs(int u, int p, vvi& g, vi& id, int x, vector<char>& a){
    id[u] = x;
    for (int v: g[u]){
        if (a[v]==a[u] && v!=p){
            dfs(v,u,g,id,x,a);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi g(n);
    vector<char> a(n);
    for (auto& z:a) cin >> z;
    for (int i=0; i<n-1; i++){
        int x,y; cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);

    }
    string res;
    vi id(n,-1);
    int cnt = 0;
    for (int i=0;i<n;i++){
        if (id[i]==-1){
            dfs(i,-1,g,id,cnt,a);
            cnt++;
        }
    }
    // debugv(id);
    for (int i=0;i<m;i++){
        int s,e; 
        char cow;
        cin >> s >> e >> cow;
        s--; e--;
        if (id[s]!=id[e]) res += "1";
        else{
            // same group, check if match 
            if (a[s]==cow) res += "1";
            else res += "0";
        }
    }
    cout << res << endl; 

};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
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
