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

int tc = 0;
int cnt = 0;
void dfs(int r, int c, vector<string>& g, vvb& seen){
    seen[r][c] = true;
    int n = g.size();
    int m = g[0].size();
    if (g[r][c] == 'G') cnt++;
    for (auto& d: dirs){
        int row = r+ d[0];
        int col = c+d[1];
        if (row<0 || row>=n || col<0 || col >=m ||  g[row][col]=='#' || seen[row][col]) continue;
        dfs(row,col,g,seen);
    }
}

void solve(){
    tc++;
    cnt = 0;
    // 1. check if escape is connected to B 
    // replace neightbors of B with wall, if its a G return false 
    // flood fill from escape and find all G 
    int n,m; cin >> n >> m;
    vector<string> g(n);
    for (int i=0;i<n;i++) cin >> g[i];
    // if (tc==63){
    //     string ans;
    //     for (auto x: g) ans+=x;
    //     ans+="///";
    //     cout << ans << endl;
    //     return;
    // }
    int g_cnt = 0;
    int d_cnt = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (g[i][j]=='G') g_cnt++;
            if (g[i][j]=='B') d_cnt++;
        }
    }
    if (g_cnt==0) {
        cout << "Yes" << endl;
        return;
    }

    if (n>1){
        if (g[n-2][m-1]=='B') {
            cout << "No" << endl;
            return;
        }
    }
    if (m>1){
        if (g[n-1][m-2]=='B'){
            cout << "No" << endl;
            return;
        }
    }
    // replace all B surrounding and if its a G kiill it, also count G 
    bool impossible = false;
    for (int i=0; i<n; i++){
        for (int j=0;j<m;j++){
            if (g[i][j]=='B'){
                for (auto& d: dirs){
                    int r = i+d[0];
                    int c = j + d[1];
                    if (r<0 || r>=n || c<0 || c>=m) continue;
                    if (g[r][c]=='G'){
                        impossible = true;
                    } else if (g[r][c]=='.') g[r][c]='#'; // make it a wall 
                }
            }
        }
    }
    // for (int i=0;i<n;i++){
    //     cerr << g[i] << endl;
    // }
    // cerr << endl << endl;
    if (impossible){
        cerr << "adjacent" << endl;
        cout << "No" << endl;
        return;
    }
    // flood fill 
    vvb seen(n, vb(m));
    dfs(n-1,m-1, g, seen);
    cerr << cnt << " " << g_cnt << endl;
    if (cnt == g_cnt){
        cout << "Yes" << endl;
    } else cout << "No" << endl;


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
