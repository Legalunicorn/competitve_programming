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




void solve(){ 
    int n,m;
    cin >> n >> m;
    vvi g(n);
    vi side(n,-1);
    bool valid = true;
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    queue<int> q;
    for (int s =0; s < n ; s++){
        if (side[s]==-1){
            q.push(s);
            side[s] = 0; 
            while(!q.empty()){
                int v= q.front();q.pop();
                for (int u:g[v]){
                    if (side[u]==-1){
                        side[u] = side[v]^1; //xor to make it flip
                        q.push(u);
                    } else{
                        valid &= (side[u]!=side[v]);
                    }
                }
            }
        }
    }
    if (valid){
        for (int s:side) cout << s+1 << " ";
        cout << endl;
    } else cout << "IMPOSSIBLE" << endl;
    // vi par(n);
    // for (int i=1;i<n;i++) par[i] =i;
    // bool valid = true;

    // function<int(int)> find = [&](int a){
    //     if (a==par[a]) return a;
    //     else return par[a] = find(par[a]);
    // };
    // function<void(int,int)> join = [&](int a,int b){
    //     if (par[a]!=a || par[b]!=b){
    //         valid = false;
    //         return;
    //     } else par[a] = a;
    // };
    // for (int i=0;i<m;i++){
    //     int a,b;
    //     cin >> a >> b;
    //     a--;b--;
    //     join(a,b);
    // }
    // if (!valid) cout <<"IMPOSSIBLE" << endl;
    // else{
    //     for (int i=0;i<n;i++){
    //         if (par[i]==i) cout << 1 <<  " ";
    //         else cout << 2 << " ";
    //     }
    //     cout << endl;
    // }
};
/*
imagine this is a graph we want to bipartite it 
i think the solution is greedy we just do a dfs and color the edge s
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