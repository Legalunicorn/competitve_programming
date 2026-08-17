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

void solve(){
    int n, t;
    cin >> n >> t;
    vi a(n);
    for (auto& z:a) cin >> z;
    // int t; cin >> t;
    set<int> st(all(a));
    bool valid = false;
    if (t == 1){
        for (int i = 0; i < n; i++){
            int x = 7777 - a[i];
            if (st.count(x)) valid = true;
        }
        cout << (valid ? "Yes":"No");
    } else if (t == 2){
        if (st.size() == n) cout << "Unique";
        else cout << "Contains duplicate";
    } else if (t == 3){
        map<int,int> mp;
        int ans = -1;
        for (auto& z: a){
            mp[z]++;
            if (mp[z] > n/2) ans = z;
        }
        cout << ans;
    } else if (t == 4){
        sort(all(a));
        if (n % 2 == 1) cout << a[n/2];
        else {
            cout << a[n/2-1] << " " << a[n/2];
        }
    } else{
        sort(all(a));
        for (auto& z:a){
            if (z >= 100 && z <= 999) cout << z << " ";
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
    while(T--) solve();
    return 0;
}
