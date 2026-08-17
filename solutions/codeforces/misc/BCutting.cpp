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

void solve(){
    int n;
    cin >> n;
    int b;
    cin >> b;
    vi a(n);
    for (auto& z:a) cin >> z;
    // just identify all cut points, sort 
    vi costs;
    int odd = 0, even = 0;
    for (int i=0;i+1<n;i++){
        if (a[i]%2==0) odd++;
        else even++;
        if (odd==even) costs.pb(abs(a[i+1]-a[i]));
        if (odd==even) debug(i);
    }
    // sort(costs.rbegin(),costs.rend());
    sort(all(costs));
    debug(costs);

    int cuts = 0;
    for (int i=0;i<costs.size();i++){
        if (costs[i] <= b){
            cuts++;
            b -= costs[i];
        }
    }
    cout << cuts << endl;
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
