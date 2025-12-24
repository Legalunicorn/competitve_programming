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


void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> A(n);
    map<int,int> mp;
    set<int> st;
    vvi g(n);
    
    for (int i=0;i<n;i++){
        int x; cin >> x;
        st.insert(x);
        mp[x] = i;
        A[i] = x;
    }
    // debugv(A);

    for (int i= 0; i < n ;i++){
        int x = A[i];
        int y = a-x;
        int z = b-x;
        if (!st.count(y) && !st.count(z)){
            cerr << "no match: " << endl;
            cout << "NO" << endl;
            return;
        }
        if (st.count(y)){
            // cerr << x << " " << y << endl;
            g[i].pb(mp[y]);
        }
        if (st.count(z)){
            // cerr << x << " " << y << endl;
            g[i].pb(mp[z]);
        }
    }
    set<int> start;
    cerr << " == SIZE == " << endl;
    for (int i=0;i<n;i++){
        // cerr << g[i].size() << endl;
        if (g[i].size()==1) start.insert(i);
    }

    vi grp(n,-1);
    int added = 0;
    // debugm(g);

    auto dfs = [&](auto& dfs, int u) -> void{
        for (int v: g[u]){
            if (grp[v]!=-1) continue;
         
            if (A[u]+A[v]==a) grp[u] = grp[v] = 0;
            else grp[u] = grp[v] = 1;
            if (A[u]==A[v]) added++;
            else added += 2;
            for (int w: g[v]){
                if (w==u || grp[w]!=-1) continue;
                dfs(dfs, w);
            }
        }
    };


    for (auto& s: start){
        // cerr << "st: " << s << endl;
        if (grp[s]!=-1) continue;
        dfs(dfs,s);
    }
    // int cnt = 0;
    // for (int i=0;i<n;i++) if (grp[i]!=-1) cnt++;
    // cerr << "cnt: " << cnt << endl;

    for (int i=0;i<n;i++){
        if (grp[i]!=-1) continue;
        dfs(dfs,i);
    }
    // debugv(grp)
    // cerr << added << endl;


    if (added != n){
        cerr << "added:" <<  added << endl;
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
        for (auto& r: grp) cout << r <<  " ";
        cout << endl;
    }
    /*
        its not possible for there the be a cycle in relation 
        and also there is a max of 2 edges per number 
        so everything is at most a line, and we can construct from the edge? 
        when we put a number and its pair into a set, we can foreget about the other ocndition 

        we need to consider some cases 
        1. a number pointing to itself 
        2. can we do a graph traversal? 
        1. start from node with in/out degree of 1 
        3. when we take the node and its niehgbor, we have to "skip" 
        4. u take v, then we check of v has someone else
        5 .
    */
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
