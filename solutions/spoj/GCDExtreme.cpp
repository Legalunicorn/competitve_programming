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

// preompute
const int N = 1000005;
ll f[N];
ll phi[N];
ll res[N];

void init(){
    for (int i = 1; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i++){
        if (phi[i] == i){
            for (int j = i; j < N; j+=i) 
                phi[j] -= phi[j]/i;
        }
    }
    // precompute f, using sieve like tool where i =d 
    for (int i = 1; i < N; i++){
        for (int j = i; j < N; j += i ){
            f[j] += 1LL * i * phi[j/i];
        }
    }

    // prefix sum 
    for (int i =1; i<N;i++){
        res[i] = res[i-1] + f[i] - i;
    }
}

void solve(){
    int n;
    while(cin >> n && n!=0) cout << res[n] << endl;
    // ll n;
    // cin >> n;
    // cout << res[n] << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
