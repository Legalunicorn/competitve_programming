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
using vvl = vector<vl>;
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
const vvi dirs_inv = {{1,0},{-1,0},{0,1},{0,-1}};
const vector<char> dirs_char = {'U','D','L','R'};
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}




void solve(){
    int n,m;
    cin >> n >> m;
    // vector<vector<char>> grid (n,vector<char>(m));
    vector<string> g (n);
    pi end, start;
    for (int i=0;i<n;i++){
        string s; cin >> s;
        g[i] = s;
        for (int j=0;j<m;j++){
            if (s[j]=='A'){
                start.F = i;
                start.S = j;
            }
        }
        if (s[0]=='.'){
            end.F = i;
            end.S = 0;
        } else if (s[m-1]=='.'){
            end.F = i;
            end.S = m-1;
        }
    }

    //Dijsktra is completely unnecessary 
    //Bfs will do 
    vvi dist(n,vi(m,INT_MAX));
    vvi par(n,vi(m,-1));
    auto cmp = [&](const auto& a, const auto& b){
        return a[0] < b[0];
    };
    priority_queue<vi,vvi,decltype(cmp)> pq(cmp);
    dist[end.F][end.S] = 0;
    pq.push({0,end.F,end.S});

    // cerr << "pretest " << endl;

    while(!pq.empty()){
        vi t = pq.top();
        pq.pop();
        int w = t[0], x = t[1], y = t[2];
        for (int i=0;i<4;i++){
            int r = x+dirs[i][0];
            int c = y+dirs[i][1];
            if (r>=0 && r<n && c>=0 && c<m && g[r][c]!='#'){
                if (w+1>dist[r][c]){
                    dist[r][c] = w+1;
                    par[r][c] = i;
                    pq.push({w+1,r,c});
                }
            }
        }
    }
    int alice = dist[start.F][start.S];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (g[i][j]=='M' && dist[i][j]<=alice){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    cout << alice << endl;

    int x = end.F, y = end.S;
    while(par[x][y]!=-1){
        int dir = par[x][y];
        vi d = dirs_inv[dir];
        cout << dirs_char[dir] << " ";
        x += d[0];
        y += d[1];
    }
    cout << endl;


};
/*
what if i compute dijkstra from escape point 
to A and all monsters

idea
- if A has the shortest shortest distance, print Yes, then proceed to find (trace using path )
*/


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