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
    string s;
    cin >> s;
    if (n <= 2) {
        cout << 1 << endl;
        return;
    }

    int start = n+1, end = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (s[i] == '1'){
            cnt ++;
            start = min(start,i);
            end = max(end,i);
        }
    }
    // debug(start,end, s);
    if (cnt == 0){
        for (int i = 1; i<n;i+=3) s[i] = '1';
        // int last = 1;
        // s[1] = '1';
        // for (int i = 2; i < end; i++){
        //     if (s[i] == '1'){
        //         last = i;
        //         continue;
        //     }  
        //     if (last == i-1) continue;
        //     if (last == i-2) continue;
        //     s[i] = '1';
        //     last = i;
        // }
        if (s[n-1] == '0' && s[n-2] == '0') s[n-1] = '1';
    } else {
        for (int i = start - 3 ; i >= 0; i -= 3){
            s[i] = '1';
        }
        for (int i = end + 3; i < n; i += 3){
            s[i] = '1';
        }
        if (s[0] == '0' && s[1] == '0') s[0] = '1';
        if (s[n-1] == '0' && s[n-2] == '0') s[n-1] = '1';
        int last = start;
        for (int i = start+1; i < end; i++){
            if (s[i] == '1'){
                last = i;
                continue;
            }  
            if (last == i-1) continue;
            if (last == i-2) {
                if (i+2 < n && s[i+2] == '1' && s[i+1] == '0'){
                    debug(i,s);
                    s[i] = '1';
                    continue;
                }
                continue;
            }
            if (i+1<n && s[i+1]=='1') continue;
            s[i] = '1';
            last = i;
        }
    }
    debug(s);
    int res = 0;
    for (char c: s) if (c=='1') res++;
    cout << res << endl;

    // vi s


    // s = "10" + s + "01";
    //
    // for (int i = 0;i < n + 4; i++){
    //     if (s[i] == '1') continue;
    //     if (i+1 <= n+1 && s[i+1] == '1') continue; // cannot be flipped 
    //     if (i-1 >= 0 && s[i-1] == '1') continue; // cannot be flipped 
    //     // the above are absolute
    //
    //     if  (i-2 >= 0 && s[i-2] == '0'){
    //         s[i] = '1';
    //         continue;
    //     }
    // }
    // int res = 0;
    // s = s.substr(2,n);
    // for( char c: s) if (c=='1') res++;
    // debug(s);
    // cout <<  res << endl;
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
