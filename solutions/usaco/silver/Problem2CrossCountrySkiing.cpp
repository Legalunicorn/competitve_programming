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


int hit = 0;
void dfs(int d, int r, int c, vvi& g, vvi& pts, vvb& seen ){
    int n = g.size(), m = g[0].size();
    seen[r][c] = true;
    if (pts[r][c]==1) hit++;
    for (const auto& dir:dirs){
        int row  = r+dir[0];
        int col =  c+dir[1];
        if (row<0 || row>=n || col<0 || col>=m || seen[row][col]) continue;
        if (abs(g[r][c]-g[row][col])<=d){
            dfs(d,row,col,g,pts,seen);
        }
    }
}



void solve(){
    int n,m; cin >> n >> m;
    // ive seen this problem before
    // we just binary search and flood fill 
    vvi g(n, vi(m));
    int cnt = 0;
    int sx = 0, sy = 0;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)  {
            cin >> g[i][j];
        }
    }
    vvi pts(n, vi(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int x; cin >> x;
            pts[i][j] = x;
            if (x==1){
                cnt++;
                sx = i;
                sy = j;
            }
        }
    }
    int l = 0, r =(int)(1000000001);
    int res = r;
    while(l<=r){
        int mid = l+(r-l)/2;
        hit = 0;
        vvb seen(n,vb(m));
        dfs(mid,sx,sy,g,pts,seen);
        // cerr << "m:" << m << " " << hit << " : " << cnt << endl;
        if (hit == cnt){
            res = mid;
            r = mid -1;
        } else l = mid +1;

    }
    cout << res << endl;

};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ccski.in","r",stdin);
    freopen("ccski.out","w",stdout);
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
