/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>
#include <sys/types.h>

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

// this sounds like bipartite matching ? 
// we draw edges if two dominos share a number 
// limitations 
// domino with same number -> no go 
// number appear more than 2 times -> no go 
// so a number only appear once or twice 
// then we can draw out edges with ease now 
// bipartite checking with bfs works 
// side = 1 or 0,, -1 for unset 

void solve(){
    int n; 
    cin >> n;
    map<int, vi> mp; // domino number -> Ids' 
    bool invalid = false;
    vvi g(n);
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if (a == b) invalid = true;
        mp[a].pb(i);
        mp[b].pb(i);
        if (mp[a].size()>2 || mp[b].size()>2) invalid = true;
        
    }
    if (invalid){
        cout << "NO" << endl;
        return;
    }
    for (auto& [val, vec]: mp){
        if (vec.size()>1){
            // connect the two dominotes 
            int u = vec[0], v = vec[1];
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    vi side(n, -1);
    queue<int> q;
    for (int i=0; i<n;i++){
        if (invalid) break;
        if (side[i] != -1) continue;
        q.push(i);
        side[i] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for (int v:g[u] ){
                if (side[v]==-1){
                    side[v] = 1 - side[u];
                    q.push(v);
                } else{
                    if (side[v] == side[u]) {
                        invalid = true;
                        break;
                    }
                }
            }
        }
    }
    if (invalid) cout << "NO" << endl;
    else cout << "YES" << endl;
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("","r",stdin);
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
