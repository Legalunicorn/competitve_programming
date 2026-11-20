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
const int inv= 1e9;

// this is like greedy i know 
// we find the next "a" the next "b" then next "c"


void solve(){

}

// let next[i][c] be the position of the NEXT "c" starting at i 
//
class Solution {
public:
    long long countValidSubstrings(string s) {
        int n  = s.size();
        int INV = n*10;
        vvi nxt(n+5, vi(3,INV));
        vector<char> cc = {'a','b','c'};
        ll res = 0;
        for (int j = 0; j < 3; j ++){
            int c = cc[j];
            for (int i = n-1; i>=0; i--){
                if (s[i]==c) nxt[i][j] = i;
            }
            for (int i = n-1; i >= 0; i--){
                nxt[i][j] = min(nxt[i][j], nxt[i+1][j]);
            }
        }
        cout << "ok" << endl;
        for (int i = 0; i < n; i++){
            int a = nxt[i][0];
            if (a == INV){
                res +=  n -i;
                continue;
            }
            int b = nxt[a+1][1];
            if (b == INV){
                res += n-i;
                continue;
            }
            int c = nxt[b+1][2];
            if (c == INV){
                res += n-i;
                continue;
            }
            res += c - i;
        }
        return res;


    }
};


#ifdef LOCAL
// int main(){
//     Sololution sol;
//     cout << sol.countValid
//     int t = 1;
//     // cin >> t;
//     while(t--) solve();
//     cerr << " == END ==" << endl;
//     return 0;
// }
#endif
