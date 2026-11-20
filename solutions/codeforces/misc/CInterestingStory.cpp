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


// i misread the problem 
// the letter needs to be > SUM of all letters COMBINED 
// dog shit writing 
//
//

void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& z: a) cin >> z;
    // comvert words to mpa
    vi curr(5);
    for (auto& w: a){
        for (char& c: w) curr[c-'a']++;
    
    }

    int v = 0, s = 0;
    for (auto& z:curr){
        v = max(v, z);
        s += z;
    }
    if (v > s - v){
        debug(n,a);
        cout << n << endl;
        return;
    }
    // if there is a tie 
    // then we go through all words 
    // if 1 char has less than all other tie chars, we win 
    //


    char t = '.';
    auto cmp = [&](const auto& p, const auto& q) -> int {
        // debug(p,q,t);
        int cnt1 = p.size(), cnt2 = q.size();
        for (char c: p) if (c == t) cnt1 -= 2;
        for (char c: q) if (c == t) cnt2 -= 2;
        return cnt1 > cnt2;
    };
    int sort_idx = 0;
    int res = 0;
    cerr << endl;
    for (int i = 0; i < 5; i++){
        t = (char)(i + 'a');
        sort(all(a), cmp);

        vi cnt = curr; 
        for (int j = 0; j < n; j++){
            for(char& c: a[j]){
                cnt[c-'a']--;
            }
            v = 0, s = 0;
            for (auto& cc: cnt){
                v = max(v,cc);
                s += cc;
            }
            if (v > s - v){
                res = max(res, n - 1 - j);
                break;
            }
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
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
