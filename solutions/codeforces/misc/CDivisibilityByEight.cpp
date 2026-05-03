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

// this some stupid useless number theorey 
// if the last 3 digits of any number is divisiible by 8, 
// the number is also divisible by 8 

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    // if the last 3 digits is divisible by 8 
    // or if it is one of two 2 multiples of 8 sure
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                int x = (s[k]-'0');
                x += (s[j]-'0') * 10;
                x += (s[i]-'0') * 100;
                debug(x);
                if (x % 8 == 0){
                    cout << "YES" << endl << x << endl;
                    return;
                }
            }
        }
    }
    // just check <= 2 digits as well
    vi dig;
    for (int i = 0; i <= 13; i++){
        dig.pb(i*8);
    }
    debug(s,dig);

    for (auto d : dig){
        // we want to check if any part of this integer is a subsequence of and fuck it just brute force 
        string t = to_string(d);
        int p = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == t[p]){
                debug(t,i,p);
                p++;
                if (p == t.size()){
                    cout << "YES" << endl;
                    cout << t << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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
