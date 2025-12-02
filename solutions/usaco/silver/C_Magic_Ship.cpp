/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */
#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//template 
// distinct - pbds 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// 
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

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


//x,y -> final positive
// windx, windy -> one loop value
bool check(string s, ll x, ll y, ll windx, ll windy, ll m){
    ll n = (ll)s.size();
    ll rev = m/n;
    ll wx = windx*rev;
    ll wy = windy*rev;
    ll mod = m%n;
    for (int i =0;i<mod;i++){
        char c = s[i];
        if (c=='U') wy++;
        else if (c=='D') wy--;
        else  if (c=='L') wx--;
        else wx++;        
    }

    ll moves = abs(x-wx) + abs(y-wy);

    return moves<=m;


}

void solve(){
    ll x1, y1, x2, y2;
    cin  >> x1 >> y1 >> x2 >> y2;
    ll x = x2-x1;
    ll y = y2-y1;
    int n; 
    cin >> n;
    string s;
    cin >> s;
    ll wx =0, wy = 0;
    for (char c:s){
        if (c=='U') wy++;
        else if (c=='D') wy--;
        else  if (c=='L') wx--;
        else wx++;
    }

    ll l = 0, r = INF;
    ll res = r;
    while(l<=r){
        ll m = l+(r-l)/2;
        bool v = check(s,x,y,wx,wy,m);
        if (v){
            res = m;
            r = m -1;
        } else l = m +1;
    }
    if (res==INF) res = -1;
    cout << res << endl;
};

/*
    - get delta x, delta y
    - we have 10e9 worth of distance o covert 
    - given a time limmit ,T -> check if we can cover the distance
    - there is wind, ship direciton and transposition of both 
    - we have to do a count basis? 
    - transposition in good vs bad direction
        - bad? just negate? if we use enegy to go to the other dir, we still need to reverse what we dod 
        - good? max bonus of 2 distance no cost differnec e

    you can also stay put 

    dx = 5
    dy = 5 

    lets say we check for time t = 10 
    1. get the number of iteraions from wind (len w)
    2. t/w
    3. if dx>0, look for R
    4. if dy>0 look for  U
    // basicically get the count. 
    
    what is a transposition? 
    say we want togo R and U 
    if we get either R or U, we can minus from both 
    if we need 5 R and 10 U 
    if we have 8 of each 
    using 5 of any can reduce to 0, 5 
    then the access needs to be solely from the larger value
    meaning it makes sense to use the smaller value for transpoitions


    1. get the number of counts 
    2. get the extra from the remaining

    
*/



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