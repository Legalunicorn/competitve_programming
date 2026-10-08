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
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> st;
    vb done(n);
    vi res;
    debug(n,s);
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            debug("p", i+1);
            st.push(i+1);
            
        } else if (s[i]=='2'){ // pop 
            if (!st.empty()){
                int t= st.top();
                st.pop();
                debug(t);
                done[t-1] = true;
                // st.push(i+1); // didnt print
                debug("pp",i+1);
            } else {
                done[i] = true;
            }
        } else{ // s[i] == 3
            debug("print",i+1);
            done[i] = true;
        }
    }
    debug(done);
    int cnt =0;
    vi ans;
    for (int i = 0; i < n ;i++){
        if (!done[i]){
            ans.pb(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    for (auto& z:ans) cout << z+1 << " ";
    cout << endl;
    // vi t;
    // while(!st.empty()){
    //     t.pb(st.top());
    //     st.pop();
    // }
    // sort(all(t));
    // debug(n,s,t);
    // cout << t.size() << endl;
    // for (auto& z: t) cout << z << " ";
    // cout << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
