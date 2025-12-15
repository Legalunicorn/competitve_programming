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



bool check(vl& a, ll m, ll k){
    int n = a.size();
    for (int i=0;i<n-1;i++){
        ll left = k;
        ll v = m;
        bool valid = true;
        for (int j=i;j<n;j++){
            if (j==n-1 && a[j]<v) {
                valid = false;
                break;
            }
            if (a[j]>=v) return true;
            ll d = v-a[j];
            if (left<d){
                valid = false;
                break;
            }
            left -= d;
            if (left < 0) {
                valid = false;
                break;
            }
            v--;
        }
        if (valid) return true;
    }
    return false;
}
void solve(){
    int n;
    ll k;
    cin >> n >> k;
    vl a(n); 
    for (auto& z:a) cin >> z; 
    ll l = MAX(a);
    ll r = INF;
    ll res = l;
    while(l<=r){
        ll m = l+(r-l)/2;
        bool ans = check(a,m,k);
        if (ans){
            res = m;
            l = m +1;
        } else r = m - 1;
        // n is brute forceable 
        // do a check
    }
    cout << res << endl;
};
/*

we need to be strategic where we imlement the greedy? 
if we have a certain value 

the pattern is 

n, n-1,  n-2,  n -3 , ... 

unless there is an element greater than what its assigned 
then that takes over 
how do we implement this? is there a optimal starting point ? 
1. one of the squares HAS to be the said max 
2. can we simulate for each square then? 
3. we kind of need to reverse enginner this 

at no point can the value be greaterh by two 

holy fuck n is only 1000 
we can just bruteforce 

*/


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
