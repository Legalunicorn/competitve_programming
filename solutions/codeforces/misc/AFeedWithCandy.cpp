#include <bits/stdc++.h>
#include <unistd.h>
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
    int n,x;
    cin >> n >> x;
    vpi a,b;
    for (int i =0; i < n ;i++){
        int t,h,m;
        cin >> t >> h >> m;
        if (t == 0) a.pb({h,m});
        else b.pb({h,m});
    }
    int res = 0;
    n = a.size();
    int m = b.size();
    vb seen(n,false), seen2(m,false);
    int t = x;
    int type = 0;
    int count = 0;
    bool found = true;
    while(found){
        found = false;
        if (type == 0){
            int pos = -1;
            int gain = 0;
            // take the highest weight from type 0 that is untaken
            for (int i =0; i < a.size(); i++){
                if (seen[i] || a[i].F > t) continue;
                if (a[i].S > gain){
                    gain = a[i].S;
                    pos = i;
                    found = true;
                }
            }
            if (found){
                seen[pos] = true;
                t += gain;
                count++;
            }
        } else{
            int pos = -1, gain  =0; 
            for (int i=0;i<b.size();i++){
                if (seen2[i] || b[i].F > t) continue;
                if (b[i].S > gain){
                    gain = b[i].S;
                    pos = i;
                    found = true;
                }
            }
            if (found){
                seen2[pos] = true;
                t += gain;
                count++;
            }
        }
        type = 1 - type;
    }
    res = max(res, count );
    seen.assign(n,false), seen2.assign(m,false);
    t = x;
    type = 1;
    count = 0;
    found = true;
    while(found){
        found = false;
        if (type == 0){
            int pos = -1;
            int gain = 0;
            // take the highest weight from type 0 that is untaken
            for (int i =0; i < a.size(); i++){
                if (seen[i] || a[i].F > t) continue;
                if (a[i].S > gain){
                    gain = a[i].S;
                    pos = i;
                    found = true;
                }
            }
            if (found){
                seen[pos] = true;
                t += gain;
                count++;
            }
        } else{
            int pos = -1, gain  =0; 
            for (int i=0;i<b.size();i++){
                if (seen2[i] || b[i].F > t) continue;
                if (b[i].S > gain){
                    gain = b[i].S;
                    pos = i;
                    found = true;
                }
            }
            if (found){
                seen2[pos] = true;
                t += gain;
                count++;
            }
        }
        type = 1 - type;
    }
    res = max(res, count);
    cout << res << endl;

    // start with type 0 
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
