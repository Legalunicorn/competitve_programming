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

// T is only 10
// contains T as a substring
// for each i we need to know where j is found as a substring


// identify all substring of t in s 
// then for L,R check if it contains a full interval


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
    int q;
    string s,t;
    cin >> q >> s >> t;
    KMP kmp;
    int x = q;
    vi pos = kmp.search(s,t);
    debug(s,t);
    debug(pos);
    // try to find "t" in "s"

    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        if (r-l+1<t.size()){
            debug(x-q, "fail",r,l, r-l+1);
            cout << "No" << endl;
            continue;
        }
        // find the first position in POS that is >= L
        auto it = lower_bound(all(pos), l);
        if (it == pos.end()){
            cout << "No" << endl;
            continue;
        }
        int left = *it;
        int right = left+t.size()-1;
        debug(x-q,l,r,left,right);
        if (left >= l && right <= r) cout << "Yes" << endl;
        else cout << "No" << endl;
        // if (right < l || left > r) cout << "No" << endl;
        // else cout << "Yes" << endl;
        

    }

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
