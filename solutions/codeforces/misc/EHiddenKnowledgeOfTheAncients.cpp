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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
int tc = 0;
void solve(){
    tc++;
    int n,k,left,right;
    cin >> n >> k >> left >> right;
    vi a(n);
    for (auto& z:a) cin >> z;
    if (tc == -1){
        string s = "";
        s+= to_string(k);
        s+=":";
        s+= to_string(left);
        s+=":";
        s+= to_string(right);
        s+="...";
        for (auto& z:a){
            s+= to_string(z);
            s+=".";
        }
        cout << s << endl;
        return;
    }
    vpi evl(n);
    for (int i = 0; i <n; i++) evl[i] = {n,-n};

    map<int,int> mp;
    //two sliding windows 
    auto chk = [&](int x) -> int {
        if (mp.count(x)) return mp.size();
        else return mp.size() + 1;
    };
    for (int l = 0, r = 0; l < n; l++){
        while(r < n && chk(a[r]) <= k){
            mp[a[r]]++;
            r++;
        }
        if (mp.size() == k) evl[l].S = r-1;
        mp[a[l]]--;
        if (mp[a[l]] ==0) mp.erase(a[l]);
    }
    mp.clear();

    for (int l = 0, r = 0; l <n ; l++){
        while(r < n && chk(a[r]) <= k){
            if (mp.size() == k) break;
            mp[a[r]]++;
            r++;
            if (mp.size() == k) break;
        }
        if (mp.size() == k) evl[l].F = r-1;
        mp[a[l]]--;
        if (mp[a[l]]==0) mp.erase(a[l]);
    }
    debug(evl);
    ll res =0;
    for (int i = 0; i < n; i++){
        int l = evl[i].F, r = evl[i].S;
        int x = min(r, i + right - 1) - max(l, i + left - 1 ) + 1;
        debug(x);
        if (x > 0) res += x;
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
