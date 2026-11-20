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
    ll n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    vl l(n, -1);
    vl r(n, -1);
    stack<ll> st;
    ll mx = MAX(a);
    bool inside = false;

    // 10 9 8 7 3 9 
    //  Mono stack
    //  -> identiies the LEFT and RIGHT 
    //  -> not necesary the min steps 
    //  dp[i][l]
    //  at most n*2 pointers 
    //  why cant i recursion this?
    

    // you can change direction 
    // dp[i][0] -> fastest way if we go left 
    // dp[i][1] -> fatest way if we go right 
    // if a[i] == max 
    //  -> 
    for (int i = 0; i < n; i++){
        if (a[i] == mx) inside = true;
        while(!st.empty() && a[st.top()]<= a[i]) st.pop();
        if (st.size()>0) l[i] = st.top();
        st.push(i);
    }
    st = stack<ll>();
    inside = false;
    for (int i = n-1;i>=0;i--){
        if (a[i] == mx) inside= true;
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.size()>0) r[i] = st.top();
        st.push(i);
    }
    debug(l);
    debug(r);
    
    vl dp(n,-1);
    auto go = [&](auto& go, int i) -> ll{
        if (dp[i]!=-1) return dp[i];
        if (a[i] == mx) return dp[i]=0ll;
        ll res = INF;
        if (l[i] != -1) res = min(res, 1+go(go, l[i]));
        if (r[i] != -1) res = min(res, 1+go(go, r[i]));
        return dp[i] = res;
    };
    for (int i = 0; i < n; i++){
        if (dp[i] == -1) go(go,i);
        cout << dp[i] << " ";
    }
    debug(dp);


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
