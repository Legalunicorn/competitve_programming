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

bool check(vl& A, int mid, ll k, ll a, ll x, ll b, ll y){
    // first mid elements 
    // 1. calculate how many (x+y) 
    // 2. calculate how many x 
    // 3. calculate how many y 
    ll lcm = (a * b)/__gcd(a,b); //LCM of a and b 
    ll gcnt = mid/lcm; // how many we can fint 
    a = (mid/a)-gcnt;
    b = (mid/b)-gcnt;
    // cerr << gcnt << " " << a <<  " : "  << b << endl;
    ll res = 0;
    for (int i=0;i<gcnt;i++){
        ll val = (A[i]/100)*(x+y);
        res += val; 
    }
    if (y>x){
        swap(x,y);
        swap(a,b);
    }
    for (int i=0;i<a;i++){
        ll val = (A[i+gcnt]/100)*x;
        res += val;
    }
    for (int i=0;i<b;i++){
        ll val = (A[i+gcnt+a]/100)*y;
        res += val;
    }
    // cerr << "mid: " << mid << " "<< res << " " << k << endl << endl;
    return res >= k;

};


void solve(){
    ll n; cin >> n;
    vl A(n);
    for (auto& x:A) cin >> x;
    ll x,a,y,b; cin >> x >> a >> y >> b;
    ll k; cin >> k;
    // our check function to handle the k part 
    ll l =1, r = n, res = -1;
    sort(A.rbegin(),A.rend());
    // debugv(A);
    while(l<=r){
        ll mid = (l+r)/2;
        cerr << "? " << l << " " << mid << " " << r << endl;
        if (check(A,mid,k,a,x,b,y)){
            res = mid;
            r = mid - 1;
        
        } else l = mid + 1;
        // check for mid? 
    }
    cout << res << endl;

};


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
