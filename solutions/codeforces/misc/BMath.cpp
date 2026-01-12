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



vector<int> factor(int n){
    vector<int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res.push_back(i);
            n /= i;
        }
    }
    if (n>1) res.push_back(n);
    return res;
}

void solve(){
    debug(2*2*2*2*3*3*3*3);
    int n;
    cin >> n;
    vi facs = factor(n);
    map<ll,int> mp;
    int  mn = 1000000;
    int mx = 1;
    ll ans = 1;
    for (auto& x: facs){
        mp[(ll)x]++;
    }
    for (auto& [val,cnt]: mp){
        ans *= val;
        mx = max(mx, cnt);
        mn = min(mn,cnt);
    }
    debug(mx,mn);
    debug(mp);
    if (mx ==1){
        cout << n << " " << 0 << endl;
        return;
    }
    // mx == mn, and is a power of 2 

    int count = 0;
    int curr = 1;
    while(curr < mx){
        curr *=2; 
        count ++;
    }
    cout << ans << " ";
    if (curr == mx && mn == mx){
        cout << count << endl;
    } else{
        cout << count+1 << endl;
    }



    // find the smallest power of 2 larger

    // int res =0;
    // // ll  ans = (ll)n;
    // int itr = 0;
    // while(true && itr < 100000){
    //     debug(mp);
    //     itr++;
    //     bool odd = false, more = false;
    //     for (auto& [val,cnt]: mp){
    //         if (cnt > 1) {
    //             more = true;
    //         }
    //         if (cnt % 2 == 1) {
    //             odd = true;
    //         }
    //     }
    //     debug(odd,more);
    //     if (!more) break;
    //     if (odd) res++; // we need to convert 
    //     for (auto& [val,cnt]: mp){
    //         mp[val] = (cnt+1)/2;
    //     }
    //     res++;
    // }
    //
    // ll ans = 1;
    // for (auto& [val,cnt]: mp){
    //     ans *= val;
    // }
    // cout << ans << " " << res << endl;
    // vi freq;
    // for (auto& [v,c]: mp) freq.pb(c);
    // int mx = MAX(freq);
    // int res = 0;
    // while(true){
    //     bool odd = false, more = false;
    //     for (int i=0;i<freq.size();i++){
    //         if (freq[i]>1) more = true;
    //         if (freq[i] % 2 == 1) odd = true;
    //     }
    //     if (!more) break;
    // }
    // repeat until reach prime factor appear exaclty once, how? 
    // lets say the freq is like 3 2 1 2 3 3 2 5 8 
    // white max > 1 
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
