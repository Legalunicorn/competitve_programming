#include <bits/stdc++.h>
#include <queue>
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


// NOTE: 
// if they are all >= 2 or <= 0
// we can use all of them fine 
// the only issues is cards with "1" 
// -> we can use them in slots with >= 4, then we replace 


void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;

    if (n == 1){
        if (a.back() <= 2) cout << 0 << endl;
        else cout << a.back()<<endl;
        return;
    }

    priority_queue<ll> pq;
    ll res = 0;
    int one = 0;
    int take = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 1) one++;
        else {
            take++;
            res += a[i];
            if (a[i] >= 4) pq.push(a[i]);
        }
    }

    if (take == 1 && one > 0){
        res++;
        one--;
    }

    for (int i = 0; i < one; i++){
        if (pq.empty()) break;
        ll t =  pq.top();
        pq.pop();
        res++;
        if (t-2 >= 4) pq.push(t-2);
    }
    cout << res << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
