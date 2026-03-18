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


// ? -> wild card -> can be either character 
// the pairty of n will tell us the first first/last character
// i can overkill this with dp maybe 
//
// dp[i][option]
//
// but then i also need the front and back pointer 
// which is n^2 
//


// hwo to fix "?"


// i cant solve for the case where "?" is consequetive 
// ? ? a 
// ? ? b 
// the question mark comes in parts 

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int acnt = 0, bcnt =0;
    for (char c: s){
        if (c=='a') acnt++;
        else if (c=='b') bcnt++;
    }
    int afull = n/2;
    if (n%2==1) afull++;
    int bfull = n/2;

    int aleft = afull - acnt;
    int bleft = bfull - bcnt;
    debug(s,aleft,bleft);
    if (aleft < 0 || bleft < 0){
        cout << "NO" << endl;
        return;
    }
    

    int f = 1;
    int b = n;
    for (int i = 0; i < n; i++){
        if (s[i] == 'a'){ // we need an odd index
            if (f%2==0 && b%2==0){
                cout << "NO" << endl;
                return;
            } else if (f%2==1) {
                f++;
            } else{
                b--;
            }
        } else if (s[i] == 'b') {
            if (f%2==1 && b%2==1){
                cout << "NO" << endl;
                return;
            } else if (f%2==0){
                f++;
            } else {
                b--;
            }
        } else {
            // wild card.. 
            if (f%2 == b%2){
                if (f%2==1) {
                    if (aleft <=0){
                        cout << "NO" << endl;
                        return;
                    } else{
                        f++;
                        aleft--;
                    }
                } else{ // both even
                    if (bleft <= 0){
                        cout << "NO" << endl;
                        return;
                    } else{
                        f++;
                        bleft--;
                    }
                }
            // both are differen==t
            // wildcard 
            } else {
                if (i == n-1) {
                    // not possible because f = b 
                    cout << "NO" << endl;
                    return;
                } else {
                    if (s[i+1] == 'a') {
                        // must use the "B"
                        if (bleft <=0){
                            cout << "NO" << endl;
                            return;
                        }
                        if (f%2==0){
                            f++;
                            bleft--;
                        } else {
                            b--;
                            bleft--;
                        }
                    } else if (s[i+1] == 'b') { 
                        if (aleft <= 0){
                            cout << "NO" << endl;
                            return;
                        }
                        if (f%2==1){
                            f++;
                            aleft--;
                        } else {
                            b--;
                            aleft--;
                        }
                    // question mark, just choose either 
                    } else {
                        if (aleft <=0 || bleft <=0){
                            cout << "NO" << endl;
                            return;
                        }
                        if (f%2==1){
                            f++;
                            aleft--;
                        } else {
                            f++;
                            bleft--;
                        }
                    }
                }
            }
        }
    }
    cout << "YES" << endl;

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
