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

void solve(){
    int n;
    cin >> n;
    ll res = 0;
    map<ll,ll> mp;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        mp[x]++;
    }
    vl a;
    int pairs = 0;
    for (auto& [val,cnt]: mp){
        if (cnt >= 2){
            ll p = cnt/2;
            res += (p * 2 * val);
            pairs += p;
        }
        if (cnt % 2 == 1) a.pb(val);
    }

    if (pairs == 0){
        cout << 0 << endl;
        return;
    }
    ll sum = res;
    // case 1: one pair 
    for (auto& x: a){
        if (x < sum) res = max(res, x + sum);
    }
    for (int i = 0; i + 1 < a.size(); i++){
        ll x = sum + a[i];
        ll y = a[i+1];
        if (x > y) res = max(res, sum + a[i] + a[i+1]);
    }
    if (pairs == 1 && sum == res){
        cout << 0 << endl;
        return;
    }
    cout << res << endl;







    // max possible perimeter 
    // i know triangle, -> longest stick shorter than all other sticks combined 
    // but we must also be symmetrical 
    // this is a greedy problem 
    // we are allowed:
    // 1. 1 super long stick 
    // 2. x pairs of same size sticks 
    // 3. 1 remaining stick 
    //
    // and second constraint is that: 
    // the length of all sticks except longest must be greater than longest 
    // 1. if we ONLY use PAIRS, it is possible as long as it is >1 pair 
    //
    // 2. we can greedy consume all pairs 
    // then our remaining one/two sticsk 
    // case 1: one stick 
    //  -> find the largest stick smaller than sum 
    //
    // case 2: two stick 
    //  -> 1. suppose we fix the longest stick 
    //  -> 2. the the next obvious stick is the one right below it 
    //
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
