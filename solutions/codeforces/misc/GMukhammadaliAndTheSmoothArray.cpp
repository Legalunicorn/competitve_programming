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

/*

    trying not to fit into bands but greedy donest make sense here 
    if we try to anchor at one index, im pretty sure no otoher index can be safe as well 
    we can try dp ? but ah wait i mis read something 
    drop is strickly down 
    means NOT drop can be equal 
    this simplfies it a bit 

*/

void solve(){
    int n;
    cin >> n;
    vl a(n), c(n);
    for (auto & z:a) cin >> z;
    for (auto & z:c) cin >> z;
    vl dp(n);
    dp[0] = c[0];
    for (int i=1; i<n; i++){
        ll evl = 0;
        for (int j=0;j<i;j++){
            if (a[j]<= a[i]){
                // we get to keep a[j];
                evl = max(evl, dp[j]);
            }
        }
        dp[i] = c[i] + evl;
    }
    // debugv(dp);
    ll mx = 0;
    for (int i=0; i<n; i++){
        mx = max(mx, dp[i]);
    }
    ll sum = 0;
    for (auto& x: c) sum += x;
    cout << sum - mx << endl;

    // try 1d dp 
    //
}

// too slow 
// 
// void solve(){
//     int n;
//     cin >> n;
//     vl a(n), c(n);
//     for (auto& z:a) cin >> z;
//     for (auto& z:c) cin >> z; 
//     // can we try dp 
//     vector<map<ll,ll>> dp(n); //hm? 
//     ll mn = MIN(a);
//     ll mx = 0;
//
//     auto go = [&](auto& go, int u, ll msf) -> ll{
//         if (u == n) return 0;
//         if (dp[u].count(msf)) return dp[u][msf];
//         ll res = c[u] + go(go, u+1, msf);
//         if (a[u]>= msf) res = min(res, go(go, u+1, max(msf, a[u])));
//         return dp[u][msf] = res;
//     };
//     for (auto z:c) mx += z;
//     ll ans = go(go,0,mn-1);
//     cout << ans << endl;
//
//
// };
// //



// template<typename T>
// map<T,int> coord_compress(vector<T>& arr){
//     int id = 0;
//     set<T> st(arr.begin(),arr.end());
//     map<T,int> mp;
//     for (const auto& x: arr) mp[x] = id++;
//     return mp;
// };
//
// ll dp[8005][8005];
// void solve(){
//     int n;
//     cin >> n;
//     vl a(n), c(n);
//     for (auto &z:a) cin >> z;
//     for (auto &z:c) cin >> z;
//     for (int i=0;i<=n;i++){
//         for (int j=0;j<=n;j++) dp[i][j] = -1LL;
//     }
//     // memset(dp,-1LL,sizeof(dp)); // odd set by 
//     map<ll,int> mp; 
//     int id = 0;
//     set<ll> st(all(a));
//     for (auto& x: st) mp[x] = id++;
//     vl conv(n);
//     for (int i=0;i<n;i++) conv[i] = (ll)mp[a[i]];
//     // can try to cheese this 
//     auto go = [&](auto& go, int u, ll msf) -> ll{
//         if (u==n) return 0;
//         if (dp[u][msf] != -1) return dp[u][msf];
//         ll res = c[u] + go(go,u+1, msf);
//         if (conv[u]>=msf) res = min(res, go(go,u+1, max(conv[u],msf)));
//         return dp[u][msf] = res;
//     };
//
//     ll evl = go(go,0,0);
//     cout << evl << endl;
// }
//
//
// void solve(){
//     int n;
//     vl a(n), c(n);
//     for (auto& z:a) cin >> z;
//     for (auto& z:c) cin >> z;
//     // maybe instead f  
// };


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
