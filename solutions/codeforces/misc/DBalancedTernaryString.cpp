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
void solve(){
    int n;
    cin >> n;
    string s; cin >> s;
    int zero = 0, one = 0, two = 0;
    for (char c:s){ 
        if (c=='0') zero++;
        else if (c=='1') one++;
        else two++;
    }
    int m = n/3;

    debug(zero,one,two);
    
    // forward push: increase zeros (< m) to one or two, increase one to two,
    for (int i=0;i<n;i++){
        if (s[i] == '0'){
            // skip
            continue;
        } else if (s[i] == '1'){
            // we on want to change to 0  
            if (one > m && zero < m){
                zero++;
                one--;
                s[i] = '0';
            }
        } else { // we see a "2"
            if (two > m){
                if (zero < m){
                    zero++;
                    two--;
                    s[i] = '0';
                } else if (one < m ){
                    one++;
                    two--;
                    s[i] = '1';
                }
            }
        } 
    }
    debug(zero,one,two, s,m);

    // we have to compensation backwards now 
    // because we want lex largest, we change to the worst string 
    for (int i = n -1; i>=0; i--){
        if (s[i] == '0'){
            if (zero ==m) continue;
            if (zero > m){
                // convert to a "2" 
                if (two < m){
                    two ++;
                    zero --;
                    s[i] = '2';
                } else if ( one < m){
                    one ++;
                    zero--;
                    s[i] = '1';
                }
            }
        } else if (s[i] == '1'){
            if (one == m )continue;
            if (one > m){
                if (two < m ){
                    two ++;
                    one --;
                    s[i] = '2';
                }
            } 
        } else{
            if (two == m ) continue;
            if (two > m){
                if (one < m){
                    one ++;
                    two --;
                    s[i] = '1';
                } else if (zero < m){
                    zero ++;
                    two --;
                    s[i] = '0';
                }
            }

        }
    }
    debug(zero,one,two);
    cout << s << endl;

    // 
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
