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

// a <= b 
// guaranteed that answer exist 
// b has at least a digits 
// is b has more digits we can just sort 
// if b has the same digits 
// we have to choose the bst? 
// but choosing the best might not guarantee we can geth a's while
//
// a = 4 5 3 3
//
//     3 5 4 3 
// b = 4 4 3 3 
//     4 5 
// we can try for each prefix the "equal length"
// -> 

void solve(){
    string a,b;
    cin >> a >> b;
    if (b.size() > a.size()){
        sort(all(a));
        reverse(all(a));
        cout << a << endl;
        return;
    }
    vi f(10), f2(10);
    for (char c: a) f[c-'0']++;
    for (char c: b) f2[c-'0']++;
    if (f == f2){
        debug("he");
        cout << b << endl;
        return;
    }
    // because a <= b, we can try for all prefixes, the max "equal lengh"
    // as soon as we DIP below we good 
    int n = a.size();
    // how long we go for commong
    string res = "";
    for (int x = 0; x < b.size(); x++){
        string s = "";
        vi freq = f;
        bool valid = true;
        for (int i = 0; i  <n; i++){
            int d = b[i] -'0';
            if (i < x){
                if (freq[d] > 0){
                    freq[d]--;
                    s += to_string(d);
                } else{
                    valid = false; break;
                }
            } else{
                if ( i == x){
                    int op = -1;
                    for (int p = 0; p < d; p++){
                        if (freq[p]>0) op = p;
                    }
                    if (op == -1){
                        valid = false;break;
                    } else {s += to_string(op); freq[op]--;}
                } else{
                    for (int p = 9; p >= 0; p--){
                        if (freq[p]>0) {
                            s += to_string(p);
                            freq[p]--;
                            break;
                        }
                    }
                }
            }
        }
        if (valid) {
            debug(x, s);
            res = s;
        }
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
