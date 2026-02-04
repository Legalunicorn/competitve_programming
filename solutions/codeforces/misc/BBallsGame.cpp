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


// im actually stumped how to implement this 
// 1 1 .. 1 1 
// we know that the max length is .. (4) 
//




void solve(){
    // just spam simulation 
    int n,k, x;
    cin >> n >> k >> x;
    int res = 0;
    vi a(n);
    for (auto& z:a) cin >> z;

    //
    auto go = [&](auto& go, vi& b) -> void{
        stack<int> st;
        int evl = 0;
        vb skip(n, false);
        for (int i =0; i < b.size(); i++){
            if (skip[i]) continue;
            if (st.size() < 2 || st.top() != b[i]) {
                st.push(b[i]);
                continue;
            } else{
                // check for at least 2 
                int u = st.top(); st.pop();
                if (st.top() != u){
                    st.push(u);
                    st.push(b[i]);
                    continue;
                } else{
                    // at least 3 securequeue 
                    debug(i, b[i+1], b[i]);
            
                    int cnt = 2;
                    if (i+1<b.size() && b[i+1] == b[i]) {
                        cnt++;
                        skip[i+1] = true;
                    }
                    while(st.size() > 0 && st.top() == b[i]){
                        cnt ++;
                        st.pop();
                    }
                    evl += cnt;
                }
            }
        }
        debug(evl-1);
        res = max(res,evl-1);
    };
    //
    //

    for (int i = 1; i < n; i ++ ){
        vi b;
        for (int j = 0; j < i ; j ++) b.pb(a[j]);
        b.pb(x);
        for (int j = i; j < n; j++ ) b.pb(a[j]);
        debug(b);
        go(go,b);
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
