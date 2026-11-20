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

// set<int> alive IDS 
//
// map< minL, vector root> 
// map < minR , vector robots> 
//
// when we see a new L , R 
//
//
//




void solve(){
    int n,m, sz;
    cin >> n >> m >> sz;
    // 1. location of robots 
    vl robots(n), spikes(m);
    for (auto& z:robots) cin >> z;
    for (auto& z:spikes) cin >> z;
    spikes.pb(-100000000L);
    spikes.pb(1000000000000000);

    string k;
    cin >> k;

    sort(all(robots));
    sort(all(spikes));
    set<int> deleted;
    map<ll, vi> map_left;
    map<ll, vi> map_right;

    auto bs1 = [&](ll x){
        int l = 0, r = spikes.size()-1;
        ll res = 0;
        while(l<=r){
            int m = (l+r)/2;
            if (spikes[m] < x){
                res = spikes[m];
                l = m +1;
            } else r = m -1;
        }
        return res;
        
    };

    auto bs2 = [&](ll x){
        int l = 0, r = spikes.size()-1;
        ll res = 0;
        while(l<=r){
            int m = (l+r)/2;
            if (spikes[m] > x){
                res = spikes[m];
                r = m -1;
            } else l = m + 1;
        }
        return res;

    };

    

    // find max left, and right for each robot 
    for (int i = 0; i < n; i++ ){
        ll  pos = robots[i];
        ll lp = bs1(pos);
        map_left[abs(lp - pos)].pb(i);

        ll rp = bs2(pos);
        map_right[abs(rp - pos)].pb(i);
    }

    debug(map_left);

    // int left = 0, right = 0;
    int dist = 0;
    int mxLeft = 0, mxRight = 0; 


    debug(k);
    for (char c: k){
        if (c =='L'){
            dist--;
        } else dist++;
        if (dist < mxLeft){
            mxLeft = dist;
            // eliminate 
            for (auto& bots: map_left[dist]){
                deleted.insert(bots);
            }
        }
        if (dist > mxRight){
            mxRight = dist;
            for (auto& bots: map_right[dist]){
                deleted.insert(bots);
            }
        }

        cout << n - deleted.size() << " ";
    }
    cout << endl;

    // closes spike for each robot 
    //
    //
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
