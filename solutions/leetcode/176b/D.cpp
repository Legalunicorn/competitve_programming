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

#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;
const int inv= 1e9;




struct FenwickTree {
    int n;
    vector<ll> tree;

    FenwickTree(int n) : n(n), tree(n + 1) {}

    void add(int k, int d) {
        while (k <= n) {
            tree[k] += d;
            k += k & -k;
        }
    }

    ll query(int k) {
        ll s = 0;
        while (k > 0) {
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }
};


const int N = 50005;
vector<int> g[N];
int order_in[N], order_out[N], order_index = 1;

void dfs(int node, int parent) {
    order_in[node] = order_index++;
    for (int child : g[node]) {
        if (child == parent) continue;
        dfs(child, node);
    }
    order_out[node] = order_index;
}

int value[N];

// stupid fucking input 

vector<string> split(string s,string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

// 1. maintain 26 trees for each character 
// subproblem can we we easily find the weight between any path? 
// no HLD 
// yes we can technocally find 
// 1. count form root to V 
// 2. count from root to U 
//
// take the absoluvalue value difference of two two 

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {

        vb res;
        for (int i = 0; i + 1 < n; i++){
            int u = edges[i][0], v = edges[i][1];
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1,-1);

        vector<FenwickTree> ff(26, FenwickTree(N));
        for (int i = 0; i < 26; i++){
            int v = s[i]-'a';
            if (v == i) v = 1;
            else v = 0;
            ff[i].add(order_in[i], v);
            ff[i].add(order_out[i], -v);
        }
        int id = 0; 

        for (int q = 0; q < queries.size(); q++ ){
            string qq = queries[q];
            vector<string> arr = split(qq," ");
            if (arr[0] == "update"){
                int u = stoi(arr[1]);
                int old = (s[u] - 'a');
                int id = (char)(arr[2][0]) -'a';

                // set this to 
                ff[old].add(order_in[u], -1);
                ff[old].add(order_out[u], 1);
                s[u] = arr[2][0];
                ff[id].add(order_in[u], 1);
                ff[id].add(order_out[u], -1);

            } else {
                int cnt = 0; 
                int u = stoi(arr[1]);
                int v = stoi(arr[2]);
                for (int i = 0; i < 26; i++){
                    int x = ff[i].query(order_in[u]);
                    int y = ff[i].query(order_in[v]);
                    int d = abs(x - y);
                    if (d%2==1) cnt++;
                    if (cnt > 1) break;
                }
                if (cnt <= 1) res.pb(true);
                else res.pb(false);
            }
        }


        return res;



    }
};


void solve(){
    
}


#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif
