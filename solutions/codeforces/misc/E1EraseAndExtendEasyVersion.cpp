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

// after your double, no more deletes for optmizatoin, but only remove excess k
// whether to delete or not 
//  -> abc....x 
//  a b c a 
//  if any position a[i] < a[i+1]
//  we should delete a[i+1]
//  otherwise the string is d >= c >= b >= a
//  so we just take the longest non decreasing prefix of S then multiply it to length k

void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int stop = n;
    for (int i = 1; i < n; i++){
        int len = n - i - 1;
        string t;
        int p = i;
        for (int j = 0; j < n; j++){
            t += s[p++];
            if (p == n) p = i;
        }
        // string u = s.substr(i, len) + 
        // string st = s.substr(0, len) + s.substr()
        if (t > s) {
            stop = i;
            break;
        }
    }
    debug(stop);

    int p = 0;
    for (int i = 0; i < k; i++){
        cout << s[p++];
        if (p >= stop)  p = 0;
    }
    cout << endl;

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
