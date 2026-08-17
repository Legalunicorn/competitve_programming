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

int tc = 0;
void solve(){
    tc++;
    int n,k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    if (k >= n){
        cout << (s == t ? "Yes":"No") << endl;
        return;
    }
    if (k==1 && n ==1){
        cout << (s == t ? "Yes":"No") << endl;
        return;
    }
    if (n >= 2*k){
        debug("heh");
        sort(all(s));
        sort(all(t));
        cout << (s==t ? "Yes":"No") << endl;
        return;
    }

    // find leftand right 
    int l = n - k;
    int r = k - 1;
    debug(tc, l, r);

    vector<char> s1, s2;
    for (int i=0;i<n;i++){
        if (i<l || i>r) {
            s1.pb(s[i]);
            s2.pb(t[i]);
        } else{
            if (s[i] != t[i]){
                cout << "No" << endl;
                return;
            }
        }
    }
    sort(all(s1));
    sort(all(s2));
    cout << (s1 == s2 ? "Yes" :"No") << endl;


    // no restrictions on k?.. 
    // n - 1 - k + 1 
    // n - k
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
