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
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;


struct Dsu{
public:
    int n; 
    vector<int> par, size;
// public:
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


void solve(){
    int n,m;
    cin >>n >> m;
    Dsu dsu(n);
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v,u--,v--;
        dsu.union_set(u, v);
    }
    // mape each each person to their group 
    using grp = array<int,3>; // teams 
    vector<grp> ans;
    vpi twos;
    vi ones;
    map<int,vi> mp;

    for (int i=0;i<n;i++){
        int p = dsu.find(i);
        mp[p].pb(i);
    }
    for (auto& [grp, people]: mp){
        if (people.size()>3){
            cout << -1 << endl;
            return;
        } else if (people.size()==3){
            ans.pb({people[0],people[1],people[2]});
        } else if (people.size()==2){
            twos.pb({people[0],people[1]});
        } else if (people.size()==1){
            ones.pb(people[0]);
        }
    }
    // now we match every twos to ones 
    int j = 0;
    for (int i=0;i<twos.size(); i++){
        if (j == ones.size()){
            cout << -1 << endl;
            return;
        }
        ans.pb({twos[i].F, twos[i].S, ones[j]});
        j++;
    }
    for (;j+2<ones.size();j+=3){
        grp t = {ones[j],ones[j+1],ones[j+2]};
        ans.pb(t);
    }
    for (auto& g: ans){
        for(auto& x: g) cout << x+1 << " ";
        cout << endl;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
