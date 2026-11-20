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


struct Dsu{
public:
    int n; 
    vector<int> par, size;
    Dsu(int sz){
        n = sz;
        size.assign(n,1);
        par.assign(n,0);
        iota(par.begin(),par.end(),0);
    }

    int find(int v){
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void union_set(int a, int b){
        a = find(a);
        b = find(b);
        if (a != b){
            if (size[a] < size[b]) swap(a,b);
            par[b] = a;
            size [a] += size[b];
        }
    }
};

int convert(int r, int c, int n){
    return r*n+c;
}


void solve(){

    int n,m,u;
    cin >> n >> m >> u;
    vector<string> g(n);
    for (auto& z:g) cin >> z;
    int tot = n*m;
    Dsu dsu(tot+5);
    
    // find stockhold and also union everything; 
    int sx, sy;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (g[i][j]=='S') {
                sx = i;
                sy = j;
            }
            if (g[i][j]!='.'){
                // can we dfs? yeah we can we just check right and dow 
                if (i+1<n && g[i+1][j]!='.'){
                    int a = convert(i,j,m);
                    int b = convert(i+1,j,m);
                    dsu.union_set(a, b);
                }
                if (j+1<m && g[i][j+1]!='.'){
                    int a = convert(i,j,m);
                    int b = convert(i,j+1,m);
                    dsu.union_set(a, b);

                }
            }
        }
    }
    int sa = convert(sx,sy,m);
    int ida = dsu.find(sa);
    cout << dsu.size[ida] << endl;
    for (int i=0; i<u;i++){
        int x,y; cin >> x >> y;
        x--; y--;
        g[x][y] = '#'; 
        // cerr << x << " " << y << endl;
        int a = convert(x,y,m);
        for (const auto& d: dirs){
            int r = x+d[0], c = y+d[1];
            if (r<0 || r>=n || c<0 || c>=m || g[r][c]=='.') continue;
            // cerr << r << " : " << c << endl;
            int b = convert(r,c,m);
            dsu.union_set(a, b);
        }
        sa = convert(sx,sy,m);
        ida = dsu.find(sa);
        cout << dsu.size[ida] << endl;
    }

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
