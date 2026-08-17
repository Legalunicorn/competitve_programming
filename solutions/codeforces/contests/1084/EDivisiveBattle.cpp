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


set<int> factor(int n){
    set<int> st;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            st.insert(i);
            n /= i;
        }
    }
    if (n>1) st.insert(n);
    return st;
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto&z:a) cin >> z;
    string A ="Alice", B = "Bob";

    // vi suf(n);
    // suf[n-1] = a[n-1];
    // int mn = a[n-1];
    // for (int i = n-1; i >= 0; i--){
    //     mn = min(mn, a[i]);
    //     suf[i] = mn;
    // }

    // debug(suf);

    bool fail = false;
    for (int i = 1; i < n; i++){
        if (a[i] < a[i-1]) fail = true;
    }
    // game ends before it started
    if (!fail){
        cout << B << endl;
        return;
    }
    // maybe not > suff[i+1] 
    // but its > mx 
    vpi g(n);
    for (int i = 0; i < n; i++){
        set<int> st = factor(a[i]);
        if (st.empty()) st.insert(1);
        int h = *st.rbegin();
        int l = *st.begin();
        g[i] = {l,h};


    }
    vi s2(n);
    int mn = g[n-1].F;
    for (int i = n-1; i >= 0; i--){
        mn = min(mn, g[i].F);
        s2[i] = mn;
    }

    for (int i = 0; i < n; i++){
        int l = g[i].F;
        int h = g[i].S;
        if (i + 1 < n && h > s2[i+1] ){
            cout <<A << endl;
            return;
        }
        if (h > l){
            cout << A<< endl;
            return;
        }
    }


    // mn = g[n-1].


    cout << B << endl;
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
    return 0;
}
