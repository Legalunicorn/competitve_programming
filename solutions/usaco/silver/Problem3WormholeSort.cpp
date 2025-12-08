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
private:
    int n; 
    vector<int> par, size;
public:
    Dsu(int sz){
        n = sz;
        size.assign(n,0);
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


bool check(int x, vvi& g, int n, vi& a){
    Dsu dsu(n);
    for (int i=0; i<g.size(); i++){
        if (g[i][2] <x) continue;
        dsu.union_set(g[i][0]-1, g[i][1]-1);
    }
    for (int i =0; i<n; i++){
        if (a[i]!=i){
            // check
            int x = dsu.find(a[i]);
            int y = dsu.find(i);
            if (x!=y) return false;
        }
    }
    return true;

}

void solve(){
    int n,m;
    cin >> n >> m;
    vi a(n);
    for (int i=0; i<n ;i++){
        int x; cin>> x;
        a[i] = x-1;
    }
    cerr << "read input " << endl;
    vvi g(m, vi(3));
    int l = 0, r = 0;
    for (int i=0;i<m;i++){
        cin >> g[i][0] >> g[i][1] >> g[i][2];
        r = max(r,g[i][2]);
    }
    cerr << "read g" << endl;
    // check if sorted;
    bool valid = true;
    for (int i=0;i<n;i++){
        if (a[i]!=i) {
            valid = false;
            break;
        }
    }
    if (valid){
        cout << -1 << endl;
        return;
    }
    int res = -1;
    while(l <= r){
        int m = l+(r-l)/2;
        bool pass = check(m, g, n , a);
        if (pass){
            res = m;
            l = m +1;
        } else r = m -1;
    }
    cout << res << endl;
};

/*
    the brute force is to do a DSU  
    i think we can binary search for the min size needed 
    then with a given size we need to check if they are sortable 
    this kinda give give dsu vibes, i forgot stuff about cycle sort and perm sort 
    can try with dsu, so no graph needed 
    -> use edges to join 
    -> then we need to check if the result can be sorted 
    if arr[i] != i-1, we can just check if the two nodes are connected, the if all are connected return true;

*/


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
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
