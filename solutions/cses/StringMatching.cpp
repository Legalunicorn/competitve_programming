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


struct KMP{
    vector<int> search(string text, string pat){
        int n = text.size(), m = pat.size();
        vector<int> lps(m), res;
        construct(pat,lps);
        int i =0, j = 0;
        while(i<n){
            if (text[i]==pat[j]){
                i++, j++;
                if (j == m){
                    res.push_back(i-j);
                    j = lps[j-1];
                } 
            } else{
                if (j!=0) j = lps[j-1];
                else i++;
            }
        }
        return res;
    }
private:
    void construct(string pat, vector<int>& lps){
        int len = 0, i =1;
        while (i< pat.size()){
            if (pat[i] == pat[len]){
                lps[i++] = ++len;
            } else{
                if (len) len = lps[len-1];
                else lps[i++] = 0;
            }
        }
    }
};


void solve(){
    string n,m;
    cin >>  n >> m;
    debug(n,m);
    KMP k;
    vi ans = k.search(n,m);
    cout << ans.size() << endl;
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
