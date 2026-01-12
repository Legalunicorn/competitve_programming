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
    // this look like dp? 
    // like we can break it into subsequences 
    // and we solve for a[i] as the start of some sequence 
    int n;
    cin >> n;
    vl a(n),b(n), c(n);;
    for (auto& z:a) cin >> z;
    b = a;
    c = a; 
    ll  m = 1;
    ll res = MAX(a);
    map<ll, int> mp;
    for (int i = n-1; i>=0; i--){
        b[i] += m;
        m++;
        if (mp.count(b[i])){
            int p = mp[b[i]];
            c[i] += c[p];
            res = max(res,c[i]);
        }
        mp[b[i]] = i;
    }
    cout << res << endl;

    debug(a,b);

    // consider the case 8  9 x 11 
    // if 8 -> 11 and 8 -> 9 
    // sufficently to know that 9 -> 11 
    // hence we only care about 8 -> 9 
    // we just need find the FIRST guy that pairs, 
    // but how ? can we binary search it ? its not continuous so on 
    // can we search backwards? instead of looking for the next guy in front 
    // we look at the closest guy behind 
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
