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

class Solution {
public:
    int minCost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        map<int,int> tot; // total ffreq mustall be even 
        map<int,int> m1;
        map<int,int> m2;
        for (auto& z:a){
            tot[z]++;
            m1[z]++;
        }
        for(auto& z:b){
            tot[z]++;
            m2[z]++;
        }
        for (auto& [v,c]: tot){
            if (c % 2 == 1) return -1; // not possible 
        }
        int res = 0;
        set<int> st; // seen
                     // // idk why but i suspect the difference is always even 
                     //
        for (auto& [val,cnt]: m1) {
            int cnt2 = m2[val];
            int d = abs(cnt - cnt2);
            res += (d/2);
            st.insert(val);
        }
        for (auto& [val,cnt]: m2){
            if (st.count(val)) continue;
            int cnt2 = m1[val];
            int d = abs(cnt - cnt2);
            res += (d/2);
        }
        res /= 2;
        // this is purely guess forces
        return res;
        // 
        

        
        

    }
};

void solve(){
    
}


#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif
