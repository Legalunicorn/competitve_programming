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

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template <class T> using ordered_multiset = tree<T, null_type,
// less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

// is it as simpleas binary search for how many numbers appear?
// but then it stacks doesn it? 
// for example K = 5, then check how many numbers less than equal to 5 appears
// then we just add that to the answer? 
// but then the numbers after 5 will affect as well 
// N = 1 2 3 4 5 6 7 8 9
//
// K = 5 
// this is more so the number of gaps we leave? maybe we can binaey search to find the right gap 
// we might also need to precompute the answer maybe but K, Ai is very large 
// or can we just binary search the value? 
// but its n log n 
//
// example 
// K = 5 
// then we try ans = 10, 
// given ANS = 10, to check if its correct, we need to find APPEAR 
// ANS - APPEAR = K 
//
// n log^2 n can pass? very riskly but meh
//
// i need to change approache this one just very buggy 
//
            

void solve(){
    int n,q;
    cin >> n >> q;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    set<ll> st(all(a));

    auto bs = [&](auto& bs, ll x) -> ll {
        // -> given x, find how many numbers smaller than in appear in a 
        int l = 0, r = n-1;
        ll res = -1;
        while(l<=r){
            int m = (l+r)/2;
            if (a[m] <= x){
                res = m;
                l = m + 1;
            } else r = m -1;
        }
        return res;
    };


    while(q--){
        ll k; cin >> k;
        if (k<a[0]){
            cout << k << endl;
            continue;
        }
        // searching for the number itself
        ll l = 1, r = INF;
        ll ans = -1;

        while(l<=r){
            ll m = l+(r-l)/2;
            ll find = bs(bs, m) +1 ;
            ll evl = m - find;
            // cerr << "check: " << m << "  " << "LTE: " << find << endl;
            if (evl==k){
                if (st.count(m)) {
                    r = m - 1;
                } else{
                    cout << m << endl;
                    break;
                }
            } else if (evl<k){
                l = m +1;
            } else{
                r = m - 1;
            }
        }
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
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
