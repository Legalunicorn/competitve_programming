/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>
#include <ctime>

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
constexpr ll MOD = 1e9+7;
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

// the one is tricky i read the solution but i gues  isohuld implement my self too 
// 1. we dereived that dist(i,j) = dist(x,i) XOR dist(x,j) 
// 2. we want to find the dist(i,j) for all all i < j 
// it just so happens that xor only countes when the parit yis different 
// and also addition works the same with bits, so we can split our addition 
// in terms of bits 
// for each bit position, we just need to know how many ones will be present which is 
// count of 0 times count of 1 


void solve(){
    int n;
    cin >> n;
    vector<vector<pair<int,ll>>> g(n);
    for (int i=0;i<n-1;i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    vl dist(n);
    auto dfs = [&](auto& dfs, int u, int p, ll xsum) -> void{
        dist[u] = xsum;
        for (const auto& [v,w]: g[u]){
            if (v==p) continue;
            dfs(dfs,v,u, xsum ^ w);
        }
    };
    // what is dist of "i" > it just 0, since anything xor 0 is itself so its fine 
    dfs(dfs,0,-1,0LL);
    ll res =0; 
    int bits = 62;
    vi count(bits,0), c2(bits);
    for (int i = 0; i < n; i++){
        for (int k =0; k<bits; k++){
            if ((dist[i] >> k ) & 1) count[k]++;
            else c2[k]++;
        }
    }
    // debugv(dist);
    for (int k = 0; k< bits; k++){
        ll a = (ll) count[k];
        ll b = (ll) c2[k];
        ll ab = a * b % MOD;
        res += (1LL<<k) % MOD * ab % MOD;
        // res += (1ll<<k)%MOD*a%MOD*b%MOD;
        res %= MOD;
        // ll x = (ll) count[k], y = (ll)(c2[k]);
        // ll xy = x * y % MOD; 
        // ll mul = (1LL << k  % MOD) * xy % MOD;
        // res += mul;
        // res %= MOD;
        // res = (res + (x * y % MOD)) % MOD;
    }
    cout << res << endl;
    // ll gans = 0;
    // debugv(count);
    // debugv(c2);
    // for(int i=0; i<60; i++){
    //     vector<int> cnt(2);
    //     for(int j=0; j<n; j++) cnt[dist[j]>>i&1]++;
    //     ans += (1ll<<i)%MOD*cnt[0]%MOD*cnt[1];
    //     ans %= MOD;
    //     cerr << "x: "  << cnt[0] << " " << cnt[1] << endl;
    //     cerr << "y: " << c2[i] << ":" << count[i] << endl << endl;
    // }
    // cout << ans << endl;
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
