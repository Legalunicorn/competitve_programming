#include <bits/stdc++.h>
#include <sstream>
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
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

vector<string> split(string& s, char delim){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream, token, delim)) tokens.pb(token);
    return tokens;
}

void solve(int n ){
    // we just want to know
    map<string, int> mp;
    int id = 0;
    for (int i = 0; i < n; i++){
        string code; cin >> code;
        mp[code] = id++;
    }
    int m; cin >> m;
    //edes

    vector<vector<pair<int, ld>>> g(n+1);
    for (int i = 0; i < m; i++){
        string a,b,c; cin >> a >> b >> c;
        vector<string> r = split(c,':');
        ld num = stold(r[1]);
        ld dem = stold(r[0]);
        ld edge = num/dem;
        ld lg = -log(edge);
        int u = mp[a];
        int v = mp[b];
        g[u].pb({v, lg});
    }

    vector<ld> dist(n+1, INF);
    int super = n;
    dist[super] = 0.0;
    for (int i = 0; i < n; i++) g[super].pb({i,0.0});
    int tot = n+1;
    for (int i = 0; i  < tot - 1; i++){
        // relax all edges 
        for (int u = 0; u < tot; u++){
            for (auto& [v, wt]: g[u]){
                if (dist[u] + wt < dist[v] - 1e-12){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }
    debug(dist);
    // extra 
    for (int u = 0; u < tot; u++){
        for (auto& [v, wt]: g[u]){
            if (dist[u] + wt < dist[v] - 1e-12){
                cout << "Arbitrage" << endl;
                return;
            }
        }
    }
    cout << "Ok" << endl;

    // run bell man fords algorithm? 
    //
};

int main(){
    ios::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(cin >> T && T != 0){
        solve(T);
    }
    cerr << " == END ==" << endl;
    return 0;
}
