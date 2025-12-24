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

// centroid decomposition optimiastion 
// the main idea doesnt involve centroid decomposition 
// main idea: 
//  for eac subtree store the shortest distance to a RED node 
//  then when we query, we chekc this node as its own root, but, then we check its parents subtree recursively 
//  the idea is that either the best is in this subtree, or its parent's subtree, for the latter it must go through the 
//  parent node, so we can do dist(u,parent) + best[parent]
//
//the centroid decomposition comes as optimization along with properties that still maintains correctness 
//  if the original tree is a straight line, the above solution will have (n log n) per query (log n for distance, or O(1))
//  we can use centroid decomposition to make a new tree, and a very imporant property is that subtree of the centroid decomp are all 
//  CONNECTED (without gaps) in the actual tre (no gaps) 
//  
//  key properties 
//  1. every original node has at most log n parents in centroid ancestors (trivial to see)
//  2. for any two nodes u, v, their path passes through their lowest common CENTROID ancestor 
//
//  reasoning for correctness: 
//  let V be the closest colored node to U (which is the queried node) 
//  then there exists csome centroid C such that 
//    - C is an ancestor of both U and V in the centroid tree, 
//    - C is the LOWEST such ancestor 
//  AND 
//  - C lies on the path between u and v in the original tree 
//
//  by removing the lowest common centroid ancestory, it is the node that separates U and V 
//
//  also pick any subtree from the centroid tree 
//  - it is connected in the original tree AND 
//  - any node connecte to it in the original tree IS A CENTROID PARENT of this ssubtree
//
//  CLAIM 
//  - either the closest node is in this subtree 
//  - OR its blocked off by some ancestor 
//  this is true because any adjacent node IS the centroid parent 
//
//  when we do best[V], it is the best in the CENTROID tree NOT original tree

vvi g;
vb gone;
vi sub_size; 
vi min_dist;
vvpi ancestor;

int get_sub_size(int u, int p){
    sub_size[u] = 1;
    for (int v:g[u]){
        if (v==p || gone[v]) continue;
        sub_size[u] += get_sub_size(v,u);
    }
    return sub_size[u];
};

int find_centroid(int u, int size, int p){
    for (int v: g[u]){
       if (v == p || gone[v])  continue;
       if (sub_size[v] * 2 > size) return find_centroid(v,size,u);
    }
    return u;
};

void add_dist(int u, int cent, int p = -1, int d = 1){
    for (int v:g[u]){
        if (gone[v] || v == p) continue;
        add_dist(v,cent,u,d+1);
    }
    ancestor[u].pb({cent, d});
};

void build_decomp(int u){
    int cent = find_centroid(u, get_sub_size(u, -1), -1);

    for (int v:g[cent]){
        if (gone[v]) continue;
        add_dist(v, cent, cent); //add distance to current centroid 
    }
    gone[cent] = true; //remove this 
    for (int v:g[cent]){
        if (gone[v]) continue;
        build_decomp(v);
    }
}

void color(int u){
    // update all parents 
    for (auto& [p, d]: ancestor[u]){
        // cerr << p << " : " << d << endl;
        min_dist[p] = min(min_dist[p], d); // dist is the distance to ancestor
    }
    min_dist[u] = 0;

};

int query(int u){
    int ans = min_dist[u];
    for (auto& [p,d]: ancestor[u]){
        ans = min(ans, min_dist[p] + d);
    }
    return ans;

}


void solve(){
    int n, m;
    cin >> n >> m;
    g.assign(n, vi());
    sub_size.assign(n,0);
    gone.assign(n,false);
    ancestor.assign(n, vpi());
    min_dist.assign(n, 10*n);

    for (int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    // debugm(g);
    build_decomp(0);
    color(0);


    while(m--){
        int t,u; cin >> t >> u;
        u--;
        if (t==1){
            color(u);
        } else{
            int evl = query(u);
            cout << evl << endl;
        }
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
