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
    long long countSubarrays(vector<int>& nums, long long k) {
        ll res = 0; 
        int n = nums.size();
        debug(nums,k);

        // sliding window? 
        map<ll,int> freq;
        set<ll> st;
        int r = 0;

        auto calc = [&](int l, int r, ll x) -> ll{
            // check if inserting this will generate larger than k 
            if (st.size() == 0) return 0LL;
            ll low = min(*st.begin(), x);
            ll high = max(*st.rbegin(), x);
            ll ans = (high - low)  * (r-l +1);
            debug(high,low,l,r);
            debug(ans);
            return ans;
        };

        auto get = [&]()->ll{
            ll low = *st.begin();
            ll high = *st.end();
            return high - low;
        };
        

        for (int l = 0; l < n; l++){
            while(r < n && calc(l,r,nums[r])<=k  ){
                freq[nums[r]]++;
                st.insert(nums[r]);
                debug("insertion: ", nums[r]);
                
                r++;
            }
            ll check = get()*(r-l);
            debug(l,r,check);
            if (st.empty() || check<=k) res += (r - l);
            // remove left 
            freq[nums[l]]--;
            if (freq[nums[l]]==0) st.erase(nums[l]);
        }
        return res;


        return res;
    }
};


void solve(){
    Solution sol;
    int n;
    cin >> n;
    ll k; cin >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    cout << sol.countSubarrays(a, k) << endl;
};


#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << "calc" << endl;
    return 0;
}
#endif
