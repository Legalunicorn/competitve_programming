/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//template/ template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// // 
// template <class T> using ordered_multiset = tree<T, null_type,
// less_e

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vb = vector<bool>;
using vvb = vector<vb>;


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244353;
constexpr double PI = 3.14159265358979323846;


// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));
#define sortU (a) sort(all(a)),(a).erase(unique(all(a)),(a).end())

// === Debug macros , to add a general function and replace this gunk
#define debugv(vec) cerr << #vec << " = ["; for (size_t i = 0; i < (vec).size(); ++i) { cerr << (vec)[i]; if (i + 1 < (vec).size()) cerr << ", "; } cerr << "]\n";
#define debugm(mat) do { cerr << #mat << " = [\n"; for (size_t i = 0; i < (mat).size(); ++i) { cerr << "  ["; for (size_t j = 0; j < (mat)[i].size(); ++j) { cerr << (mat)[i][j]; if (j + 1 < (mat)[i].size()) cerr << ", "; } cerr << "]\n"; } cerr << "]\n"; } while (0)

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
const vector<char> dir_char = {'U','D','L','R'};
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}


ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % m;
        a = a  * a % m;
        b >>=1;
    }
    return res;
}
void solve(){
    // well there has to be exactly one segment for each left to right 
    // we can probably DP or some form of construction 
    // M cells 
    // N segments 
    // there can be duplicates and such 
    // the first segment as to start from 1 obv 
    // we can do some kind of dfs search maybe? like a graph? 
    // like we join all segment with shared edges or something 
    // need to separate the start and end values though 
    // i-th segment probably has a dp right ? 
    // dp[i] => value or some shit 
    // for a full line, we just multiply the probabilty, we can store the denom and numerator separately 
    // then mod inverse at the end 
    // pair<ll,ll> for dp?
    // we need a O(n) graph construction with this approach though 
    // Map<int,vector<int>> start, end 
    // map the time to a list of positions of segments 
    // the from start[0] we do our dfs ? 
    //
    int n,m;
    cin >> n >> m;


    vector<pair<ll,ll>> dp(n, {-1,-1}); 
    map<int,vi> start,end;
    vi left(n),right(n);
    vl top(n),bot(n);
    // vector<tuple<int,int,ll,ll>> a(n);
    for (int i=0;i<n;i++){
        int l,r;
        ll p,q;
        cin >> l >> r >> p >> q;
        // a[i] = {l,r,p,q};
        left[i] = l;
        right[i] = r;
        top[i] = p;
        bot[i] = q;
        start[l].pb(i);
        end[r].pb(i);
    }

    auto dfs = [&](auto& dfs, int u) -> pl {
        if (dp[u].F !=-1) return dp[u];
        if (right[u] == m){
            return {top[u],bot[u]};
        }
        pl res = {1,1};
        // find those that start at your right 
        int st = right[u];
        int cnt = 0;
        for (auto& x: start[st+1]){
            pl evl = dfs(dfs,x);
            if (evl.F == -1) continue; //invalid 
            res.F = res.F * evl.F % MOD;
            res.S = res.S * evl.S % MOD;
            cnt ++;
        }
        if (cnt == 0) res = {-1,-1};
        return dp[u] = res;
    };

    ll found = 0;
    pl res = {1,1};
    for (auto& x: start[1]){
        pl ans = dfs(dfs,x);
        if (ans.F == -1) continue;
        cerr << "ex: " << ans.F << " " << ans.S << endl;
        found++;
        res.S = res.S * ans.S % MOD;
        res.S = ((res.F * ans.S % MOD) + (res.S * ans.F % MOD)) % MOD;
    }
    cerr << res.F << " " << res.S << endl;
    if (found == 0){
        cout << 0 << endl;
        return;
    }
    // res.F and res.S 
    // we want to find mod inverse of res.S MOD 984... 
    // Using fermats little theorem that res.S inverse MOD is res.S ^ (mod-2)
    ll modinv = binpowmod(res.S, MOD-2, MOD);
    ll ans = res.F * modinv % MOD;
    cout << ans << endl;

    // but now we have to add all the fricking things? a/b + c/d = = (ad+cd)/(db)) 

    
};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
