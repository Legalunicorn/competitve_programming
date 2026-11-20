#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;



// NOTE:
// necessary condition: they are leaves
// but not sufficent, two leaves may not be diameter D apart 
// we need a mechanism to compute distance pairs some how 
// we can fix a ROOT
// -> special case: ROOT can be a leaf
// -> normla case: ROOT multiple children no leaf 
//
// -> reduce the tree?
// -> 
//  -> trivial to find diameter, D 
//
// -> alternatively -> find a diameter end point of a tree -> make it root 
// -> this NODE MUST be a leaf 
//
//     -> this solves easily for color[v]
//     -> we can try to reroot 
//
//
//     depth does not matter its not good 
//
// alteritive
// -> if we check by color, the totla check is tehnically O[n]
// -> can we try to build trees for each color, with weightaed edges? 
// -> impossible to construct
// then its necessary we just ocunt pairs in the new tree? 
//
//
// ALTERNATIVE:
// some reroot bullshit that works because the color .. nah dont wokr
//
//
// BUG: is it possible for two nodes.. yes 
// BUG: two diameter nodes may not be diameter distance apart
//
// can we over count then reduce? 
// this is NOT reroot
// we can most likely start from diamter node would be useful 
//
// suppose we have some leaf and we knew the distance to all other leaf of same color 
// it doesnt give us ALL the pairs for this color 
// O(n)
// for each color 
//      for eac node
//
//
//
// lets try to reduce this problem
// count all diameter pairs 
// -> reroot DP can trivially solve, just keep track of max depth  but ths color. i dont think its possibel
//
//
// we need to go to proving mode 
//
// can we try some delete nodes solution? 
// start from arbitariart diameter D 
// -> find all dist = D, and matching COLOR 
// -> put all of them in a LIST 
// -> do some traverseal with THESE as a base 
//      -> multisource BFS 
//      -> guess, it will
//
//
// start -> end list 
// end list -> multiscure bfs  back -> 
//
// i only figure out how to solve for 1 color in O(n) but there are n colors ? 
//
//
// alternative 
// -> arbitaray root 
// -> DFS and find ALL the max distances
// -> keep these nodes as a LIST 
// -> multisource BFS from this new list 
// -> gues
//
//
// undercounting 
// within S and within E 
// there can be pairs as well
// how tf do i count within S

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    for (int i = 0; i + 1< n;i ++){
        int u,v;
        cin >>u >> v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi col(n);
    for (auto& z: col) cin >> z;
    debug(col);
    int dist = 1;
    queue<int> q;
    q.push(0);
    vb seen(n);
    seen[0] = true;
    map<int,vi> mp;
    int s = 0;
    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++){
            int u = q.front();
            q.pop();
            for (auto& v: g[u]){
                if (!seen[v]){
                    seen[v] = true;
                    q.push(v);
                    s = v;
                }
            }
        }
        dist++;
    }
    // s is guaranteed to be blah bla
    dist = 1;
    q = queue<int>();
    q.push(s);
    seen.assign(n, false);
    mp[0].pb(s);
    seen[s] = true;
    int dia = 0;
    // map<int,int> mp;
    // int s = 0;
    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++){
            int u = q.front();
            q.pop();
            for (auto& v: g[u]){
                if (!seen[v]){
                    seen[v] = true;
                    q.push(v);
                    s = v;
                    // actually assign v
                    mp[dist].pb(v);
                    dia = max(dia, dist);

                }
            }
        }
        dist++;
    }

    ll res = 0;
    map<int,int> st;
    map<int,int> end;
    seen.assign(n, false);
    q = queue<int> ();
    for (auto& u: mp[dia]){
        q.push(u);
        int c = col[u];
        st[c]++;
    }
    dist = 1;
    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++){
            int u = q.front();
            q.pop();
            for (auto& v: g[u]){
                if (!seen[v]){
                    seen[v] = true;
                    q.push(v);
                    s = v;
                    if (dist == dia){
                        int c = col[v];
                        end[c]++;
                    }
                }
            }
        }
        dist++;
    }
    for (auto& [c,f]: st){
        ll ff = end[c];
        res += f * ff;
    }
    cout << res << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
